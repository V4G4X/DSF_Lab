//============================================================================
// Name        : Assignnment9.cpp
// Author      : Varun Gawande
// Description : Hashing in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Hash.h"
#include "HashNonRep.h"
using namespace std;

int main() {
	int r;
	HashNR *hTableNR=NULL;
	Hash *hTable=NULL;
	cout<<"Enter 1 for Replacement, 0 for Non-Replacement\nFor Hashing Mechanism\n";
	cin>>r;
	if(r==0)	hTableNR = new HashNR;
	else		hTable	 = new Hash;
	int ch;
	do{
		cout<<"1.Insert Record\n2.Print Table\n3.Search Record\n4.Delete Record\n5.Exit\n";
		cin>>ch;
		cin.ignore();
		switch (ch) {
		case 1:{				//Insert Record
			if(hTable){			//With Replacement
				hTable->insert();
				hTable->printTable();
			}
			else{				//Without Replacement
				hTableNR->insert();
				hTableNR->printTable();
			}
			break;
		}
		case 2:{				//Print Table
			if(hTable){			//With Replacement
				hTable->printTable();
			}
			else{				//Without Replacement
				hTableNR->printTable();
			}
			break;
		}
		case 3:{				//Search a Record
			int phoneNo;
			cout<<"Enter phone number: ";
			cin>>phoneNo;
			if(hTable){			//With Replacement
				Record r = hTable->search(phoneNo);
				cout<<r.name<<"\t"<<r.rollNo<<"\t"<<r.phoneNo<<endl;
			}
			else{				//Without Replacement
				RecordNR r = hTableNR->search(phoneNo);
				cout<<r.name<<"\t"<<r.rollNo<<"\t"<<r.phoneNo<<endl;
			}
			break;
		}
		case 4:{				//Delete a Record
			int phoneNo;
			cout<<"Enter phone number: ";
			cin>>phoneNo;
			if(hTable){			//With Replacement
				hTable->dlete(phoneNo);
				hTable->printTable();
			}
			else{				//Without Replacement
				hTableNR->dlete(phoneNo);
				hTableNR->printTable();
			}
			break;
		}
		case 5:
			cout<<"Exiting Program"<<endl;
			break;
		default:
			cout<<"Enter Proper Choices"<<endl;
			break;
		}
	}while(ch!=5);
	return 0;
}
