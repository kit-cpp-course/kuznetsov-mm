#pragma once
#include "stdafx.h"
#include "GlobalData.h"
#include "IComponent.h"
#include <taglib/tag.h>
#include <taglib/fileref.h>
using namespace std;

/*
 * Class File describes a file in a filesystem, it has such fields as: an extension and parameters.
 * And in also contains methods to manupulate the data (set parameters, get parameters...)
 */
class File : public IComponent
{
	string extension;
	
	//inludes the name of the artist, album, genre, year 
	string* params;

	string GetNameFromPath();
	//getting the extension of the file from its path in the filesystem of Windows
	string GetExtensionFromPath();
	//setting of the parameters of the file (artist, album, year, genre)
	void SetParams();

	
public:
			
	File() {};
	File(string path);

	bool IComponent::isFile() const { return true; }
	
	string* GetParam() { return params; }

	~File() { 
		delete[] params; 
	};
};

