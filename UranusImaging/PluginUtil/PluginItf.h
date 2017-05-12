#pragma once
#include "..\Utility\ComTypeDef.h"



// Get version of plugin
typedef tstring (__cdecl *GetVersionsPtr)(void);

// Get compatible code of plugin
typedef tstring (__cdecl *GetValidateCodePtr)(void);

//Use these macro to make sure all dll have the same method name.
////

//get version function. 
#define URA_GET_VERSION tstring uraGetVersion()

// name of get version function
#define URA_GET_VERSION_NAME #uraGetVersion

//get validate function, this is used for indicate valid dll or not.
#define URA_GET_VALID_CODE tstring uraGetValidateCode()

//name of get validate code function.
#define URA_GET_VALID_CODE_NAME #uraGetValidateCode
////
