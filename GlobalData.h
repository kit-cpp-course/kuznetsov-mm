#pragma once
#include <string>

/*
 * Class GlobalData is needed to contain the data which is used in the whole project.
 * In general, it contains the data, which was inputted by a user and some constants. 
 */
class GlobalData {
	
	GlobalData() = default;
	~GlobalData() {
		delete[] params;
		delete[] PARAMETERS_IN_ORDER;
	}

	GlobalData& operator=(const GlobalData&) = delete;
	GlobalData(const GlobalData&) = delete;

public:
	
	//max number of the params for catalogization
	const size_t MAX_NUMBER_OF_PARAMS = 4;
	//this array is needed to convert the numbers {0, 1, 2, 3} to the string values (e.g. PARAMETERS_IN_ORDER[0] - "artist")
	const std::string* PARAMETERS_IN_ORDER = new std::string[MAX_NUMBER_OF_PARAMS]{ "artist", "album", "year", "genre" };

	//number of params for catalogization, that were set by a user
	size_t numberOfParams;
	//the array of params, that were set by a user
	std::string* params;
	//the path to  the folder, where the audiofiles are stored
	std::string SourceDirectory;
	//the path to the folder, where the tree sould be created
	std::string DistDirectory;

	//return the reference to the object of the class
	static GlobalData& getObject() {
		static GlobalData a;
		return a;
	}
};
