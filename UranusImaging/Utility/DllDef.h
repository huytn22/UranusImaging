#pragma once

#ifdef  DLL_EXPORT
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif //  DLL_FUNC

#define PLUGIN_API extern "C" DLL_API