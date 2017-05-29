#pragma once

enum error_t{
	//error: 0
	//No error.
	uraERR_SUCCESS = 0,

	//error: 1
	//Directory does not exist.
	uraERR_DIR_NOT_EXIST,

	//error: 2
	//File was not found.
	uraERR_FILE_NOT_FOUND,

	//error: 3
	uraERR_PLG_NO_FEATURE,
	
	uraERR_MAX
};