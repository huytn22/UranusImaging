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
#include "..\Utility\com_include.h"
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
error_t CPluginMan::LoadPlugin(tstring szPluginDir)
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
error_t CPluginMan::LoadPlugin(tstring szPluginDir, PluginOpt PlgOpt)
{
	CFindFile findPlgin;
	error_t ErrRet;

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

		//load all feature in this plugin
		ErrRet = LoadPlgData(hPlgInst);
		if (ErrRet != uraERR_SUCCESS)
		{
			FreeLibrary(hPlgInst);
			continue;
		}

		//store instance of valid plugin
		m_vPlgInst.push_back(hPlgInst);

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
error_t CPluginMan::SetOption(PluginOpt PlgOpt)
{
	m_PlgOption = PlgOpt;

	return uraERR_SUCCESS;
}

//==================================================================================
// Description:
//	Load all feature in plugin.
//
// Parameters:
//	[IN] HINSTANCE hPlgInst	: Instance of plugin.
//
// Return:
//	error type.
//	
//
// Note:
//	
//==================================================================================
error_t CPluginMan::LoadPlgData(HINSTANCE hPlgInst)
{
	GetObjInstPtr GetObjFunc = (GetObjInstPtr)GetProcAddress(hPlgInst, URA_FC_GET_OBJ_NAME);
	if (!GetObjFunc)
	{
		return uraERR_PLG_NO_FEATURE;
	}

	GetObjFunc();

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

//==================================================================================
// Description:
//	Clean all data of plugin manager.
//
// Parameters:
//
// Return:
//	None.
//
// Note:
//	
//==================================================================================
void CPluginMan::Clean()
{
	CleanPlgInst();
}

//==================================================================================
// Description:
//	Clean all instance of loaded plugin.
//
// Parameters:
//
// Return:
//	None.
//
// Note:
//	
//==================================================================================
void CPluginMan::CleanPlgInst()
{
	for (PLG_INST::iterator it = m_vPlgInst.begin(); it != m_vPlgInst.end(); it++)
	{
		FreeLibrary(*it);
	}
}