#pragma once
#include "stdafx.h"
#include "GlobalData.h"


namespace fs = std::experimental::filesystem;

class ArgumentsValidator
{		
	ArgumentsValidator() = default;
	~ArgumentsValidator() = default;
	
	//checking if the path is correct (if it exists)
	static bool CheckPath(string path); 

	//checking for the uniqueness of the parameter
	static bool Unique(string param);

public:

	//checking if the args that were set by a user are correct 
	static bool CheckAndSetArgs(size_t size, char ** args); 

	//checking if the file is an audio file from which the metadata could be taken
	static bool IsAudio(string extension);
};

