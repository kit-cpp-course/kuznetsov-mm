#pragma once
#include "stdafx.h"
#include "GlobalData.h"
#include "IComponent.h"
#include <taglib/tag.h>
#include <taglib/fileref.h>
using namespace std;
class File : public IComponent
{
	
	string GetNameFromPath() {
		return path.substr(path.find_last_of('\\') + 1);
	}

	//getting the extension of the file from its path in the filesystem of Windows
	string GetExtensionFromPath() {	
		return path.substr(path.find_last_of('.') + 1);
	}
	//setting of the parameters of the file (artist, album, year, genre)
	void SetParams();

	string extension;
public:

	//inludes the name of the artist, album, genre, year 
	string* params;
	
	File() {};

	File(string path){
		this->path = path;
		name = GetNameFromPath();
		extension = GetExtensionFromPath();		
		SetParams();
	}
	bool IComponent::isFile() const { return true; }
	
	~File() { 
		delete[] params; 
	};
};

