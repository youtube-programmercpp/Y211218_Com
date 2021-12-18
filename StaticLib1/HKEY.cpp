// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#include "pch.h"
#include "HKEY.h"

StaticLib1::HKEY::HKEY() noexcept
	: LSTATUS {ERROR_FILE_NOT_FOUND}
	, hkResult{                    }
{
}
StaticLib1::HKEY::HKEY(HKEY&& r) noexcept
	: LSTATUS {r         }
	, hkResult{r.hkResult}
{
	static_cast<LSTATUS&>(r) = ERROR_FILE_NOT_FOUND;
	r.hkResult               = {                  };
}
auto StaticLib1::HKEY::operator=(HKEY&& r) noexcept->HKEY&
{
	std::swap(static_cast<LSTATUS&>(*this), static_cast<LSTATUS&>(r));
	std::swap(hkResult                    , r.hkResult              );
	return *this;
}
StaticLib1::HKEY::HKEY(::LSTATUS return_value, ::HKEY hkResult) noexcept
	: LSTATUS (return_value)
	, hkResult(hkResult    )
{
}
StaticLib1::HKEY::~HKEY() noexcept
{
	if (*this)
		(void)RegCloseKey(hkResult);
}
StaticLib1::HKEY::operator ::HKEY() const noexcept
{
	assert(*this);
	return hkResult;
}
