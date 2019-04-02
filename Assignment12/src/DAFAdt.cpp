/*
 * DAFAdt.cpp
 */
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
#include"DAFAdt.h"
using namespace std;

DAFAdt::DAFAdt() {
	filesize = 0;
}

void DAFAdt::init() {
	int i;
	cout << "\n\t Enter the file name for new file";
	cin >> Filename;

	cout << "enter the  No of records for file ::";
	cin >> filesize;

	strcpy(Records.name," ");
	Records.emp_id = -1;
	Records.salary = 0.0;
	Records.chain = -1;
	DAfile.open(Filename, ios::out | ios::binary);

	if(DAfile){
		for (i = 0; i < filesize; i++) {
			DAfile.write((char*) &Records, sizeof(Records));
		}
		DAfile.close();
		Display(0);
	} else
		cout << "\n\t Unable to create a file";
}

int DAFAdt::update_chain(int hash2, int index, int i) {
	Rec R1;
	if (hash2 == index)
		return 1;
	return 0;
}

void DAFAdt::Create(){
	int i, j, n, hash2;
	int flag = 0, flag1 = 0;
	char ch = 'y';
	Rec R1;
	fstream seqfile;
	int index, offset;
	i = 0;
	DAfile.open(Filename, ios::in | ios::out | ios::binary);
	if (DAfile) {
		do {
			cout << "\n Enter Name: ";
			cin >> Records.name;
			cout << "\n Enter Emp_ID: ";
			cin >> Records.emp_id;
			cout << "\n Enter Salary: ";
			cin >> Records.salary;

			index = Records.emp_id % filesize;
			cout << "\n\t Index : " << index;
			cout << "\n\t size of Records" << sizeof(Records);

			offset = index * sizeof(Records);
			cout << offset;
			DAfile.seekg(offset, ios::beg);
			DAfile.read((char*) &R1, sizeof(R1));
			if (R1.emp_id == -1) {
				DAfile.seekp(offset, ios::beg);
				DAfile.write((char*) &Records, sizeof(Records));
				cout << "\n\t Successful in first attempt";
				break;
			}
			else{ //go for linear probing
				hash2 = R1.emp_id % filesize;
				i = index + 1;
				while (i != index) {
					DAfile.seekg(i * sizeof(R1), ios::beg);
					DAfile.read((char*) &R1, sizeof(R1));
					if (R1.emp_id == -1) {
						offset = i * sizeof(Records);
						DAfile.seekp(offset, ios::beg);
						DAfile.write((char*) &Records, sizeof(Records));
						cout
						<< "\n\t Record inserted  Successfully through linear probing !";
						flag = 1;
						break;
					} else
						i = i + 1 % 10;
				} // end of while
				if (flag == 1){	 //set the chain if collision is their
					j = index;
					if (hash2 == index) {
						do {
							DAfile.seekg(j * sizeof(R1), ios::beg);
							DAfile.read((char*) &R1, sizeof(R1));

							if (R1.chain == -1) {
								R1.chain = i;
								DAfile.seekp(j * sizeof(R1), ios::beg);
								DAfile.write((char*) &R1, sizeof(R1));
								flag1 = 1;
								break;
							}
							j = R1.chain;
						} while (1);
					} //if end
					else {
						j = index + 1;
						while (j != i) {
							DAfile.seekg(j * sizeof(R1), ios::beg);
							DAfile.read((char*) &R1, sizeof(R1));
							hash2 = R1.emp_id % 10;
							if (hash2 == index) {
								if (R1.chain == -1) {

									R1.chain = i;
									DAfile.seekp(j * sizeof(R1), ios::beg);
									DAfile.write((char*) &R1, sizeof(R1));
									flag1 = 1;
									break;
								}
							}
							j = (j + 1) % 10;
						}
					}
				}
				// }//end while
				if (i == index) {
					cout << "\n\t File is FULL ";
					break;
				}
			} //end else
			cout << "\nDo you want to add more records?";
			cin >> ch;
		} while (ch == 'y');
		DAfile.close();
	} else
		cout << "\n\t Unable to create a file";
}
void DAFAdt::Display(int flag) {

	int n, i, j;
	DAfile.open(Filename, ios::in | ios::binary);

	if (DAfile) {
		DAfile.seekg(0, ios::beg);
		cout << "\n The Contents of file are ..." << endl;
		i = 0;
		cout << "\n\t Sr. No \t Emp _Id \t Name \ t Salary \n\t Chain \n\t";

		while (DAfile.read((char *) &Records, sizeof(Records))) {
			//DAfile.seekg(i,ios::beg);//seeking record of that pos from seq.file
			//reading record
			// if(flag!=0)
			// {
			//if(Records.emp_id!=-1)///if rec. is not deleted logically
			{		    //then display it
				cout << " \n\t" << i << "\t " << Records.name << "\t"
						<< Records.emp_id << "\t" << Records.salary << "\t"
						<< Records.chain;

			}

			i++;
		}
	} else
		cout << "\n\t unable to open a file";

	DAfile.close();
}

void DAFAdt::Search() {
	Rec R1;
	int key, index, offset, i;
	DAfile.open(Filename, ios::in | ios::binary);
	cout << "\n\t Enter the  Emp ID to be searched  !!";
	cin >> key;

	index = key % filesize;
	cout << "\n\t Index : " << index;
	cout << "\n\t size of Records" << sizeof(Records);
	offset = index * sizeof(Records);
	cout << offset;

	if (DAfile) {
		cout << "\n\t if block ";
		DAfile.seekg(offset, ios::beg);
		DAfile.read((char*) &R1, sizeof(R1));

		if (R1.emp_id == key) // checking key with records emp id
		{
			cout << "\n\t  Record  found successfully at  " << index
					<< "in the first attempt";

		} else {
			cout << "\n\t Start linear probing  ....";
			i = index + 1;

			while (i != index) {
				DAfile.read((char*) &R1, sizeof(R1));
				if (R1.emp_id == key) {
					cout << "\n\t Record found  through  Linear probing at  "
							<< i << "location ";
					break;
				} //end if
				i++;
				cout << "\n\t I :: " << i;
				if (i == 9)
					DAfile.seekg(0, ios::beg);

			} //end while
			if (i == index) {
				cout << "\n\t Record with" << key
						<< "is not present in the file !!  ";

			}
		} //end else
		DAfile.close();
	} // end if

	else
		cout << "\n\t Unable to open a file !!";

}
