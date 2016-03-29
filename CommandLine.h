/*
 * CommandLine.h
 *
 *  Created on: Mar 26, 2016
 *      Author: jjh35
 */

#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_
#include<string>

using namespace std;

class CommandLine {
public:
	CommandLine(istream& in);
	//void parse(const char *array[],int length);
	void parse(char input[]);
	char** getArgVector();
	int getArgCount();
	char* getCommand() const;
	char* getArgVector(int i);
private:
	char** argumentV;
	int argumentC;

};



#endif /* COMMANDLINE_H_ */
