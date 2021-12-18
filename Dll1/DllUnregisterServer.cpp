// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
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
				//当クラスが登録済みであったのでクラスIDを含めてProgIDを削除
				hKey = {};
				return StaticLib1::LSTATUS{ RegDeleteTreeA(HKEY_CLASSES_ROOT, SimpleObject_TextA_ProgID) }.hr;
			}
			else {
				//異なるクラスIDとして ProgID が登録されていたためエラー
				return SELFREG_E_CLASS;
			}
		case ERROR_FILE_NOT_FOUND:
			//クラスIDは登録されていない
			//ProgIDを削除
			hKey = {};
			return StaticLib1::LSTATUS{ RegDeleteTreeA(HKEY_CLASSES_ROOT, SimpleObject_TextA_ProgID) }.hr;
		default:
			return pre_registered_clsid.hr;//レジストリからの読み出しに失敗
		}
	}
	else if (hKey.lStatus == ERROR_FILE_NOT_FOUND)
		return S_OK;//ProgID未登録
	else
		return hKey.hr;//レジストリキーのオープンに失敗
}
STDAPI DllUnregisterServer(void)
{
	auto hr = UnregisterProgID();
	if (SUCCEEDED(hr))
		hr = StaticLib1::LSTATUS{ RegDeleteTreeA(HKEY_CLASSES_ROOT, "CLSID" "\\" SimpleObject_TextA_CLSID) }.hr;
	return hr;
}
