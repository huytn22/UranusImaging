#pragma once
//==================================================================================
// Description:
//	Error ID.
//
// Note:
//	
// History:
//	2017/06/07		HuyTN	Initialize code.
//==================================================================================
enum error_t{
	//error: 0x0000
	//NO error.
	uraERR_SUCCESS = 0x0000,

	//error: 0x0001
	//Directory does not exist.
	uraERR_DIR_NOT_EXIST,

	//error: 0x0002
	//File was not found.
	uraERR_FILE_NOT_FOUND,

	//error: 0x0003
	//Plugin is valid but it hasn't any feature to use.
	uraERR_PLG_NO_FEATURE,
	
	uraERR_MAX
};