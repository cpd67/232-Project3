#include "Prompt.h"

//http://www.qnx.com/developers/docs/660/index.jsp?topic=%2Fcom.qnx.doc.neutrino.lib_ref%2Ftopic%2Fg%2Fgetcwd.html
Prompt::Prompt() {
	update();  //Call the update() method to avoid redundant coding
}

//Gets the current value of the Prompt
string Prompt::get() const {
	return myCurrentDirectory;
}

//Updates the Prompt whenever we change it
//If we use cd, we have to update the Prompt in order 
//to show that we updated it.
//This function does exactly that.
void Prompt::update() {
	char holder[PATH_MAX + 1];	
	string directory = getcwd(holder, PATH_MAX + 1);
	myCurrentDirectory = (string)directory;		
}
