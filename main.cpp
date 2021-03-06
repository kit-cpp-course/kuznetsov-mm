#pragma once
#include "stdafx.h"
#include "GlobalData.h"
#include "ArgumentsValidator.h"
#include "Directory.h"
#include "File.h"
#include "Tree.h"

using namespace std;

namespace fs = std::experimental::filesystem;


int FillVectorOfSongs(vector<shared_ptr<File>>& songs);
int main(size_t count, char ** args) {

	//the reference to the object of the class, where the global variables are stored
	GlobalData& gb = GlobalData::getObject();

	//checking the data from the input args and initializing of the global variables 
	if (!ArgumentsValidator::CheckAndSetArgs(count, args)) {
		cout << "Error in input data" << endl;
		return 0;
	}
	
	//vector of the songs from the source directory
	vector<shared_ptr<File>> songs;

	
	//filling the vector of the songs by the audio files with the popular extensions of the audio files
	FillVectorOfSongs(songs);

	//creating the directory where other folders and files will be stored (the root of the tree)
	shared_ptr<Directory> main(new Directory(gb.DistDirectory));
	

	//creating of the tree
	Tree * tree = new Tree(main, gb.numberOfParams);

	//adding the songs to the tree
	tree->AddVectorOfFilesToTheTree(songs);

	//creating the tree in the filesystem of Windows
	tree->CreateTheTreeInWindows();
		
	delete tree;
	cout << "Music has been succesfully cataloged!" << endl;
	return 0;
}

int FillVectorOfSongs(vector<shared_ptr<File>>& songs) {
	GlobalData& gb = GlobalData::getObject();

	for (const auto & entry : fs::recursive_directory_iterator(gb.SourceDirectory))
	{
		string path = entry.path().string(),
			ext = entry.path().extension().string();
		if (ArgumentsValidator::IsAudio(ext)) {
			try {
				songs.push_back(shared_ptr<File>(new File(path)));
			}
			catch (exception ex) {
				cout << "Couldn't get a metadata from the file: " << path << endl;
				continue;
			}
		}

	}

}