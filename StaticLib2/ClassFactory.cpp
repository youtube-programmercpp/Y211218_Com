// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "pch.h"
#include "ClassFactory.h"

ULONG StaticLib2::ClassFactory::lockcnt;

StaticLib2::ClassFactory::ClassFactory(HRESULT(*pfnCreateInstance)(IUnknown* pUnkOuter, REFIID riid, void** ppvObject) noexcept) noexcept
	: pfnCreateInstance(pfnCreateInstance)
	, refcnt(1UL)
{
	InterlockedIncrement(&lockcnt);
}
StaticLib2::ClassFactory::~ClassFactory() noexcept
{
	InterlockedDecrement(&lockcnt);
}
bool StaticLib2::ClassFactory::CanUnloadNow() noexcept
{
	return lockcnt == 0;
}
// IClassFactory を介して継承されました
HRESULT STDMETHODCALLTYPE StaticLib2::ClassFactory::QueryInterface(REFIID riid, void** ppvObject) noexcept
{
	if (riid == IID_IClassFactory || riid == __uuidof(IUnknown)) {
		(reinterpret_cast<IClassFactory*&>(*ppvObject) = this)->AddRef();
		return S_OK;
	}
	else
		return E_NOINTERFACE;
}
ULONG STDMETHODCALLTYPE StaticLib2::ClassFactory::AddRef(void) noexcept
{
	return InterlockedIncrement(&refcnt);
}
ULONG STDMETHODCALLTYPE StaticLib2::ClassFactory::Release(void) noexcept
{
	if (const auto n = InterlockedDecrement(&refcnt))
		return n;
	else {
		delete this;
		return 0UL;
	}
}
HRESULT STDMETHODCALLTYPE StaticLib2::ClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppvObject) noexcept
{
	return (*pfnCreateInstance)(pUnkOuter, riid, ppvObject);
}
HRESULT STDMETHODCALLTYPE StaticLib2::ClassFactory::LockServer(BOOL fLock) noexcept
{
	if (fLock)
		InterlockedIncrement(&lockcnt);
	else
		InterlockedDecrement(&lockcnt);
	return S_OK;
}
