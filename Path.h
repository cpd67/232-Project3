
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <dirent.h>
#include <sys/types.h>
using namespace std;

class Path {
public:
	Path();
	int find(const string& program) const;
	string getDirectory(int i) const;
private:
	vector<string> myPaths;
};
