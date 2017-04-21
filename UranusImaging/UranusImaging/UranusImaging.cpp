// UranusImaging.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>


using namespace std;

bool Read_URAI_ini();

int _tmain(int argc, _TCHAR* argv[])
{
    



	return 0;
}


bool Read_UraI_ini()
{
    //get path of main exe
    _TCHAR szFileName[MAX_PATH];
    
    GetModuleFileName(NULL, szFileName, sizeof(_TCHAR)*MAX_PATH);

	return true;
}