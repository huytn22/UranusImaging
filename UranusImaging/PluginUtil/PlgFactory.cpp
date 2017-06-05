#include "stdafx.h"
#include "PlgFactory.h"

MAPTYPE* CPlgFactoryBase::m_mapType = NULL;

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
//	
// History:
//	2017/06/06		HuyTN	Initialize code.
//==================================================================================
CPlgFactoryBase::CPlgFactoryBase()
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
//	
// History:
//	2017/06/06		HuyTN	Initialize code.
//==================================================================================
CPlgFactoryBase::~CPlgFactoryBase()
{
}

//==================================================================================
// Description:
//	
//
// Parameters:
//	None.
//
// Return:
//	None.
//
// Note:
//	
// History:
//	2017/06/06		HuyTN	Initialize code.
//==================================================================================
CPluginBase* CPlgFactoryBase::CreateInstance(tstring clsType)
{
	MAPTYPE::iterator it = GetMap()->find(clsType);
	if (it == GetMap()->end())
		return NULL;

	return it->second();
}

//==================================================================================
// Description:
//	
//
// Parameters:
//	None.
//
// Return:
//	None.
//
// Note:
//	
// History:
//	2017/06/06		HuyTN	Initialize code.
//==================================================================================
MAPTYPE* CPlgFactoryBase::GetMap()
{
	if (m_mapType == NULL)
	{
		m_mapType = new MAPTYPE();
	}

	return m_mapType;
}
