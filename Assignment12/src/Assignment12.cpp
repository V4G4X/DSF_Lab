//============================================================================
// Name        : Assignment12.cpp
// Author      : Varun Gawande
// Description : Direct Access File
//============================================================================
#include <iostream>
#include "DAFAdt.h"
using namespace std;

int main(){
	DAFAdt File;
	int ch;
	do{
		cout<<"\n\t DIRECT ACCESS FILE OPERATIONS ::  \n\t -----------------------------------------------------";
		cout<<"\n\t 1. Create New file() \n\t 2. Insert \n\t 3. Search \n\t 4. Display \n\t 5. Exit";
		cin>>ch;
		switch(ch){
		case 1: // create new file and insert records
			File.init();
			File.Create();
			File.Display(1);
			break;
		case 2:
			File.Create();
			File.Display(1);
			break;
		case 3:
			File.Search();
			File.Display(1);
			break;
		case 4:
			File.Display(1);
			break;
		case 5:
			return 0;
		}
	}while(1);
	return 0;
}
