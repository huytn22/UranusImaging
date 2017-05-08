#pragma once
#include "ConstDef.h"
#include <string>

using namespace std;

class CFindFile
{
public:
	CFindFile();
	~CFindFile();

private:
	TCHAR m_szDir[_MAX_PATH];
	TCHAR m_tcFileExt[FILE_EXT_NUM];
	HANDLE m_hFind;

public:
	//Open directory
	bool OpenDir(TCHAR* szDir, TCHAR* tcFileExt);
	
	//get first file
	bool GetFirstFile(TCHAR* pFileName);

};

