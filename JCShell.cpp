/*
 * JCShell.cpp
 *
 *  Created on: Mar 26, 2016
 *      Author: jjh35
 */

#include "JCShell.h"

JCShell::JCShell(){
	myPath = new Path();
	myPrompt = new Prompt();
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
	cout << myPrompt->get() << "$";	
	while(true) {
		pid_t pid;
		//Create the CommandLine object
		CommandLine c(cin);
		//Check if the command passed is valid
		//If ENTER key was not pressed...
		if(c.getCommand() != NULL) {
		//	char * command = c.getCommand();
			//Check if built-in command...			
			if((string)c.getCommand() == "cd") {  //Built-in commands
				cout << "BUILT-IN" << endl;
			} else if((string)c.getCommand() == "exit") {
				
			} else if((string)c.getCommand() == "pwd") {
				cout << "BUILT-IN" << endl;
			}
			//Else, check if the command is in the Path....
			int directoryNum = myPath->find(c.getCommand());			
			if(directoryNum == -1) {  //Not found
				cout << "Command not found!" << endl;
			} else {  //Found
				cout << "FOUND!" << endl;
				//Use the directory num to get the directory
				string directory = myPath->getDirectory(directoryNum);
				//And so it begins...
				//Executing a command
				if(c.noAmpersand()) {  //If there's no ampersand found, we'll have to use waitpid()
					cout << "COUT FROM NO AMPERSAND" << endl;
					pid = fork();  //Fork a process					
					if(pid == 0) {   //
						//string fullPath = directory + "/" + (string)command;
					//	directory = directory + "/" + (string)command;						
						//cout << directory << endl;		
						execve("/bin/ls", c.getArgVector(), NULL);
						_exit(EXIT_SUCCESS);
					} else {
						int status;
						(void)waitpid(pid, &status, 0);
					}
				} else {  //Else, we don't have to wait.
					cout << "COUT FROM AMPERSAND" << endl;
					pid = fork();
					if(pid == 0) {
						sched_yield();
		//				string fullPath = directory + "/" + (string)command;
					//	directory = directory + "/" + (string)command;			
						cout << directory << endl;						
						//execv("/bin/ls", c.getArgVector());
						_exit(EXIT_SUCCESS);
					}
				}	
			}				
		} //Else, do nothing
		cout << myPrompt->get() << "$";			
//		cout << flush;		
		//cin.getline(userInput,256);
	//	CommandLine commandline(cin);
		//char ** it = commandline.getArgVector();
//		int count = myLine->getArgCount();
		
//		cout << myPrompt->get() << "$";
//       for(int i = 0; i<count; i++){
 //   	   cout <<commandline.getArgVector(i) <<endl;
  //     }
	

	}
}

