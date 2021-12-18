// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "pch.h"
#include "SimpleObject.h"

HRESULT CreateInstance_SimpleObject(IUnknown* pUnkOuter, REFIID riid, void** ppvObject) noexcept
{
	if (pUnkOuter)
		return CLASS_E_NOAGGREGATION;
	else {
		try {
			return IDispatchPtr{ new SimpleObject , false }.QueryInterface(riid, ppvObject);
		}
		catch (const std::exception& e) {
			OutputDebugStringA(e.what());
			OutputDebugStringA("\n");
			return E_OUTOFMEMORY;
		}
	}
}

SimpleObject::SimpleObject() noexcept
	: refcnt(1UL)
{
}
SimpleObject::~SimpleObject() noexcept
{
}
HRESULT SimpleObject::Test1(WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr) noexcept
{
	if (pDispParams->cNamedArgs)
		return DISP_E_NONAMEDARGS;
	else if (pDispParams->cArgs == 1) {
		if (pVarResult) {
			VariantInit(pVarResult);
			const HRESULT hr = VariantChangeType(pVarResult, pDispParams->rgvarg, 0, VT_INT);
			if (SUCCEEDED(hr)) {
				++pVarResult->intVal;
				return S_OK;
			}
			else
				return hr;
		}
		else
			return S_OK;
	}
	else
		return DISP_E_BADPARAMCOUNT;
}
HRESULT SimpleObject::Test2(WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr) noexcept
{
	if (pDispParams->cNamedArgs)
		return DISP_E_NONAMEDARGS;
	else if (pDispParams->cArgs == 1) {
		if (pVarResult) {
			VariantInit(pVarResult);
			HRESULT hr = VariantChangeType(pVarResult, pDispParams->rgvarg, 0, VT_BSTR);
			if (SUCCEEDED(hr)) {
				const auto cchSrc = SysStringLen(pVarResult->bstrVal);
				/*int*/LCMapStringW
				( /*_In_                                       LCID     Locale    */GetThreadLocale()
				, /*_In_                                       DWORD    dwMapFlags*/LCMAP_UPPERCASE
				, /*_In_reads_(cchSrc)                         LPCWSTR  lpSrcStr  */pVarResult->bstrVal
				, /*_In_                                       int      cchSrc    */cchSrc
				, /*_Out_writes_opt_(_Inexpressible_(cchDest)) LPWSTR   lpDestStr */pVarResult->bstrVal
				, /*_In_                                       int      cchDest   */cchSrc
				);
				return S_OK;
			}
			else
				return hr;
		}
		else
			return S_OK;
	}
	else
		return DISP_E_BADPARAMCOUNT;
}
DISPID SimpleObject::MemberId(LPCOLESTR pszMemberName) noexcept
{
	if (lstrcmpiW(pszMemberName, L"Test1") == 0) return static_cast<DISPID>(Method::Test1);
	if (lstrcmpiW(pszMemberName, L"Test2") == 0) return static_cast<DISPID>(Method::Test2);
	return DISPID_UNKNOWN;
}

HRESULT STDMETHODCALLTYPE SimpleObject::QueryInterface(REFIID riid, void** ppvObject) noexcept
{
	if (riid == __uuidof(IDispatch) || riid == __uuidof(IUnknown)) {
		(reinterpret_cast<IDispatch*&>(*ppvObject) = this)->AddRef();
		return S_OK;
	}
	else
		return E_NOINTERFACE;
}

ULONG STDMETHODCALLTYPE SimpleObject::AddRef(void) noexcept
{
	return ++refcnt;
}

ULONG STDMETHODCALLTYPE SimpleObject::Release(void) noexcept
{
	if (const auto n = --refcnt)
		return n;
	else {
		delete this;
		return 0;
	}
}

HRESULT STDMETHODCALLTYPE SimpleObject::GetTypeInfoCount(UINT* pctinfo) noexcept
{
	*pctinfo = 0;
	return S_OK;
}

HRESULT STDMETHODCALLTYPE SimpleObject::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo) noexcept
{
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SimpleObject::GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId) noexcept
{
	if (riid == IID_NULL) {
		switch (cNames) {
		case 0:
			return E_INVALIDARG;
		case 1:
			return (*rgDispId = MemberId(*rgszNames)) == DISPID_UNKNOWN ? DISP_E_UNKNOWNNAME : S_OK;
		default:
			*rgDispId++ = MemberId(*rgszNames);
			while (--cNames)
				*rgDispId++ = DISPID_UNKNOWN;
			return DISP_E_UNKNOWNNAME;
		}
	}
	else
		return E_INVALIDARG;
}

HRESULT STDMETHODCALLTYPE SimpleObject::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr) noexcept
{
	if (riid == IID_NULL) {
		switch (dispIdMember) {
		case static_cast<DISPID>(Method::Test1): return Test1(wFlags, pDispParams, pVarResult, pExcepInfo, puArgErr);
		case static_cast<DISPID>(Method::Test2): return Test2(wFlags, pDispParams, pVarResult, pExcepInfo, puArgErr);
		default:
			return DISP_E_MEMBERNOTFOUND;
		}
	}
	else
		return DISP_E_UNKNOWNINTERFACE;
}
