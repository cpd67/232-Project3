/*
 * JCShell.cpp
 *
 *  Created on: Mar 26, 2016
 *      Author: jjh35 Jesse Hulse, Chris Dilley
 *
 */

/*JCShell is the shell class that runs our shell
 * uses Path,Prompt,CommandLine classes
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
			string command(c.getCommand());
			cout << command << endl;
			//Check if built-in command...			
			if(command == "cd") {  //Built-in commands
				cout << "BUILT-IN" << endl;
				
			} else if(command == "exit") {
				exit(1);
			} else if(command == "pwd") {
				cout << "BUILT-IN" << endl;
			} else {
//				cout << c.getCommand() << endl;
				//Else, check if the command is in the Path....
				int directoryNum = myPath->find(command.c_str());			
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
							directory = directory + "/" + command;						
							cout << directory << endl;		
							execve(directory.c_str(), c.getArgVector(), NULL);  //Only problem is this now!
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
		//					string fullPath = directory + "/" + (string)command;
						//	directory = directory + "/" + (string)command;			
							cout << directory << endl;						
							//execv("/bin/ls", c.getArgVector());
							_exit(EXIT_SUCCESS);
						}
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

