// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
#include "LSTATUS.h"
namespace StaticLib1 {
	class HKEY : public LSTATUS {
		::HKEY    hkResult    ;
	public:
		HKEY() noexcept;
		~HKEY() noexcept;
		HKEY(HKEY&& r) noexcept;
		auto operator=(HKEY&& r) noexcept->HKEY&;
		HKEY(::LSTATUS return_value, ::HKEY hkResult) noexcept;
		operator ::HKEY() const noexcept;
	};
}
