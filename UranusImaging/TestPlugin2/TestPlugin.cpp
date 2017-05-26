// TestPlugin.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "..\Utility\DllDef.h"
#include "..\PluginUtil\PluginItf.h"
#include "..\Utility\ConstDef.h"
#include "DumPlugin.h"
#include "DumPlugin2.h"

//==================================================================================
// Description:
//	Version of plugin dll.
//
// Note:
//	
//==================================================================================
#define VERSION _T("0.1.0.0")

//==================================================================================
// Description:
//	Object list of this plugin. When URA_GET_OBJ_INST function is called, 
//	this list will be used to create object instance.
//
// Note:
//	
//==================================================================================
//void* g_arrObj[] =
//{
//	(void*)(new CDumPlugin())
//};
#define OBJ_LSIT \
		CDumPlugin,\
		CDumPlugin2


//==================================================================================
// Description:
//	Get version of plugin dll.
//
// Parameters:
//	None.
//
// Return:
//	Version of plugin dll.
//
// Note:
//	
//==================================================================================
PLUGIN_API
TCHAR* URA_GET_VERSION()
{
	//tstring version = VERSION;
	return VERSION;
}

//==================================================================================
// Description:
//	Get validation code of plugin dll.
//
// Parameters:
//	None.
//
// Return:
//	validation code.
//
// Note:
//	
//==================================================================================
PLUGIN_API
TCHAR* URA_GET_VALID_CODE()
{
	return VALIDATE_CODE;
}


//==================================================================================
// Description:
//	Get validation code of plugin dll.
//
// Parameters:
//	None.
//
// Return:
//	validation code.
//
// Note:
//	
//==================================================================================
PLUGIN_API
void* URA_GET_OBJ_INST()
{


	return NULL;
}



