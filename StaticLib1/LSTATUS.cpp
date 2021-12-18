// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#include "pch.h"
#include "LSTATUS.h"

StaticLib1::LSTATUS::LSTATUS(::LSTATUS return_value) noexcept
	: return_value(return_value)
{
}
StaticLib1::LSTATUS::operator bool() const noexcept
{
	return return_value == ERROR_SUCCESS;
}
HRESULT StaticLib1::LSTATUS::get_hr() const noexcept
{
	if (*this)
		return S_OK;
	else
		return HRESULT_FROM_WIN32(return_value);
}

::LSTATUS StaticLib1::LSTATUS::get_lStatus() const noexcept
{
	return return_value;
}
