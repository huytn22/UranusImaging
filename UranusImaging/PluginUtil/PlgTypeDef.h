#pragma once

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
//	Create instance of objects base on Template function.
//
// Note:
//	
//==================================================================================
template<typename T>
CPluginBase* CreateT() { return new T; }


