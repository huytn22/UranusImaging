#pragma once
#include "..\Utility\ComTypeDef.h"



// Get version of plugin
typedef TCHAR* (__cdecl *GetVersionsPtr)(void);

// Get compatible code of plugin
typedef TCHAR* (__cdecl *GetValidateCodePtr)(void);

// Get objects instance
typedef void* (__cdecl *GetObjInstPtr)(void);

//Use these macro to make sure all dll have the same method name.
////
#define URA_STR(x) #x
#define URA_GET_NAME(fc) URA_STR(fc)

//get version function. 
#define URA_GET_VERSION uraGetVersion
// name of get version function
#define URA_FC_VERSION_NAME	URA_GET_NAME(URA_GET_VERSION)

//get validate function, this is used for indicate valid dll or not.
#define URA_GET_VALID_CODE uraGetValidateCode
//name of function that get validate code.
#define URA_FC_VALIDCODE_NAME URA_GET_NAME(URA_GET_VALID_CODE)

//get object of this plugin.
#define URA_GET_OBJ_INST uraGetObjInst
//name of function that get object instance.
#define URA_FC_GET_OBJ_NAME URA_GET_NAME(URA_GET_OBJ_INST)
////
