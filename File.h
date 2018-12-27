#pragma once
#include "stdafx.h"
#include "GlobalData.h"
#include "IComponent.h"
#include <taglib/tag.h>
#include <taglib/fileref.h>


/*
 * Class File describes a file in a filesystem, it has such fields as: an extension and parameters.
 * And in also contains methods to manupulate the data (set parameters, get parameters...)
 */
class File : public IComponent
{
	//an extension of the file
	std::string extension;
	
	//includes the name of the artist, album, genre, year 
	std::string* params;

	//getting the name of the file from its path
	std::string GetNameFromPath();

	//getting the extension of the file from its path in the filesystem of Windows
	std::string GetExtensionFromPath();

	//setting of the parameters of the file (artist, album, year, genre)
	void SetParams();

	
public:
	
	//default constructor
	File() {};

	//constructor which takes a path as a parameter
	File(std::string path);

	//copy constructor
	File(const File& file);

	//assignment operator
	File& operator=(const File& file); 

	bool IComponent::isFile() const { return true; }
	
	//return the array of the parameters of the object
	std::string* GetParam() { return params; }

	~File() { 
		delete[] params; 
	};
};

