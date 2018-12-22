#pragma once
#include "stdafx.h"
#include "Directory.h"
#include "File.h"

/*
 * Class Tree is needed to create a tree of data.
 * In a particular case it creats and stores a tree of directories and files.
 * A tree in this case means a structure of directories that inludes files and other directories inside.
 * This class can create the tree inside the program and also in the filesystem of Windows
 */
class Tree
{
	//nesting depth of the tree 
	int depth;
	//the root of the tree
	shared_ptr<Directory> root;
	
	//the recursive adding of the file to the tree
	void AddRecursive(shared_ptr<Directory>&, shared_ptr<File>&, size_t);

	//the recursive creating the tree in the filesystem of Windows
	void CreateRecursive(shared_ptr<Directory>&);
public:
	
	Tree(shared_ptr<Directory>& dir, size_t depthLevel): depth(depthLevel), root(dir) {}

	//adding of the file to the tree
	void AddFileToTheTree(shared_ptr<File>& file) {
		int counter = 0;
		AddRecursive(root, file, counter);
	}

	//adding of the vector of files to the tree
	void AddVectorOfFilesToTheTree(vector<shared_ptr<File>>& files) {
		for (size_t i = 0; i < files.size(); i++) AddFileToTheTree(files[i]);		
	}
	
	//creating the tree in the filesystem of Windows
	void CreateTheTreeInWindows() {
		CreateRecursive(root);
	}
	
};

