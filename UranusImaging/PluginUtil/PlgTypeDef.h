#pragma once

//==================================================================================
// Description:
//	Option of plugin. Use for verify this plugin.
//
// Note:
//	
//==================================================================================
typedef struct PluginOpt {
	tstring		tVersion;
	tstring		tValidateCode;
};

//==================================================================================
// Description:
//	Map Type and create function of class.
//
// Note:
//	
//==================================================================================
typedef std::map<tstring, CPluginBase*(*)()> MAPTYPE;

//==================================================================================
// Description:
//	Map Type and create function of class.
//
// Note:
//	
//==================================================================================
typedef std::map<PluginID, CPluginBase*> MAP_PLUGIN;

//==================================================================================
// Description:
//	Create instance of objects base on Template function.
//
// Note:
//	
//==================================================================================
template<typename T>
CPluginBase* CreateT() { return new T; }


