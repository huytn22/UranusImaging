#pragma once
#include "..\Utility\ComTypeDef.h"



// Get version of plugin
typedef tstring (__cdecl *GetVersionsPtr)(void);

// Get compatible code of plugin
typedef tstring (__cdecl *GetValidateCodePtr)(void);

//Use these macro to make sure all dll have the same method name.
////
#define URA_GET_NAME(fc) #fc

//get version function. 
//#define URA_GET_VERSION tstring uraGetVersion()
#define URA_GET_VERSION uraGetVersion

// name of get version function
#define URA_FC_VERSION_NAME	URA_GET_NAME(URA_GET_VERSION)

//get validate function, this is used for indicate valid dll or not.
//#define URA_GET_VALID_CODE tstring uraGetValidateCode()
#define URA_GET_VALID_CODE uraGetValidateCode

//name of get validate code function.
#define URA_FC_VALIDCODE_NAME URA_GET_NAME(URA_GET_VALID_CODE)
////
