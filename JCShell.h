/*
 * JCShell.h contains the source code needed in order to create a JCShell, 
 * which mimics the command line in Linux.
 * Created on: Mar 26, 2016
 * Author: jjh35, Jesse Hulse, Chris Dilley.
 * For: CS-232 - Project 3: A Command Shell.
 */

#ifndef JCSHELL_H_
#define JCSHELL_H_

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>  //fork() ...
#include <sys/wait.h>  //waitpid() ...
#include "JCShell.h"
#include "CommandLine.h"
#include "Path.h"
#include "Prompt.h"
using namespace std;

/* JCShell is the shell class that runs our shell and 
 * uses Path, Prompt, and CommandLine classes.
 */
class JCShell{

public:
	//Default-constructor
	JCShell();
	//Run the shell!
	void run();

private:
	//Path
	Path * myPath;
	//Prompt
	Prompt * myPrompt;

};



#endif /* JCSHELL_H_ */
