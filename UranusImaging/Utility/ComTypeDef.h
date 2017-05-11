#pragma once
#include <string>

#if defined(_WINDOWS) || defined(WIN32)
#include "TCHAR.H"
#endif // _WINDOWS

using namespace std;

typedef basic_string<TCHAR>   tstring;
