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


/*Commandline uses parses the input and constructos a char ** vector that has pointers to the different words that the
 *user inputs. It allows stores the number of arguments in the vector (argumentC)
 *@istream& in is the in stream used to get the input from the user (it is STDIN)
 * returns nothing, gives values to argumentV, argumentC, and isAmp
 */

CommandLine::CommandLine(istream& in){
	argumentC = 0;
	argumentV = NULL;
	isAmp=false;
   //this is the maximum size of one word that our vector will store
	string it="this will be the maximum length command        ";





   string input;
   getline(cin,input);
   char* str;
   str = const_cast<char*>(input.c_str());



  int count=0;
	for(int i=0;i<input.length();i++){
		if(isspace(input[i])) {
			count++;
            //cout <<"loop" <<endl;
             }
        //if there is an ampersand, then set the correspoinding instance variable to true.
		if(input[i]=='&')
			isAmp=true;
	}
	//if there is one one argument (no white space) then set count to 1
	count=count+1;
	if(count <= 0) {
		count =1;
	}





  
    
	
	char * element = NULL; 
	//char ** temp = (char **)calloc(count+1,sizeof(char*));	
    argumentV = (char **)calloc(count+1,sizeof(char*));
   //strtok is a c tokenizer that breaks apart the user input separated by a white space.
   //the idea for this while loop came from http://www.cplusplus.com/reference/cstring/strtok/
	element = strtok (str," ");
    int c = 0;
	while (element!=NULL){
       // cout << "the " << c++ << " element is " << element<< endl;
		//element[sizeof(char*)] = '\0';
		//strcpy(ARGV[0],element);
		argumentV[argumentC] = element;
		//printf ("%s\n",element);
		element = strtok (NULL, " ");
		argumentC++;
	}
   //I added the following line of code
   argumentC=count;
	 //argumentV = temp;
	argumentV[argumentC] = (char*)NULL;
   	//Free the element holder variable
	 free(element);
 
//     cout <<"the temp value of the pointer is"<< temp << endl;
 //    cout << "the size if " << argumentC << endl;
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

//Happens when we are double freeing something....
//the deconstructor
CommandLine::~CommandLine(){

//	free(argumentV);

}

