/*
 * JCShell.cpp
 *
 *  Created on: Mar 26, 2016
 *      Author: jjh35
 */


#include "JCShell.h"
#include <iostream>
#include "CommandLine.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;



JCShell::JCShell(){

}


//void JCShell::run(){
//	while(true){
//
//       cin.getline(userInput,256);
//       cout << userInput << "end" <<endl;
//       CommandLine commandline;
//       commandline.parse(userInput);
////       for(int i=0;i<commandline.getArgc(); i++){
////    	   cout << i << "." << &commandline.getArgv()[i] << endl;
////       }
//	}
//}

void JCShell::run(){
	while(true){

    cout <<flush;
		//cin.getline(userInput,256);

       CommandLine commandline(cin);
       //char ** it = commandline.getArgVector();
       int count = commandline.getArgCount();

       for(int i = 0; i<count; i++){
    	   cout <<commandline.getArgVector(i) <<endl;

       }

	}
}

