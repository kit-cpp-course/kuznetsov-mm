#pragma once
#include <string>
using namespace std;

class GlobalData {
	
	GlobalData() = default;
	~GlobalData() = default;

	GlobalData& operator=(const GlobalData&) = delete;
	GlobalData(const GlobalData&) = delete;

public:
	
	//max number of the params for catalogization
	const size_t MAX_NUMBER_OF_PARAMS = 4;
	//this array is needed to convert the numbers {0, 1, 2, 3} to the string values (e.g. PARAMETERS_IN_ORDER[0] - "artist")
	const string* PARAMETERS_IN_ORDER = new string[MAX_NUMBER_OF_PARAMS]{ "artist", "album", "year", "genre" };

	//number of params for catalogization, that were set by a user
	size_t numberOfParams;
	//the array of params, that were set by a user
	string* params;
	//the path to  the folder, where the audiofiles are stored
	string SourceDirectory; 
	//the path to the folder, where the tree sould be created
	string DistDirectory;

	static GlobalData& getObject() {
		static GlobalData a;
		return a;
	}
};
