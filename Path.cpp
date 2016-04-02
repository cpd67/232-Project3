#include "Path.h"

//https://www.daniweb.com/programming/software-development/threads/117408/splitting-a-string-using-a-delimiter
//http://www.cplusplus.com/reference/sstream/stringstream/str/ (for #includes using stringstream() )
//http://www.cplusplus.com/reference/cstdlib/getenv/
Path::Path() {
	//Get the PATH variable
	char * path = getenv("PATH");
	//Change it to a String
	string p = string(path);
	//Change it to a String Stream (to manipulate it)
	stringstream ss(p);
	string holder = "";
	//Get the directories seperated by ':' 
	//And push them into the vector of Strings
	while(getline(ss, holder, ':')) {
		myPaths.push_back(holder);
	}
}

//http://man7.org/linux/man-pages/man3/opendir.3.html
//http://linux.die.net/man/3/readdir
//http://stackoverflow.com/questions/3554120/open-directory-using-c
//http://linux.die.net/man/3/closedir
int Path::find(const string& program) const {
	//File descriptor
	struct dirent * folder;
	//Directory to open
	DIR * directory;
	//Iterate through the directories in PATH
	for(unsigned i = 0; i < myPaths.size(); i++) {
		//Open the directory
		directory = opendir(myPaths[i].c_str());
		//Iterate through the files in it
		while((folder=readdir(directory)) != NULL) {
			//If the name of the file in the folder is the name of the program...
			if(string(folder->d_name) == program) {
				//Close the directory, free up memory, and return the index
				closedir(directory);
		//		delete folder;
				folder = NULL;
				return i;
			}
		} 
	}	
	//Program not found!
	closedir(directory);
	//Close the directory, and free up memory
//	delete folder;
	folder = NULL;				
	return -1;
}

string Path::getDirectory(int i) const {
	return myPaths[i];
}
