#pragma once
#include <string>
class IComponent {
	//getting the name of the file from its path in the filesystem of Windows
	virtual std::string GetNameFromPath() = 0;
public:
	std::string name;
	std::string path;
	virtual bool isFile() const = 0;
	
};