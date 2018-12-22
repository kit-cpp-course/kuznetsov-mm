#include "ArgumentsValidator.h"
bool ArgumentsValidator::CheckPath(string path) {
	return fs::exists(path);
}
bool ArgumentsValidator::Unique(string param) {
	GlobalData& gb = GlobalData::getObject();
	for (size_t i = 0; i < gb.numberOfParams; i++) {
		if (param == gb.params[i]) return false;
	}
		
	return true;
}

bool ArgumentsValidator::CheckAndFillTheArrayOfParams(char** args, size_t size, size_t startNumber) {
	GlobalData& gb = GlobalData::getObject();
	size_t currentArg;

	for (size_t i = 0; i < gb.numberOfParams; i++)
	{	
		currentArg = atoi(args[i+startNumber]);	
		//checking for correctness of the current parameter 
		if (!(currentArg >= 0 && currentArg <= gb.MAX_NUMBER_OF_PARAMS - 1)) return false; 
		//checking for the uniqueness of the parameter (if it has been already set)	
		if (!Unique(gb.PARAMETERS_IN_ORDER[currentArg])) return false;
		//filling of the current cell of the array with the param		
		gb.params[i] = gb.PARAMETERS_IN_ORDER[currentArg];		
	}

	return true;
}

bool ArgumentsValidator::CheckAndSetArgs(size_t size, char ** args) {
	GlobalData& gb = GlobalData::getObject();

	//number of the args shouldn`t be less than 4
	//("path to exe file by default" "path to the source directory" "path to the distination directory" and at least 1 param)
	if (size <= 4 || size > 3 + gb.MAX_NUMBER_OF_PARAMS) return false;

	//check for existence of the sorce directory
	if (CheckPath(args[1])) gb.SourceDirectory = args[1]; else return false;

	//check for a possibility to create a directory in the distination folder and creating it in the case if it is possible
	if (!CheckPath(args[2]) && !CreateDirectory(args[2], NULL)) return false;
	gb.DistDirectory = args[2];

	//number of parameters for catalogization (all array except 3 first args: path, path, path)
	gb.numberOfParams = size - 3;
	gb.params = new string[gb.numberOfParams];	
	
	//reading the params and filling the array of params with them 
	if(!CheckAndFillTheArrayOfParams(args, size, 3)) return false;

	return true;
}

bool ArgumentsValidator::IsAudio(string ext) {
	const size_t numberOfValidExt = 9;
	string validExt[numberOfValidExt] = {".mp3",".wav",".flac",".ogg",".aiff",".m4a",".m4a", ".mp4",".ape"};

	for (size_t i = 0; i < numberOfValidExt; i++) {
		if (ext == validExt[i]) return true;
	}
		
	return false;
}