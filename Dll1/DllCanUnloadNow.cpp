// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#include "pch.h"

#include "../StaticLib2/ClassFactory.h"

__control_entrypoint(DllExport)
STDAPI DllCanUnloadNow(void)
{
	return StaticLib2::ClassFactory::CanUnloadNow() ? S_OK : S_FALSE;
}
