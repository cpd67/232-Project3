#include "Path.h"

/**
 * Default-constructor for the Path class.
 */
Path::Path() {
	//http://www.cplusplus.com/reference/cstdlib/getenv/
	//Get the PATH variable
	char * path = getenv("PATH");
	//Change it to a String
	string p = string(path);
	//http://www.cplusplus.com/reference/sstream/stringstream/str/
	//Change it to a String Stream (to manipulate it)
	stringstream ss(p);
	string holder = "";
	//https://www.daniweb.com/programming/software-development/threads/117408/splitting-a-string-using-a-delimiter
	//Get the directories seperated by ':' 
	//And push them into the vector of Strings
	while(getline(ss, holder, ':')) {
		myPaths.push_back(holder);
	}
}

/**
 * find() method determines if a program is in the path of directories.
 * @param: program, a const string reference representing the program to
 *         search for in the Path.
 * @return: the index of the directory holding the program, or -1 if the 
		    program is not found in the Path.
 */ 
int Path::find(const string& program) const {
	//The following code was adapted from this website which taught me
	//the basic idea of creating the structures needed to open directories,
	//looping through directories and opening and closing them:
	//http://stackoverflow.com/questions/3554120/open-directory-using-c	
	//File descriptor
	struct dirent * folder;
	//Directory to open
	DIR * directory;
	//Iterate through the directories in PATH
	for(unsigned i = 0; i < myPaths.size(); i++) {
		//http://man7.org/linux/man-pages/man3/opendir.3.html
		//Open the directory
		directory = opendir(myPaths[i].c_str());
		//http://linux.die.net/man/3/readdir
		//Iterate through the files in it
		while((folder=readdir(directory)) != NULL) {
			//If the name of the file in the folder is the name of the program
			if(string(folder->d_name) == program) {
				//http://linux.die.net/man/3/closedir
				//Close the directory, and return the index
				closedir(directory);
				folder = NULL;
				return i;
			}
		} 
	}	
	//Program not found!
	//http://linux.die.net/man/3/closedir
	//Close the directory
	closedir(directory);
	folder = NULL;
	return -1;
}

/**
 * Accessor for a directory in the Path.
 * @param: i, an int representing the index into the vector of directories
 *		   that compose the path environment variable.
 * @return: myPaths[i], a string representing the directory at index i
 *			in the vector.
 */
string Path::getDirectory(int i) const {
	return myPaths[i];
}
