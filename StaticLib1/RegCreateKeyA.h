// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
#include "HKEY.h"
namespace StaticLib1 {
	auto RegCreateKeyA
	( _In_     ::HKEY hKey    
	, _In_opt_ LPCSTR lpSubKey
	) noexcept->HKEY;
}
