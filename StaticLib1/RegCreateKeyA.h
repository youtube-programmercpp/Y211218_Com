// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#pragma once
#include "HKEY.h"
namespace StaticLib1 {
	auto RegCreateKeyA
	( _In_     ::HKEY hKey    
	, _In_opt_ LPCSTR lpSubKey
	) noexcept->HKEY;
}
