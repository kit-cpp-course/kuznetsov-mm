#include "Tree.h"
using namespace std;

void Tree::AddRecursive(shared_ptr<Directory>& currentDir, shared_ptr<File>& file, size_t counter) {

	//vector of directories inside the current directory
	vector<shared_ptr<Directory>>& dirs = currentDir->GetDirs();

	//if the last level of nesting is reached
	if (counter == this->depth|| file->GetParam()[counter] == "") {
		//creating of the file in the current folder
		currentDir->Add(file);
		return;
	}
	for (size_t i = 0; i < dirs.size(); i++) {
		//checking if the folder with the required name (the name of the current param of the file) exists
		if (file->GetParam()[counter] == dirs[i]->GetName()) {			
			//going inside the folder, if the folder with the required name was found
			AddRecursive(dirs[i],file, counter + 1);
			return;
		}
	}
	
	//creating the directory if the folder with the required name wasn`t found 
	shared_ptr<Directory> newDir(new Directory(currentDir->GetPath() + '\\' + file->GetParam()[counter]));
	//adding the folder to the vector of folders
	currentDir->Add(newDir);
	//going inside the directory which has been just created
	AddRecursive(dirs[dirs.size() - 1],file, counter + 1);

	return;

}
void Tree::CreateRecursive(shared_ptr<Directory>& currentDir) {

	//vector of directories inside the current directory
	vector<shared_ptr<Directory>>& dirs = currentDir->GetDirs();
	//vector of files inside the current directory
	vector<shared_ptr<File>>& files = currentDir->GetFiles();

	//creating the directory in the filesystem of Windows
	CreateDirectory(currentDir->GetPath().c_str(), NULL);
	
	//creating the files which are inside the currentDir
	for (size_t i = 0; i < files.size(); i++) {
		rename((files[i]->GetPath()).c_str(), (currentDir->GetPath() +'\\'+ files[i]->GetName()).c_str());
	}
			
	//creating the directories which are in the currentDir recursivly 
	for (size_t i = 0; i < dirs.size(); i++) {
		CreateRecursive(dirs[i]);
	}			
	return;
}

