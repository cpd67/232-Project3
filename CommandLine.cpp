/*
 * CommandLine.cpp
 *
 *  Created on: Mar 26, 2016
 *      Author: jjh35
 */

#include "CommandLine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstring>


using namespace std;

CommandLine::CommandLine(istream& in){
	argumentC = 0;
	argumentV = NULL;
	isAmp=false;
	string it="this will be the maximum length command";
	char str[256];
    in.clear();
	in.getline(str,256);
	//the following loop counts to see how many white space chars are in the input
	int count=0;
	for(int i=0;i<256;i++){
		if(str[i]==' ')
			count++;
		if(str[i]=='&')
			isAmp=true;
	}
	count=count-2;
	if(count <= 0) {
		count =1;
	}
	cout << count<<endl;
	char * element = new char [it.length()+1];
	//char * element = (char*) malloc(it.length()+1);
	char** temp = (char **)calloc(count,sizeof(it));
	element =strtok (str," ");
	//getline(in,(string)element,' ');
	while (element!=NULL){
		//strcpy(ARGV[0],element);
		temp[argumentC] = element;
		//printf ("%s\n",element);
		element = strtok (NULL, " ");
		argumentC++;
	}
	argumentV = temp;
	cout <<"the temp value of the pointer is"<< temp << endl;
	for(int i = 0;i<3;i++){
		//cout << "The " << i << "th element in argv is " << &temp[0] << endl;
		//cout << argumentV[i] << endl;

	}

}

char* CommandLine::getCommand() const {
	return argumentV[0];
}

//void CommandLine::parse(char array[]){
//	int i = 0;
//	while(1){
//		if(array[i]==' '){
//			i++;
//		}
//		else
//			break;
//	}
//
//	for(int j = i;j<256;j++){
//		string s;
//		for(int k = j; k<50; k++){
//           //cout << array[k] << endl;
//			if(array[k]!=' '){
//				s = s + array[k];
//			//	cout << s << endl;
//			}
//			else {
//				//cout <<"space char found" << endl;
//				int size = sizeof(s);
//				//argv[argc] = (string*) malloc(100);
//				argv[argc] = new string;
//				//cout << argv[argc];
//				*argv[argc]=s;
//				argc++;
//				j=k;
//				break;
//			}
//		}
//	}
//}

//
//void CommandLine::parse(const char *array[],int length){
//	vector <string> strV;
//	int i = 0;
////	while(1){
////		if(array[i]==' '){
////			i++;
////		}
////		else
////			break;
////	}
//
//	for(int j = 0;j<length;j++){
//		string s;
//		for(int k = j; k<10; k++){
//			//cout << array[k] << endl;
//			if(*array[k]!=' ' || j!=length-1){
//				s = s + array[k];
//
//				cout << s << endl;
//			}
//			else {
//				//cout <<"space char found" << endl;
//				strV.push_back(s);
//				j=k;
//				argc++;
//				break;
//			}
//		}
//	}
//
//
//	cout << argc<< endl << flush;
//
//
//	for(int q=0;q<argc;q++){
//		cout<< endl << strV[q] << endl;
//	}
//
//}


void CommandLine::parse(char input[]){
	//	//I got the idea for this code from http://www.cplusplus.com/reference/cstring/strtok/
	//	char * element;
	//	element =strtok (input," ");
	//
	//
	//	while (element!=NULL){
	//		//	argv[argc]=&element;
	//		printf ("%s\n",element);
	//		element = strtok (NULL, " ");
	//		argc++;
	//	}
	//	cout << argc<<endl;
	//	//char * pData;
	//	//char *argV[] = (char*)calloc(argc,sizeof("a very very long command"));
	//	//char *argV[] = (char* []) malloc (sizeof("a very very long command")*argc);
	//
	//
	//
	//	//	element =strtok (input," ");
	//	//	//&pData[0]= element;
	//	//	for(int i = 0; i<argc;i++) {
	//	//		argv[i]=element;
	//	//			element = strtok (NULL, " ");
	//	//			argc++;
	//	//	}

}


char** CommandLine::getArgVector(){
	return argumentV;
}
int CommandLine::getArgCount(){
	return argumentC;
}

char* CommandLine::getArgVector(int i){
return argumentV[i];
}

bool CommandLine::noAmpersand() const {
	return !isAmp;
}

CommandLine::~CommandLine(){

	free(argumentV);

}


