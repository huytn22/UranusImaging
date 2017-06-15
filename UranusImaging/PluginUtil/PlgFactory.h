#pragma once
#include <map>
#include "..\Utility\com_include.h"
#include "PluginBase.h"
#include "PlgTypeDef.h"

using namespace std;

class CPlgFactoryBase
{
public:
	CPlgFactoryBase();
	~CPlgFactoryBase();

public:
	CPluginBase* CreateInstance(tstring clsType);

public:
	static MAPTYPE* GetMap();

private:
	static MAPTYPE* m_mapType;
};

//==================================================================================
// Description:
//	Register class in to factory using singleton instance of factory.
//
// Note:
//
// History:
//	2017/06/06		HuyTN	Initialize code.
//==================================================================================
template<typename T>
class FactoryRegister : CPlgFactoryBase {
public:
	FactoryRegister(tstring s) {
		GetMap()->insert(std::make_pair(s, &CreateT<T>));
	}
};

//==================================================================================
// Description:
//	Declare variable of class in .cpp file.
//
// Note:
//	This function is used for self-register in class. Currently version is not support.
//
// History:
//	2017/06/06		HuyTN	Initialize code.
//==================================================================================
#define REGISTER_DEC_TYPE(NAME) \
    static FactoryRegister<NAME> regst;

//==================================================================================
// Description:
//	define variable of class in .cpp file.
//
// Note:
//	This function is used for self-register in class. Currently version is not support.
//
// History:
//	2017/06/06		HuyTN	Initialize code.
//==================================================================================
#define REGISTER_DEF_TYPE(NAME) \
	FactoryRegister<NAME> NAME::regst(_T(#NAME));


//==================================================================================
// Description:
//	This macro is used for registering into factory.
//
// Note:
//	Using this macro to auto export class from dll.
//
// History:
//	2017/06/06		HuyTN	Initialize code.
//==================================================================================
#define PLG_FACTORY_REGISTER(PLG_NAME, CLS_TYPE) \
	FactoryRegister<CLS_TYPE> OBJTYPE_##CLS_TYPE(##PLG_NAME"@"#CLS_TYPE);

