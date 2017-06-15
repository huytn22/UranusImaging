//==================================================================================
// Description:
//	TestPlugin.cpp : Defines the exported functions for the DLL application.
//
// Note:
//
// History:
//	2017/06/06		HuyTN	Initialize code.
//==================================================================================

#include "stdafx.h"
#include <map>
#include "..\Utility\DllDef.h"
#include "..\PluginUtil\PluginItf.h"
#include "..\Utility\ConstDef.h"
#include "..\PluginUtil\PlgFactory.h"
#include "..\PluginUtil\PluginBase.h"
#include "..\PluginUtil\PlgTypeDef.h"
#include "..\PluginUtil\PluginMacro.h"
#include "DumPlugin.h"
#include "DumPlugin3.h"

using namespace std;

//==================================================================================
// Description:
//	Version of plugin dll.
//
// Note:
//	
// History:
//	2017/06/06		HuyTN	Initialize code.
//==================================================================================
#define PLG_VERSION _T("0.1.0.0")

//==================================================================================
// Description:
//	Object list of this plugin. When URA_GET_OBJ_INST function is called, 
//	this list will be used to create object instance.
//
// Note:
//	
// History:
//	2017/06/06		HuyTN	Initialize code.
//==================================================================================
PLG_FACTORY_REGISTER(PROJECT_NAME, CDumPlugin)
PLG_FACTORY_REGISTER(PROJECT_NAME, CDumPlugin3)

//==================================================================================
// Description:
//	Get version of plugin dll.
//
// Parameters:
//	None
//
// Return:
//	Version of plugin dll.
//
// Note:
//	
// History:
//	2017/06/06		HuyTN	Initialize code.
//==================================================================================
PLUGIN_API
tstring URA_GET_VERSION()
{
	return PLG_VERSION;
}

//==================================================================================
// Description:
//	Get validation code of plugin dll.
//
// Parameters:
//	None.
//
// Return:
//	Validation code.
//
// Note:
//	
// History:
//	2017/06/06		HuyTN	Initialize code.
//==================================================================================
PLUGIN_API
tstring URA_GET_VALID_CODE()
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
// History:
//	2017/06/06		HuyTN	Initialize code.
//==================================================================================
PLUGIN_API
void* URA_GET_OBJ_INST()
{
	CPlgFactoryBase Factory;

	MAPTYPE* maptype = Factory.GetMap();

	return (void*)maptype;
}