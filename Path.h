/**
 * Path.h contains the source code that allows for the creation of a Path
 * object that holds the directories in a user's PATH variable. 
 * For: CS-232 - Project 3: A Command Shell.
 * Created by: Chris Dilley & Jesse Hulse.
 * Date: 04/04/16 (Completion date).
 */

//Includes
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <dirent.h>
#include <sys/types.h>
using namespace std;

/**
 * Path holds the directories from the PATH environment variable.
 */
class Path {
public:
	//Constructor
	Path();
	//Find a program in the path
	int find(const string& program) const;
	//Get the directory inside of the stored vector
	string getDirectory(int i) const;
private:
	//Holds the pathes from the PATH variable
	vector<string> myPaths;
};
