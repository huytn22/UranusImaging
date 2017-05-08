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
#include "FindFile.h"

#ifdef _WINDOWS
//#include <Windows.h>
#include "Shlwapi.h"
#include "TCHAR.H"
#endif // _WINDOWS


CFindFile::CFindFile()
: m_hFind(INVALID_HANDLE_VALUE)
{
}


CFindFile::~CFindFile()
{
}

//==================================================================================
// Description:
//		Open directory. Check whether directory is exist or not.
//
// Parameters:
//		[IN] TCHAR* szDir	: Working directory
//
// Return:
//		true	: Success.
//		false	: Failed.
// Note:
//
// History:
// 08/05/2017	Huy		Original created.
//==================================================================================
bool CFindFile::OpenDir(TCHAR* szDir, TCHAR* tcFileExt)
{
	bool bRet = true;

	//save dir
	_tcscpy(m_szDir, szDir);

	//save extension
	_tcscpy(m_tcFileExt, tcFileExt);

	//check if dir is exist or not
	if (!PathFileExists(szDir))
		bRet = false;

	return bRet;
}

//==================================================================================
// Description:
//		Open directory. Check whether directory is exist or not.
//
// Parameters:
//		[IN] TCHAR* szDir	: Working directory
//
// Return:
//		true	: Success.
//		false	: Failed.
// Note:
//
// History:
// 08/05/2017	Huy		Original created.
//==================================================================================
bool CFindFile::GetFirstFile(TCHAR* pFileName)
{
	bool bRet = true;
	WIN32_FIND_DATA ffd;

	m_hFind = FindFirstFile(m_szDir, &ffd);
	if (m_hFind == INVALID_HANDLE_VALUE)
	{
		bRet = false;
	}

	return bRet;
}
