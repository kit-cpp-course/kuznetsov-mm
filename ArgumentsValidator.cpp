#include "ArgumentsValidator.h"
bool ArgumentsValidator::CheckPath(string path) {
	return fs::exists(path);
}
bool ArgumentsValidator::Unique(string param) {
	GlobalData& gb = GlobalData::getObject();
	for (size_t i = 0; i < gb.numberOfParams; i++)
		if (param == gb.params[i]) return false;
	return true;
}

bool ArgumentsValidator::CheckAndSetArgs(size_t size, char ** args) {
	GlobalData& gb = GlobalData::getObject();

	//number of the args shouldn`t be less than 4
	//("path to exe file by default" "path to the source directory" "path to the distination directory" "number of args")
	if (size <= 4 || size > 4 + gb.MAX_NUMBER_OF_PARAMS) return false;

	//check for existence of the sorce directory
	if (CheckPath(args[1])) gb.SourceDirectory = args[1]; else return false;

	//check for a possibility to create a directory in the distination folder and creating it in the case if it is possible
	try {
		CreateDirectory(args[2], NULL);
		gb.DistDirectory = args[2];
	}
	catch (...) {
		return false;
	}

	//number of parameters for catalogization 
	size_t currentArg = atoi(args[3]);

	//checking if the numer of parameters is correct and creating of the array of params if it is so
	if (currentArg >= 0 && currentArg <= gb.MAX_NUMBER_OF_PARAMS) {
		gb.numberOfParams = currentArg;
		gb.params = new string[gb.numberOfParams];
	}
	else return false;

	//reading the params and filling the array of params with them 
	for (size_t i = 0; i < gb.numberOfParams; i++)
	{
		currentArg = atoi(args[4 + i]);
		if (currentArg >= 0 && currentArg <= gb.MAX_NUMBER_OF_PARAMS - 1) {
			
			//checking for the uniqueness of the parameter (if it has been already set)
			if (!Unique(gb.PARAMETERS_IN_ORDER[currentArg])) return false;
			
			//filling of the current cell of the array with the param
			gb.params[i] = gb.PARAMETERS_IN_ORDER[currentArg];
		}
	}

	return true;



}