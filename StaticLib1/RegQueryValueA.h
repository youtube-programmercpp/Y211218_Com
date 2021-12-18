// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
namespace StaticLib1 {
	template<LONG size>class RegQueryValueA : public LSTATUS {
		LONG cbData      ;
		char lpData[size];
	public:
		RegQueryValueA
		( _In_     ::HKEY hKey    
		, _In_opt_ LPCSTR lpSubKey
		) noexcept
			: LSTATUS({})
			, cbData(size)
		{
			static_cast<LSTATUS&>(*this) = /*LSTATUS*/::RegQueryValueA
			( /*_In_                                                                        HKEY   hKey    */hKey    
			, /*_In_opt_                                                                    LPCSTR lpSubKey*/lpSubKey
			, /*_Out_writes_bytes_to_opt_(*lpcbData, *lpcbData) __out_data_source(REGISTRY) LPSTR  lpData  */lpData  
			, /*_Inout_opt_                                                                 PLONG  lpcbData*/&cbData 
			);
		}
		operator const char* () const noexcept
		{
			assert(*this);
			return lpData;
		}
	};
}
