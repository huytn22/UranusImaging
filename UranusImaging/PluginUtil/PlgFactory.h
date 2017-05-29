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

template<typename T>
class FactoryRegister : CPlgFactoryBase {
public:
	FactoryRegister(tstring s) {
		GetMap()->insert(std::make_pair(s, &CreateT<T>));
	}
};

//Declare variable as member of class
#define REGISTER_DEC_TYPE(NAME) \
    static FactoryRegister<NAME> regst;

//define variable of class in .cpp file
#define REGISTER_DEF_TYPE(NAME) \
	FactoryRegister<NAME> NAME::regst(_T(#NAME));

//register into factory, use this macro to auto export class from dll.
#define PLG_FACTORY_REGISTER(CLS_TYPE) \
	FactoryRegister<CLS_TYPE> OBJTYPE_##CLS_TYPE(_T(#CLS_TYPE));
