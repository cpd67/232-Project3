/*
 * CommandLine.cpp
 *
 *  Created on: Mar 26, 2016
 *      Author: Jesse Hulse. jjh35.
 *
 *   
 *  Command line uses the constructor to parse through a user input and put each white space separated 
 *  word as into an argument vector. The vector consistes of char * pointers to the word. There are 
 *  various accessors that allow access to the different pointers/arguments. 
 */

#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

class CommandLine {
public:
	//the different methods for this class
	CommandLine(istream& in);
	void parse(char input[]);
	char** getArgVector() const;
	int getArgCount() const ;
	char* getCommand() const;
	char* getArgVector(int i) const;
	bool noAmpersand() const;
	~CommandLine();
private:
	//the instance variables. char** is the vector of pointers to the different arguments from the user
	//argumentC is the number of elements in argumentV
	//isAmp is true if there is an ampersand in the user input
	char** argumentV;
	int argumentC;
	bool isAmp;

};



#endif /* COMMANDLINE_H_ */
