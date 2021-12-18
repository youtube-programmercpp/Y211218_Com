// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
namespace StaticLib1 {
	template<class T>auto RegSetValueA
	( _In_     ::HKEY   hKey    
	, _In_opt_ LPCSTR   lpSubKey
	, _In_     DWORD    dwType  
	, _In_     const T& lpData
	) noexcept->LSTATUS
	{
		return
		{ /*LSTATUS*/::RegSetValueA
		( /*_In_                         HKEY    */hKey    
		, /*_In_opt_                     LPCSTR  */lpSubKey
		, /*_In_                         DWORD   */dwType  
		, /*_In_reads_bytes_opt_(cbData) LPCSTR  */static_cast<LPCSTR>(lpData)
		, /*_In_                         DWORD   */lpData.cbData 
		)};
	}
}
