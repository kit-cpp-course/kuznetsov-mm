#pragma once
#include "stdafx.h"
#include "GlobalData.h"

namespace fs = std::experimental::filesystem;
/*
 * Class ArgumentsValidator is needed to check the data, which was introduced by a user for correctness
 */
class ArgumentsValidator
{			
	//checking if the path is correct (if it exists)
	static bool CheckPath(std::string path);

	//checking for the uniqueness of the parameter
	static bool Unique(std::string param);

	//checking the params and filling the array of params with them if they are correct
	static bool CheckAndFillTheArrayOfParams(char** args, size_t size, size_t startNumber);

public:

	//checking if the args that were set by a user are correct 
	static bool CheckAndSetArgs(size_t size, char ** args); 

	//checking if the file is an audio file from which the metadata could be taken
	static bool IsAudio(std::string extension);
};

