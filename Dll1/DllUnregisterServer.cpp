// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#include "pch.h"
#include "CLSIDs.h"
#include "ProgIDs.h"
#include "../StaticLib1/RegOpenKeyA.h"
#include "../StaticLib1/RegQueryValueA.h"

static HRESULT UnregisterProgID()
{
	if (auto hKey = StaticLib1::RegOpenKeyA(HKEY_CLASSES_ROOT, SimpleObject_TextA_ProgID)) {
		const auto pre_registered_clsid = StaticLib1::RegQueryValueA<sizeof SimpleObject_TextA_CLSID>(hKey, "CLSID");
		switch (pre_registered_clsid.lStatus) {
		case ERROR_SUCCESS:
			if (lstrcmpiA(pre_registered_clsid, SimpleObject_TextA_CLSID) == 0) {
				//���N���X���o�^�ς݂ł������̂ŃN���XID���܂߂�ProgID���폜
				hKey = {};
				return StaticLib1::LSTATUS{ RegDeleteTreeA(HKEY_CLASSES_ROOT, SimpleObject_TextA_ProgID) }.hr;
			}
			else {
				//�قȂ�N���XID�Ƃ��� ProgID ���o�^����Ă������߃G���[
				return SELFREG_E_CLASS;
			}
		case ERROR_FILE_NOT_FOUND:
			//�N���XID�͓o�^����Ă��Ȃ�
			//ProgID���폜
			hKey = {};
			return StaticLib1::LSTATUS{ RegDeleteTreeA(HKEY_CLASSES_ROOT, SimpleObject_TextA_ProgID) }.hr;
		default:
			return pre_registered_clsid.hr;//���W�X�g������̓ǂݏo���Ɏ��s
		}
	}
	else if (hKey.lStatus == ERROR_FILE_NOT_FOUND)
		return S_OK;//ProgID���o�^
	else
		return hKey.hr;//���W�X�g���L�[�̃I�[�v���Ɏ��s
}
STDAPI DllUnregisterServer(void)
{
	auto hr = UnregisterProgID();
	if (SUCCEEDED(hr))
		hr = StaticLib1::LSTATUS{ RegDeleteTreeA(HKEY_CLASSES_ROOT, "CLSID" "\\" SimpleObject_TextA_CLSID) }.hr;
	return hr;
}
