
#include <iostream>
#include <unistd.h>
#include <string>
#include <sstream>
#include <limits.h>
#include <cstring>
using namespace std;

class Prompt {
public:
	Prompt();
	string get() const;
	void update();
private:
	string myCurrentDirectory;
};
