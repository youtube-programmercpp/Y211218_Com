// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "pch.h"
#include "CLSIDs.h"
#include "../StaticLib2/ClassFactory.h"

HRESULT CreateInstance_SimpleObject(IUnknown* pUnkOuter, REFIID riid, void** ppvObject) noexcept;
class __declspec(uuid(SimpleObject_TextA_CLSID)) SimpleObject;

_Check_return_
STDAPI DllGetClassObject(_In_ REFCLSID rclsid, _In_ REFIID riid, _Outptr_ LPVOID* ppv)
{
	if (rclsid == __uuidof(SimpleObject)) {
		try {
			return IClassFactoryPtr{ new StaticLib2::ClassFactory(CreateInstance_SimpleObject), false }.QueryInterface(riid, ppv);
		}
		catch (const std::exception& e) {
			OutputDebugStringA(e.what());
			OutputDebugStringA("\n");
			return E_OUTOFMEMORY;
		}
	}
	else
		return CLASS_E_CLASSNOTAVAILABLE;
}
