// TestPlugin.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "..\Utility\DllDef.h"
#include "..\PluginUtil\PluginItf.h"
#include "..\Utility\ConstDef.h"

#define VERSION _T("0.1.0.0")

//#define COMPATIBLE_CODE _T("0.1.0.0")

DLL_API
URA_GET_VERSION
{
	tstring version = VERSION;
	return version;
}

DLL_API
URA_GET_VALID_CODE
{
	return VALIDATE_CODE;
}