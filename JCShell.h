/*
 * JCShell.h
 *
 *  Created on: Mar 26, 2016
 *      Author: jjh35
 */

#ifndef JCSHELL_H_
#define JCSHELL_H_

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "JCShell.h"
#include "CommandLine.h"
#include "Path.h"
#include "Prompt.h"
using namespace std;

class JCShell{

public:
	JCShell();
	void run();

private:
	CommandLine * myLine;
	Path * myPath;
	Prompt * myPrompt;

};



#endif /* JCSHELL_H_ */
