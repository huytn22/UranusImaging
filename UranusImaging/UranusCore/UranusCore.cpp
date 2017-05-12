// UranusCore.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"

#if defined(_WINDOWS) || defined(WIN32)
#include <Windows.h>
#endif // _WINDOWS
#include "../Utility/ConstDef.h"
#include "PluginMan.h"

#define VERSION _T("0.1.0.0")

int _tmain(int argc, _TCHAR* argv[])
{
	CPluginMan PlgMan;

	PluginOpt PlgOption;

	PlgOption.tVersion = VERSION;
	PlgOption.tValidateCode = VALIDATE_CODE;

	PlgMan.LoadPlugin(_T("C:\\huy\\WorkingDir\\Uranus\\git_src\\UranusImaging\\UranusImaging\\x64\\Debug"), PlgOption);


	return 0;
}

