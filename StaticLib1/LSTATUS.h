// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
namespace StaticLib1 {
	class LSTATUS {
		::LSTATUS return_value;
	public:
		LSTATUS(::LSTATUS return_value) noexcept;
		virtual explicit operator bool() const noexcept;
		::HRESULT get_hr     () const noexcept;
		::LSTATUS get_lStatus() const noexcept;
		__declspec(property(get = get_hr     )) ::HRESULT hr     ;
		__declspec(property(get = get_lStatus)) ::LSTATUS lStatus;
	};
}
