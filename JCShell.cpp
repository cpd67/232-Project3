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

void JCShell::run(){	
	//Display Prompt for the first time
	cout << myPrompt->get() << "$";	
	while(true) {
		pid_t pid;
		//Create the CommandLine object
		CommandLine c(cin);		
		//Check if the command passed is valid
		//If ENTER key was not pressed...
		if(c.getCommand() != NULL) {
			//Check if built-in command...
			if((string)c.getCommand() == "cd") { //cd
				chdir(c.getArgVector(1));
				myPrompt->update();	
			} else if((string)c.getCommand() == "exit") { //exit
				exit(1);
			} else if((string)c.getCommand() == "pwd") { //pwd
				cout << myPrompt->get() << endl;
			} else {
				//Else, check if the command is in the Path....
				int directoryNum = myPath->find(c.getCommand());			
				if(directoryNum == -1) {  //Not found
					cout << "Command not found!" << endl;
				} else {  //Found
					//Use the directory num to get the directory
					string directory = myPath->getDirectory(directoryNum);
					string command = c.getCommand();					
					directory = directory + "/" + command;					
					//Executing a command
					//If there's no ampersand found, we'll have to wait
					if(c.noAmpersand()) {  
						pid = fork();  //Fork a process
						if(pid == 0) {   //
							execve(directory.c_str(), c.getArgVector(), NULL);
							_exit(EXIT_SUCCESS);
						} else {
							int status;
							(void)waitpid(pid, &status, 0);
						}
					//Else, we don't have to wait.
					} else {  
						cout << "COUT FROM AMPERSAND" << endl;
						pid = fork();
						if(pid == 0) {
							sched_yield();
							execve(directory.c_str(), c.getArgVector(), NULL);
							_exit(EXIT_SUCCESS);
						}
					}
				}		
			}						
	} //Else, do nothing
	cout << myPrompt->get() << "$";			
	}
}

