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
#include "..\PluginUtil\PluginBase.h"
#include "..\PluginUtil\PluginItf.h"


//==================================================================================
// Description:
//	Constructor.
//
// Parameters:
//	None.
//
// Return:
//	None.
//
// Note:
//	None.
//
//==================================================================================
CPluginMan::CPluginMan()
{

}

//==================================================================================
// Description:
//	Destructor.
//
// Parameters:
//	None.
//
// Return:
//	None.
//
// Note:
//	None.
//
//==================================================================================
CPluginMan::~CPluginMan()
{

}

//==================================================================================
// Description:
//	Load all plugin.
//
// Parameters:
//	[IN] tstring szPluginDir	: Plugin folder.
//
// Return:
//	Error code.
//
// Note:
//	None.
//	
//==================================================================================
int CPluginMan::LoadPlugin(tstring szPluginDir)
{
	return LoadPlugin(szPluginDir, m_PlgOption);
}

//==================================================================================
// Description:
//	Load all plugin.
//
// Parameters:
//	[IN] tstring szPluginDir	: Plugin folder.
//	[IN] PluginOpt PlgOpt		: Plugin option.
//
// Return:
//	Error code.
//
// Note:
//
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
		if (!VerifyPlugin(hPlgInst))
		{
			FreeLibrary(hPlgInst);
			continue;
		}


	} while (findPlgin.GetNextFile(tFileName));
	
	return uraERR_SUCCESS;
}

//==================================================================================
// Description:
//	Set plugtion option
//
// Parameters:
//	[IN] PluginOpt PlgOpt	: Plugin option.
//
// Return:
//	Error code.
//	
// Note:
//	
//==================================================================================
int CPluginMan::SetOption(PluginOpt PlgOpt)
{
	m_PlgOption = PlgOpt;

	return uraERR_SUCCESS;
}

//==================================================================================
// Description:
//	Check this plugin is compatible or not.
//
// Parameters:
//	[IN] HINSTANCE hPlgInst	: Instance of plugin.
//
// Return:
//	true	: compatible.
//	false	: not compatible.
//
// Note:
//	
//==================================================================================
bool CPluginMan::VerifyPlugin(HINSTANCE hPlgInst)
{
	// get GetValidateCode
	GetValidateCodePtr GetValidateCodeFC = (GetValidateCodePtr)GetProcAddress(hPlgInst, URA_FC_VALIDCODE_NAME);
	if (!GetValidateCodeFC)
		return false;

	// verify if this dll is not a plugin of this software
	if (GetValidateCodeFC() != VALIDATE_CODE)
		return false;

	//get GetVersions function
	GetVersionsPtr GetVersionFC = (GetVersionsPtr)GetProcAddress(hPlgInst, URA_FC_VERSION_NAME);
	if (!GetVersionFC)
		return false;

	//verify if version is not compatible
	if (!VerifyVersion(GetVersionFC()))
		return false;

	return true;
}

//==================================================================================
// Description:
//	Check this plugin is compatible or not.
//
// Parameters:
//	[IN] HINSTANCE hPlgInst	: Instance of plugin.
//
// Return:
//	true	: compatible.
//	false	: not compatible.
//
// Note:
//	
//==================================================================================
bool CPluginMan::VerifyVersion(tstring tVersion)
{
	return true;
}