/**
 * Prompt.h contains the source code that allows for the creation of a visual 
 * prompt that displays the current directory that the user is in.
 * For: CS-232 - Project 3: A Command Shell.
 * Created by: Chris Dilley & Jesse Hulse.
 * Date: 04/04/16 (Completion date).
 */

//Includes
#include <iostream>
#include <unistd.h>
#include <string>
#include <sstream>
//http://stackoverflow.com/questions/9449241/where-is-path-max-defined-in-linux
//(I used limits.h to find PATH_MAX and it worked for me. Here is where
// I discovered where it is located).
#include <limits.h>
#include <cstring>
using namespace std;

/**
 * Prompt creates a visual prompt that displays the current working directory.
 */
class Prompt {
public:
	//Display the Prompt
	Prompt();
	//Get the value of the Prompt
	string get() const;
	//Display the Prompt and update it from time to time
	void update();
private:
	//The current directory to display in the Prompt
	string myCurrentDirectory;
};
