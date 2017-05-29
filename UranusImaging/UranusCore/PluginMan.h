#pragma once

#include <vector>
#include "..\Utility\com_include.h"
#include "..\Utility\PluginDef.h"

using namespace std;
typedef vector<HINSTANCE> PLG_INST;

class CPluginMan
{
public:
	CPluginMan();
	~CPluginMan();

private:
	PluginOpt m_PlgOption;
	PLG_INST m_vPlgInst;

//private method
private:
	bool VerifyPlugin(HINSTANCE hPlgInst);
	bool VerifyVersion(tstring tVersion);
	
	error_t LoadPlgData(HINSTANCE hPlgInst);

	void Clean();
	void CleanPlgInst();

//public method
public:
	//load plugin
	error_t LoadPlugin(tstring szPluginDir, PluginOpt PlgOpt);
	error_t LoadPlugin(tstring szPluginDir);

	error_t SetOption(PluginOpt PlgOpt);
};

