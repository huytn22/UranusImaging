// TestPlugin.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "..\Utility\DllDef.h"
#include "..\PluginUtil\PluginItf.h"
#include "..\Utility\ConstDef.h"
#include "DumPlugin.h"
#include "DumPlugin2.h"
#include "..\PluginUtil\PlgFactory.h"
#include "..\PluginUtil\PlgTypeDef.h"

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
PLG_FACTORY_REGISTER(CDumPlugin)
PLG_FACTORY_REGISTER(CDumPlugin2)


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
tstring URA_GET_VERSION()
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
tstring URA_GET_VALID_CODE()
{
	return VALIDATE_CODE;
}

#define SET_THIS_FILE_NAME() \
    char* const THIS_FILE_NAME = \
        

//==================================================================================
// Description:
//	Get object of plugin dll.
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
	CPlgFactoryBase Factory;

	MAPTYPE* maptype = Factory.GetMap();

	MAP_PLUGIN mapPlugin;

	tstring FileName = _T(__FILE__);


	for (MAPTYPE::iterator it = maptype->begin(); it != maptype->end(); it++)
	{

	}

	return NULL;
}



