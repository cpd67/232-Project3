#include "JCShell.h"

/**
 * Default-constructor for the JCShell class.
 */
JCShell::JCShell(){
	//Create the Path
	myPath = new Path();
	//Prompt
	myPrompt = new Prompt();
}

/**
 * run() method implements the algorithm described in driver.cpp
 * and runs our JCShell!
 */
void JCShell::run(){	
	//Process id holder
	pid_t pid;
	//Main loop
	while(true) {
		//Display the prompt
		cout << myPrompt->get() << "$";	
		//Create the CommandLine object
		CommandLine c(cin);		
		//If ENTER key was not pressed...
		if(c.getCommand() != NULL) {
			//Check if built-in command...
			if((string)c.getCommand() == "cd") { //cd
				//http://linux.die.net/man/3/chdir
				//Use the first argument passed as the directory to
				//change to
				chdir(c.getArgVector(1));
				//Update the Prompt to reflect the chanegs
				myPrompt->update();	
			} else if((string)c.getCommand() == "exit") { //exit
				exit(1);
			} else if((string)c.getCommand() == "pwd") { //pwd
				//Just display the Prompt
				cout << myPrompt->get() << endl;
			} else {
				//Else, check if the command is in the Path....
				int directoryNum = myPath->find(c.getCommand());			
				if(directoryNum == -1) {  //Not found
					cout << "Command not found!" << endl;
				} else {  //Found
					//Use the directory num to get the directory
					string directory = myPath->getDirectory(directoryNum);
					//Store the command
					string command = c.getCommand();
					//http://geoffgarside.co.uk/2009/08/28/using-execve-for-the-first-time/
					//https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/exec.html
					//http://stackoverflow.com/questions/12575826/using-execv-c-language-to-run-commands-from-a-linux-command-prompt
					//Make the directory include the command
					directory = directory + "/" + command;					
					//If there's no ampersand found, we'll have to wait
					if(c.noAmpersand()) {
						//Fork a process  
						pid = fork();  
						//Child does the execution
						if(pid == 0) { 
							//http://linux.die.net/man/3/execve
							//https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/exec.html
							//Execute the given command
							execve(directory.c_str(), c.getArgVector(), NULL);
							_exit(EXIT_SUCCESS);
						//Parent waits until the child terminates
						} else {
							int status;
							(void)waitpid(pid, &status, 0);
						}
					//Else, we don't have to wait.
					} else {
						//Fork a process
						pid = fork();
						if(pid == 0) {
							//http://www.tutorialspoint.com/unix_system_calls/sched_yield.htm
							//Yield the process to the parent before doing
							//the command
							sched_yield();
							//Execute the command and terminate							
							execve(directory.c_str(), c.getArgVector(), NULL);
							_exit(EXIT_SUCCESS);
						}
					}
				}		
			}						
		}
	}
}
