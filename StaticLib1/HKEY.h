// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
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
