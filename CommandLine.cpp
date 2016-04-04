/*
 * CommandLine.cpp
 *
 *  Created on: Mar 26, 2016
 *      Author: jjh35
 */

#include "CommandLine.h"

CommandLine::CommandLine(istream& in){
	argumentC = 0;
	argumentV = NULL;
	isAmp=false;
	string it="this will be the maximum length command        ";
	char str[256];
    in.clear();
	in.getline(str,256);	
	string str1(str);
	//the following loop counts to see how many white space chars are in the input
	int count=0;
	for(int i=0;i<str1.length();i++){
		if(isspace(str1[i]))
			count++;
		if(str1[i]=='&')
			isAmp=true;
	}
	
	count=count+1;
	if(count <= 0) {
		count =1;
	}
	
	char * element = NULL; 
	char ** temp = (char **)calloc(count+1,sizeof(char*));	
	element = strtok (str," ");
	while (element!=NULL){
		element[sizeof(char*)] = '\0';
		//strcpy(ARGV[0],element);
		temp[argumentC] = element;
		//printf ("%s\n",element);
		element = strtok (NULL, " ");
		argumentC++;
	}
	 argumentV = temp;
	 argumentV[argumentC] = (char*)NULL; 
   	//Free the element holder variable
	 free(element);
//     cout <<"the temp value of the pointer is"<< temp << endl;
 //    cout << "the size if " << argumentC << endl;
}

char* CommandLine::getCommand() const {
	return argumentV[0];
}

char** CommandLine::getArgVector() const {
	return argumentV;
}

int CommandLine::getArgCount() const {
	return argumentC;
}

char* CommandLine::getArgVector(int i) const {
	return argumentV[i];
}

bool CommandLine::noAmpersand() const {
	return !isAmp;
}

//Happens when we are double freeing something....
CommandLine::~CommandLine(){

//	free(argumentV);

}
