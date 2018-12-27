#pragma once
#include "stdafx.h"
#include "File.h"
#include "IComponent.h"

/*
 * Class Directory describes a directory in a filesystem. 
 * It contains files and other directories inside and methods to add components to it. 
 */

class Directory : public IComponent
{	
	//getting the name of the directory from its path
	std::string GetNameFromPath();

	//vector of directories which are stored in the object
	std::vector<std::shared_ptr<Directory>> dirs;

	//vector of files which are stored in the object
	std::vector<std::shared_ptr<File>> files;
public:	
	
	//default constructor
	Directory() {};

	//constructor which takes a path to the dir as a parameter
	Directory(std::string path) {
		this->path = path;
		name = GetNameFromPath();
	}

	bool IComponent::isFile() const { return false; }

	//return the vector of directories which are stored in the object
	std::vector<std::shared_ptr<Directory>>& GetDirs() {
		return dirs;
	}

	//return the vector of files which are stored in the object
	std::vector<std::shared_ptr<File>>& GetFiles() {
		return files;
	}
	//adding the directory to the current folder
	void Add(std::shared_ptr<Directory>& dir) {
		dirs.push_back(dir);
	}

	//adding the file to the current folder
	void Add(std::shared_ptr<File>& file) {
		files.push_back(file);
	}
	
	
};

