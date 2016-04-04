/*
 * CommandLine.h
 *
 *  Created on: Mar 26, 2016
 *      Author: jjh35
 */

#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>

using namespace std;

class CommandLine {
public:
	CommandLine(istream& in);
	//void parse(const char *array[],int length);
	void parse(char input[]);
	char** getArgVector() const;
	int getArgCount() const ;
	char* getCommand() const;
	char* getArgVector(int i) const;
	bool noAmpersand() const;
	~CommandLine();
private:
	char** argumentV;
	int argumentC;
	bool isAmp;

};



#endif /* COMMANDLINE_H_ */
