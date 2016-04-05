#include "Prompt.h"

/**
 * Default-constructor for the Prompt class.
 */
Prompt::Prompt() {
	//Call the update() method (to avoid redundant coding)	
	update(); 
}

/**
 * get() is the accessor for the current value of the Prompt.
 * @return: myCurrentDirectory, a string representing the current directory
 *	        that the user is in.
 */
string Prompt::get() const {
	return myCurrentDirectory;
}

/**
 * update() displays the Prompt and updates it when needed.
 */
void Prompt::update() {
	//http://linux.die.net/man/3/getcwd	
	//Holder for the current working directory
	char holder[PATH_MAX + 1];
	//http://linux.die.net/man/3/getcwd
	//http://www.qnx.com/developers/docs/660/index.jsp?topic=%2Fcom.qnx.doc.neutrino.lib_ref%2Ftopic%2Fg%2Fgetcwd.html
	//Get the current working directory 
	string directory = getcwd(holder, PATH_MAX + 1);
	//Store it
	myCurrentDirectory = (string)directory;		
}
