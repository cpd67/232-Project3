/*
 * driver.cpp runs the main program
 *
 *  Created on: Mar 26, 2016
 *      Author: jjh35 Jesse Hulse, Chris Dilley (cpd5)
 *  this code was provided for the project
 *  For: CS-232 - Project 3: A Command Shell.
 */

#include "JCShell.h"

/**
 * Our algorithm:
 *  1). Create a JCShell object, which creates two objects: Path, and Prompt.
 *  2). Display the Prompt, create a CommandLine object,
 *      and await user input from cin.
 *  3). When we get user input, we parse it for the command, and determine 
 *      if it's a built-in command. If it is, execute it.
 *  4). If not, use the Path.find() method to find the directory.
 *  5). If found, we take the number that was returned from the previous step 
 *      and pass it to the Path.getDirectory() function.
 *      If not, print an error message, but don't exit the command line.
 *  6). If we found the directory, we fork() another process, 
 *      and have that process call the execv() function. 
 *      It passes the command to that function. 
 *      If there's no ampersand, we have to also call waitpid() on the 
 *      parent's id so that they can wait until the newly forked 
 *		process terminates. If there's an ampersand, 
 *      we don't call waitpid() and proceed as normal.
 */
int main()
{
	//Create the shell
	JCShell myShell;
	//Run it!
	myShell.run();
}
