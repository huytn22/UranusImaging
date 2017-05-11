//==================================================================================
// Description:
//
//
//
// Note:
//
//
// History:
// 08/05/2017	Huy		Original created.
//==================================================================================

#include "stdafx.h"

#if defined(_WINDOWS) || defined(WIN32)
#include <Windows.h>
#endif // _WINDOWS

#include "PluginMan.h"
#include "..\Utility\FindFile.h"
#include "..\Utility\ErrorDef.h"
#include "..\Utility\StringDef.h"


//==================================================================================
// Description:
//
// Parameters:
//
// Return:
//
// Note:
//
// History:
// 08/05/2017	Huy		Original created.
//==================================================================================
CPluginMan::CPluginMan()
{

}

//==================================================================================
// Description:
//
// Parameters:
//
// Return:
//
// Note:
//
// History:
// 08/05/2017	Huy		Original created.
//==================================================================================
CPluginMan::~CPluginMan()
{

}

//==================================================================================
// Description:
//	Load all plugin.
// Parameters:
//	None.
// Return:
//	
// Note:
//	
// History:
//	08/05/2017	Huy		Original created.
//==================================================================================
int CPluginMan::LoadPlugin(tstring szPluginDir)
{
	return LoadPlugin(szPluginDir, m_PlgOption);
}

//==================================================================================
// Description:
//	Load all plugin.
// Parameters:
//	None.
// Return:
//	
// Note:
//	
// History:
//	08/05/2017	Huy		Original created.
//==================================================================================
int CPluginMan::LoadPlugin(tstring szPluginDir, PluginOpt PlgOpt)
{
	CFindFile findPlgin;

	//open plugin directory
	if (!findPlgin.OpenDir(szPluginDir, PLUGIN_EXT))
	{
		return uraERR_DIR_NOT_EXIST;
	}

	//load all found plugin
	tstring tFileName;
	if (!findPlgin.GetFirstFile(tFileName))
	{
		return uraERR_FILE_NOT_FOUND;
	}

	do {
		//create plugin file path
		tstring tFilePath = szPluginDir + _T("\\") + tFileName;

		//load plugin
		HINSTANCE hPlgInst = LoadLibrary(tFilePath.c_str());
		if (!hPlgInst)
			continue;

		//check compatible plugin

		


	} while (!findPlgin.GetNextFile(tFileName));
	
	return uraERR_SUCCESS;
}

//==================================================================================
// Description:
//	Set plugtion option
// Parameters:
//	[IN] PluginOpt PlgOpt	: Plugin option
// Return:
//	
// Note:
//	
// History:
//	10/05/2017	Huy		Original created.
//==================================================================================
int CPluginMan::SetOption(PluginOpt PlgOpt)
{
	m_PlgOption = PlgOpt;

	return uraERR_SUCCESS;
}

//==================================================================================
// Description:
//	Check this plugin is compatible or not.
// Parameters:
//	[IN] HINSTANCE hPlgInst	: Instance of plugin.
// Return:
//	true	: compatible.
//	false	: not compatible.
// Note:
//	
// History:
//	10/05/2017	Huy		Original created.
//==================================================================================
bool CPluginMan::CheckCompatible(HINSTANCE hPlgInst)
{
	bool bResult = false;

	

	return bResult;
}