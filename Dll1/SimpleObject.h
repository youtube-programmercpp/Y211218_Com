// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
class SimpleObject : public IDispatch{
	friend HRESULT CreateInstance_SimpleObject(IUnknown* pUnkOuter, REFIID riid, void** ppvObject) noexcept;
	enum class Method
	{ Test1
	, Test2
	};
	ULONG refcnt;
	SimpleObject() noexcept;
	~SimpleObject() noexcept;
	HRESULT Test1(WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr) noexcept;
	HRESULT Test2(WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr) noexcept;
	static DISPID MemberId(LPCOLESTR pszMemberName) noexcept;
	// *** IUnknown ***
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject) noexcept override;
	virtual ULONG   STDMETHODCALLTYPE AddRef        (void                         ) noexcept override;
	virtual ULONG   STDMETHODCALLTYPE Release       (void                         ) noexcept override;
	// *** IDispatch ***
	virtual HRESULT STDMETHODCALLTYPE GetTypeInfoCount(UINT* pctinfo) noexcept override;
	virtual HRESULT STDMETHODCALLTYPE GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo) noexcept override;
	virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames
	( REFIID riid
	, LPOLESTR* rgszNames
	, UINT      cNames   
	, LCID      lcid     
	, DISPID  * rgDispId 
	) noexcept override;
	virtual HRESULT STDMETHODCALLTYPE Invoke
	( DISPID        dispIdMember
	, REFIID        riid        
	, LCID          lcid        
	, WORD          wFlags      
	, DISPPARAMS  * pDispParams 
	, VARIANT     * pVarResult  
	, EXCEPINFO   * pExcepInfo  
	, UINT        * puArgErr    
	) noexcept override;
};
