// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#pragma once
namespace StaticLib1 {
	template<class T>auto RegSetValueW
	( _In_     ::HKEY   hKey    
	, _In_opt_ LPCWSTR  lpSubKey
	, _In_     DWORD    dwType  
	, _In_     const T* lpData  
	) noexcept->LSTATUS
	{
		return
		{ /*LSTATUS*/::RegSetValueW
		( /*_In_                         HKEY    */hKey    
		, /*_In_opt_                     LPCWSTR */lpSubKey
		, /*_In_                         DWORD   */dwType  
		, /*_In_reads_bytes_opt_(cbData) LPCWSTR */lpData->operator LPCWSTR()
		, /*_In_                         DWORD   */lpData->cbData 
		)};
	}
}
