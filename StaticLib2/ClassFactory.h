// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
namespace StaticLib2 {
	class ClassFactory : public IClassFactory {
		static ULONG lockcnt;
		ULONG refcnt;
		HRESULT(*pfnCreateInstance)(IUnknown* pUnkOuter, REFIID riid, void** ppvObject) noexcept;
		~ClassFactory() noexcept;
		// IClassFactory を介して継承されました
		virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject) noexcept override;
		virtual ULONG   STDMETHODCALLTYPE AddRef (void) noexcept override;
		virtual ULONG   STDMETHODCALLTYPE Release(void) noexcept override;
		virtual HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppvObject) noexcept override;
		virtual HRESULT STDMETHODCALLTYPE LockServer(BOOL fLock) noexcept override;
	public:
		ClassFactory(HRESULT (*pfnCreateInstance)(IUnknown* pUnkOuter, REFIID riid, void** ppvObject) noexcept) noexcept;
		static bool CanUnloadNow() noexcept;
	};
}
