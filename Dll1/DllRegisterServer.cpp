// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#include "pch.h"
#include "CLSIDs.h"
#include "ProgIDs.h"
#include "../StaticLib1/GetModuleFileNameW.h"
#include "../StaticLib1/RegCreateKeyA.h"
#include "../StaticLib1/RegQueryValueA.h"
#include "../StaticLib1/RegSetValueW.h"

extern "C" extern std::remove_pointer_t<HMODULE> __ImageBase;

static HRESULT RegisterCLSID()
{
	if (const auto pathname = StaticLib1::GetModuleFileNameW<MAX_PATH>(&__ImageBase)) {
		if (const auto hKey = StaticLib1::RegCreateKeyA(HKEY_CLASSES_ROOT, "CLSID" "\\" SimpleObject_TextA_CLSID)) {
			if (const auto result = StaticLib1::RegSetValueW(hKey, L"InProcServer32", REG_SZ, &pathname))
				return S_OK;
			else
				return result.hr;
		}
		else
			return hKey.hr;
	}
	else
		return pathname.hr;
}
static HRESULT RegisterProgID()
{
	if (const auto hKey = StaticLib1::RegCreateKeyA(HKEY_CLASSES_ROOT, SimpleObject_TextA_ProgID)) {
		const auto pre_registered_clsid = StaticLib1::RegQueryValueA<sizeof SimpleObject_TextA_CLSID>(hKey, "CLSID");
		switch (pre_registered_clsid.lStatus) {
		case ERROR_SUCCESS:
			return lstrcmpiA(pre_registered_clsid, SimpleObject_TextA_CLSID) == 0
				? S_OK            //���ɓo�^�ς�
				: SELFREG_E_CLASS //�قȂ�N���XID�Ƃ��� ProgID ���o�^����Ă������߃G���[
				;
		case ERROR_FILE_NOT_FOUND:
			return StaticLib1::LSTATUS{ ::RegSetValueA(hKey, "CLSID", REG_SZ, SimpleObject_TextA_CLSID, sizeof SimpleObject_TextA_CLSID) }.hr;
		default:
			return pre_registered_clsid.hr;//���W�X�g������̓ǂݏo���Ɏ��s
		}
	}
	else
		return hKey.hr;//���W�X�g���L�[�̃I�[�v���Ɏ��s
}
STDAPI DllRegisterServer(void)
{
	auto hr = RegisterCLSID();
	if (SUCCEEDED(hr)) {
		hr = RegisterProgID();
		if (SUCCEEDED(hr))
			return S_OK;
	}
	return hr;
}
