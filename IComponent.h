#pragma once
#include <string>
/*
 * Class IComponent summarizes the concept of file and directory,
 * it contains methods and fields which both file and directory have
 */
class IComponent {
	//getting the name of the file from its path in the filesystem of Windows
	virtual std::string GetNameFromPath() = 0;
protected:
	std::string name;
	std::string path;
public:
	std::string GetName() const { return name; }
	std::string GetPath() const { return path; }
	virtual bool isFile() const = 0;
	
};