#pragma once


#include "..\Utility\ComTypeDef.h"
#include "..\Utility\ComTypeDef.h"
#include "..\Utility\PluginDef.h"

class CPluginMan
{
public:
	CPluginMan();
	~CPluginMan();

private:
	PluginOpt m_PlgOption;

//private method
private:
	bool CheckCompatible(HINSTANCE hPlgInst);

//public method
public:
	//load plugin
	int LoadPlugin(tstring szPluginDir, PluginOpt PlgOpt);
	int LoadPlugin(tstring szPluginDir);

	int SetOption(PluginOpt PlgOpt);
};

