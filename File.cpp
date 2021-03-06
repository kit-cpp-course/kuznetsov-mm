#include "File.h"
using namespace std;

void File::SetParams() {
	GlobalData& gb = GlobalData::getObject();
	TagLib::FileRef f(path.c_str());
	this->params = new string[gb.numberOfParams];
	for (size_t i = 0; i < gb.numberOfParams; i++)
	{
		if (f.tag() == nullptr) continue;
		if (gb.params[i] == "artist") {
			this->params[i] = f.tag()->artist().toCString();
			continue;
		}
		if (gb.params[i] == "album") {
			this->params[i] = f.tag()->album().toCString();
			continue;
		}
		if (gb.params[i] == "year") {
			size_t year = f.tag()->year();
			if (year == 0) {
				this->params[i] = "";
			}
			else {
				this->params[i] = to_string(year);
			}			
			continue;
		}
		if (gb.params[i] == "genre") {			
			this->params[i] = f.tag()->genre().toCString();
			int indexOfSlash = params[i].find_first_of('/');
			//in the case, when the genre is written as: "Hip-hop / Rap", it is impossible to create the folder
			//so it is needed to change '/' to ','
			if (indexOfSlash != -1) params[i][indexOfSlash] = ',';
			continue;
		}
	}
}
string File::GetNameFromPath() {
	return path.substr(path.find_last_of('\\') + 1);
}
string File::GetExtensionFromPath() {
	return path.substr(path.find_last_of('.') + 1);
}

File::File(string path) {
	this->path = path;
	name = GetNameFromPath();
	extension = GetExtensionFromPath();
	SetParams();
}

File::File(const File& file) {
	GlobalData& gb = GlobalData::getObject();
	extension = file.extension;
	name = file.name;
	path = file.path;
	params = new string[gb.numberOfParams];
	for (size_t i = 0; i < gb.numberOfParams; i++)
	{
		params[i] = file.params[i];
	}
}

File& File::operator=(const File& file) {
	GlobalData& gb = GlobalData::getObject();
	extension = file.extension;
	name = file.name;
	path = file.path;
	params = new string[gb.numberOfParams];
	for (size_t i = 0; i < gb.numberOfParams; i++)
	{
		params[i] = file.params[i];
	}
	return *this;
}