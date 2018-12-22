#pragma once
#include "stdafx.h"
#include "File.h"
#include "IComponent.h"
using namespace std;
/*
 * Class Directory describes a directory in a filesystem. 
 * It contains files and other directories inside and methods to add components to it. 
 */

class Directory : public IComponent
{	
	string GetNameFromPath();

	vector<shared_ptr<Directory>> dirs;
	vector<shared_ptr<File>> files;
public:	
	
	
	Directory() {};
	Directory(string path){
		this->path = path;
		name = GetNameFromPath();
	}
	bool IComponent::isFile() const { return false; }

	vector<shared_ptr<Directory>>& GetDirs() {
		return dirs;
	}
	vector<shared_ptr<File>>& GetFiles() {
		return files;
	}
	//adding the directory to the current folder
	void Add(shared_ptr<Directory>& dir) {
		dirs.push_back(dir);
	}

	//adding the file to the current folder
	void Add(shared_ptr<File>& file) {
		files.push_back(file);
	}
	
	
};

