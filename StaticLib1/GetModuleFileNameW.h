// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
#include "LSTATUS.h"
namespace StaticLib1 {
	template<DWORD nSize>class GetModuleFileNameW : public LSTATUS {
		DWORD   return_value       ;
		wchar_t lpFilename  [nSize];
	public:
		GetModuleFileNameW(_In_opt_ HMODULE hModule) noexcept
			: LSTATUS({})
			, return_value
				{ /*_Success_(return != 0) _Ret_range_(1, nSize)                     DWORD   */::GetModuleFileNameW
				( /*_In_opt_                                                         HMODULE */hModule   
				, /*_Out_writes_to_(nSize, ((return < nSize) ? (return +1) : nSize)) LPWSTR  */lpFilename
				, /*_In_                                                             DWORD   */nSize     
				)}
		{
			static_cast<LSTATUS&>(*this) = LSTATUS{static_cast<::LSTATUS>(::GetLastError())};
		}
		virtual explicit operator bool() const noexcept override
		{
			switch (return_value) {
			case 0    :
			case nSize:
				return false;
			default   :
				return true ;
			}
		}
		DWORD get_cbData() const noexcept
		{
			assert(*this);
			return return_value * sizeof * lpFilename;
		}
		__declspec(property(get = get_cbData)) DWORD cbData;
		operator const wchar_t* () const noexcept
		{
			assert(*this);
			return lpFilename;
		}
	};
}
