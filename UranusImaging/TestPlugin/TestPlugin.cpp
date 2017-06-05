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
#include "..\Utility\DllDef.h"
#include "..\PluginUtil\PluginItf.h"
#include "..\Utility\ConstDef.h"
#include "DumPlugin.h"
#include "..\PluginUtil\PlgFactory.h"
#include "..\PluginUtil\PlgTypeDef.h"

//==================================================================================
// Description:
//	Version of plugin dll.
//
// Note:
//	
// History:
//	2017/06/06		HuyTN	Initialize code.
//==================================================================================
#define VERSION _T("0.1.0.0")

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
PLG_FACTORY_REGISTER(CDumPlugin)

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
	tstring version = VERSION;
	return version;
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

	tstring PlgName = _T(PROJECT_NAME);



	for (MAPTYPE::iterator it = maptype->begin(); it != maptype->end(); it++)
	{

	}

	return NULL;
}