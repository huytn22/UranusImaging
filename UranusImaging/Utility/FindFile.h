#pragma once
#include "ConstDef.h"
//#include <string>
#include "ComTypeDef.h"

#ifdef _WINDOWS
#include <Windows.h>
#endif // _WINDOWS

using namespace std;

class CFindFile
{
public:
	CFindFile();
	~CFindFile();

private:
	tstring m_szDir;
	tstring m_tcFileExt;
	HANDLE m_hFind;

public:
	//Open directory
	bool OpenDir(tstring szDir, tstring tcFileExt);
	
	//get first file
	bool GetFirstFile(tstring &FileName);

	//get next file
	bool GetNextFile(tstring &FileName);

};

