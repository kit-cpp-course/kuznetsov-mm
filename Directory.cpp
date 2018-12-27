#include "Directory.h"

std::string Directory::GetNameFromPath() {
	if (path[path.size() - 1] == '\\') path = path.substr(0, path.size() - 1);
	return path.substr(path.find_last_of('\\') + 1);
}