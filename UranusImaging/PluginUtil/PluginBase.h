#pragma once
#include "..\Utility\ComTypeDef.h"


class CPluginBase
{
public:
	CPluginBase();
	~CPluginBase();

protected:
	tstring m_tPlgnVersion; //	version
	//tstring m_tPlgnCode;	//	compatible code

public:
	//get version of this plugin
	virtual tstring GetVersion() { 
		return m_tPlgnVersion; 
	};

	////get compatible code
	//virtual tstring GetPlgnCode() {
	//	return m_tPlgnCode;
	//};
};

