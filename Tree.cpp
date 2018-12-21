#include "Tree.h"


void Tree::AddRecursive(shared_ptr<Directory>& currentFolder, shared_ptr<File>& file, size_t counter) {

	//if the last level of nesting is reached
	if (counter == this->depth|| file->params[counter] == "") {
		//creating of the file in the current folder
		currentFolder->Add(file);
		return;
	}
	for (size_t i = 0; i < currentFolder->dirs.size(); i++) {
		//checking if the folder with the required name (the name of the current param of the file) exists
		if ((*file).params[counter] == currentFolder->dirs[i]->name) {
			
			//going inside the folder, if the folder with the required name was found
			AddRecursive(currentFolder->dirs[i],file, counter + 1);
			return;
		}
	}
	
	//creating the directory if the folder with the required name wasn`t found 
	shared_ptr<Directory> newDir(new Directory(currentFolder->path + '\\' +(*file).params[counter]));
	//adding the folder to the vector of folders
	currentFolder->Add(newDir);
	//going inside the directory which has been just created
	AddRecursive(currentFolder->dirs[currentFolder->dirs.size() - 1],file, counter + 1);

	return;

}
void Tree::CreateRecursive(shared_ptr<Directory>& currentDir) {
	//creating the directory in the filesystem of Windows
	CreateDirectory(currentDir->path.c_str(), NULL);
	
	//creating the files which are inside the currentDir
	for (size_t i = 0; i < currentDir->files.size(); i++)
		rename((currentDir->files[i]->path).c_str(), (currentDir->path +'\\'+ currentDir->files[i]->name).c_str());
	
	//creating the directories which are in the currentDir recursivly 
	for (size_t i = 0; i < currentDir->dirs.size(); i++)
		CreateRecursive(currentDir->dirs[i]);
		
	
	return;
}

