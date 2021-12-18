// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
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
