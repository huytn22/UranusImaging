//==================================================================================
// Description:
//
//
//
// Note:
//
//==================================================================================
#include "FindFile.h"

#if defined(_WINDOWS) || defined(WIN32)
//#include <Windows.h>
#include "Shlwapi.h"
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
//==================================================================================
bool CFindFile::OpenDir(tstring szDir, tstring tcFileExt)
{
	bool bRet = true;

	//save dir
	m_szDir = szDir;
	//_tcscpy(m_szDir, szDir);

	//save extension
	m_tcFileExt = tcFileExt;
	//_tcscpy(m_tcFileExt, tcFileExt);

	//check if dir is exist or not
	if (!PathFileExists(szDir.c_str()))
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
//
// Note:
//		None.
//==================================================================================
bool CFindFile::GetFirstFile(tstring &FileName)
{
	bool bRet = true;
	WIN32_FIND_DATA ffd;

	tstring filter = m_szDir.c_str();
	filter.append(_T("\\*."));
	filter += m_tcFileExt;

	//clear before finding
	FileName.clear();

	m_hFind = FindFirstFile(filter.c_str(), &ffd);
	if (m_hFind == INVALID_HANDLE_VALUE)
	{
		bRet = false;
	}
	else
	{
		FileName = ffd.cFileName;
	}

	return bRet;
}

bool CFindFile::GetNextFile(tstring &FileName)
{
	bool bRet = true;
	WIN32_FIND_DATA ffd;

	//clear before finding
	FileName.clear();

	if (FindNextFile(m_hFind, &ffd) != 0)
	{
		FileName = ffd.cFileName;
	}
	else
	{
		bRet = false;
	}

	return bRet;
}