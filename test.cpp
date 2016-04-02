#include "Path.h"
#include "Prompt.h"

/**
 * To start:
 *  1). Create a JCShell object, which creates two objects: Path, and Prompt.
 *  2). Display the Prompt, create a CommandLine object, and await user input from cin.
 *  3). When we get user input, we parse it for the command, and then use the Path.find() method to find the directory.
 *  4). If found, we take the number that was returned from the previous step and pass it to the Path.getDirectory() function.
 *      If not, print an error message, but don't exit the command line.
 *  5). If we found the directory, we fork() another process, and have that process call the execv() function. It passes the command to that
 *      function. If there's no ampersand, we have to also call waitpid() on the parent's id so that they can wait until the newly forked 
 *		process terminates. If there's an ampersand, we don't call waitpid() and proceed as normal. 
 *
 */
int main() {
	Path p;
	int test = p.find("ps");
	cout << test << endl;
	Prompt p2;
	cout << p2.get() << endl;
}
