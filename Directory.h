#pragma once
#include "stdafx.h"
#include "File.h"
#include "IComponent.h"
using namespace std;


class Directory : public IComponent
{	
	string GetNameFromPath() {
		if (path[path.size() - 1] == '\\') path = path.substr(0, path.size()-1);
		return path.substr(path.find_last_of('\\') + 1);
	}
public:	
	vector<shared_ptr<Directory>> dirs;
	vector<shared_ptr<File>> files;
	
	Directory() {};
	Directory(string path){
		this->path = path;
		name = GetNameFromPath();
	}
	bool IComponent::isFile() const { return false; }

	//adding the directory to the current folder
	void Add(shared_ptr<Directory>& dir) {
		dirs.push_back(dir);
	}

	//adding the file to the current folder
	void Add(shared_ptr<File>& file) {
		files.push_back(file);
	}
	
	
};

