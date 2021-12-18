// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "pch.h"
#include "RegOpenKeyA.h"

auto StaticLib1::RegOpenKeyA
( _In_     ::HKEY hKey    
, _In_opt_ LPCSTR lpSubKey
) noexcept->HKEY
{
	::HKEY hkResult;
	const auto return_value = /*LSTATUS*/::RegOpenKeyA
	( /*_In_     HKEY   hKey     */hKey
	, /*_In_opt_ LPCSTR lpSubKey */lpSubKey
	, /*_Out_    PHKEY  phkResult*/&hkResult
	);
	return { return_value, hkResult };
}
