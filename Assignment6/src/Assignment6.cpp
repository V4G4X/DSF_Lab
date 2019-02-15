//============================================================================
// Name        : Assignment6.cpp
// Author      : Varun Gawande
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <string.h>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	char name[50];
	cin.getline(name,50);
	time_t now = time(0);
	char *st_name = ctime(&now);
	strcat(name,st_name);
	cout<<name<<endl;
	return 0;
}
