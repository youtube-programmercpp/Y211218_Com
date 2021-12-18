// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "pch.h"

#include "../StaticLib2/ClassFactory.h"

__control_entrypoint(DllExport)
STDAPI DllCanUnloadNow(void)
{
	return StaticLib2::ClassFactory::CanUnloadNow() ? S_OK : S_FALSE;
}
