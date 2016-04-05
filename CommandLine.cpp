/*
 * CommandLine.cpp
 *
 *  Created on: Mar 26, 2016
 *      Author: Jesse Hulse. jjh35.
 *   
 *  Command line uses the constructor to parse through a user input and put each white space separated 
 *  word as into an argument vector. The vector consistes of char * pointers to the word. There are 
 *  various accessors that allow access to the different pointers/arguments. 
 */

#include "CommandLine.h"


/*Commandline uses parses the input and constructos a char ** vector that has 
 *pointers to the different words that the
 *user inputs. It allows stores the number of arguments in the vector (argumentC)
 *@istream& in is the in stream used to get the input from the user (it is STDIN)
 * returns nothing, gives values to argumentV, argumentC, and isAmp
 */
CommandLine::CommandLine(istream& in){
	argumentC = 0;
	argumentV = NULL;
	isAmp=false;
	//Input from the user
	string input;
	//Get it from cin
	getline(cin,input);
	char* str;
	//Cast the input to a const char *
	str = const_cast<char*>(input.c_str());

	int count=0;
	//Loop through the input and count the number of white space characters
	for(int i=0;i<input.length();i++){
		if(isspace(input[i])) {
			count++;
		}
		//if there is an ampersand, then set the correspoinding instance variable to true.
		if(input[i]=='&') {
			isAmp=true;
			//http://stackoverflow.com/questions/5891610/how-to-remove-characters-from-a-string
			//Take out the ampersand from the command
			//Nate B. showed me how to do this as well
			input.erase (std::remove(input.begin(), input.end(), '&'), input.end());
		}
	}

	//if there is one one argument (no white space) then set count to 1
	count=count+1;
	if(count <= 0) {
		count =1;
	}

	char * element = NULL; 
	argumentV = (char **)calloc(count+1,sizeof(char*));
	//strtok is a c tokenizer that breaks apart the user input separated by a white space.
	//the idea for this while loop came from http://www.cplusplus.com/reference/cstring/strtok/
	element = strtok (str," ");
	int c = 0;
	while (element!=NULL){
		argumentV[argumentC] = element;
		element = strtok (NULL, " ");
		argumentC++;
	}
	//I added the following line of code
	//Initialize argumentC to count
	argumentC=count;
	//You need a NULL at the end of the char ** vector
	//When passing it into execve().
	//http://linux.die.net/man/3/execv
	argumentV[argumentC] = (char*)NULL;
	//Free the element holder variable
	free(element);
}


/* getCommand() returns the pointer to the first argument (the command)
 *no arguments to the function
 *returns a char* to the first argument (the command)
 */
char* CommandLine::getCommand() const {
	return argumentV[0];
}

/* getArgVector returns the argumentV
 * returns a char** that points to the first argument in the vector
 */
char** CommandLine::getArgVector() const {
	return argumentV;
}

/*getArgCount returns the number of arguments in the argumentV
 *returns an int: the number of arguemnts in argumentV
 */
int CommandLine::getArgCount() const {
	return argumentC;
}

/*getArgVector returns the argument at the specified index
 *@int i is the index of the desired argument
 *returns a pointer to the argument
 */
char* CommandLine::getArgVector(int i) const {
	return argumentV[i];
}

/*noAmpersand returns whether or not this is no ampersand
 *returns true is there is no amerpsand, false otherwise
 */
bool CommandLine::noAmpersand() const {
	return !isAmp;
}

/**
 * The deconstructor for the CommandLine class.
 */
CommandLine::~CommandLine(){
	free(argumentV);
	argumentV = NULL;
}
