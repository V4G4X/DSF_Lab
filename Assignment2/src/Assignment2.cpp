//=============================================================
// Name        : Priority_Queue.cpp
// Author      : Varun Gawande
// Copyright   : Your copyright notice
// Description : Hospital Priority Queue in C++, Ansi-style
//=============================================================
/*Disease List
High Priority:
	1. Accident
	2. Hemorrhage(Internal Bleeding)
	3. Heart Disease
	4. Quarantine Scenario
	5. LoveSick
Medium Priority:
	6. Cancer
	7. Diabetes
Low Priority
	8. Cold
	9. Viral
	10.First CheckUp
 */

#include<iostream>
#include<iomanip>
#include<string.h>
#include"PQ_ADT.h"
#include"PQ_IMP.cpp"
using namespace std;

class Patient{
	char name[50];
	int  age;
	char address[50];
	char diseaselist[11][50] = {"1. Accident","2. Hemorrhage","3. Heart Disease","4. Quarantine Scenario","5. LoveSick","6. Cancer","7. Diabetes","8. Cold","9. Viral","10.First CheckUp"};
	int disease;
	char priority;
	static int count;
	char uid[50];
public:
	void accept(){
		cout<<"Enter Patient Name: ";
		cin.getline(name,50);
		strcpy(uid,name);
		char temp[50] = to_string(count);
		strcat(uid,temp);
		count++;
		cout<<"Enter Patient Age: ";
		cin>>age;
		cin.ignore();
		cout<<"Enter Patient Address: ";
		cin.getline(address,50);
		cout<<"\nHigh Priority:\n1. Accident\n2. Hemorrhage(Internal Bleeding)\n3. Heart Disease\n4. Quarantine Scenario\n5. LoveSick\nMedium Priority:\n6. Cancer\n7. Diabetes\nLow Priority\n8. Cold\n9. Viral\n10.First CheckUp"<<endl;
		do{
			cout<<"Enter Patient Disease: ";
			cin>>disease;
			if(disease>0 && disease<=5){
				priority = 'h';
				break;
			}
			else if(disease>5 && disease<=7){
				priority = 'm';
				break;
			}
			else if(disease>7 && disease<=10){
				break;
				priority = 'l';
			}
			else
				cout<<"Incorrect Choice\n";
		}while(1);
		cin.ignore();
	}

	void print(){
		cout<<"Patient Name: "<<name<<endl;
		cout<<"Patient ID: "<<uid<<endl;
		cout<<"Patient Age: "<<age<<endl;
		cout<<"Patient Address: "<<address<<endl;
		cout<<"Patient Disease: "<<diseaselist[disease-1]<<endl;
	}

	//Getters for Required Data Members
	const char* getAddress() const { return address;	}

	int getAge() const {return age;	}

	int getDisease() const { return disease; }

	const char* getDiseaselist(int i) const { return diseaselist[i]; }

	const char* getName() const { return name; }

	const char* getUID() const { return uid; }

	char getPriority() const { return priority;	}
};

int Patient::count=19;

int main() {
	Patient p;
	PQueue<Patient> pq;
	cout<<"Welcome to the Hospital"<<endl;
	int ch;
	do{
		cout<<"Enter a choice\n1.Add Customer\n2.Serve Customer\n3.Display Queue\n4.Exit"<<endl;
		cin>>ch;
		cin.ignore();
		switch(ch){
		case 1:
			p.accept();
			switch (p.getPriority()){
			case 'h':
				pq.addH(p);
				break;
			case 'm':
				pq.addM(p);
				break;
			case 'l':
				pq.add(p);
				break;
			default:
				cout<<"Priority Data was tampered with"<<endl;
				break;
			}
			break;
			case 2:
				if(!pq.isEmpty()){
					p = pq.serve();
					p.print();
				}
				else
					cout<<"The Queue is Empty"<<endl;
				break;
			case 3:{
				int l;
				Patient* arr=pq.getVector(l);
				int i;
				cout<<"Name"<<setw(15)<<"UID"<<setw(15)<<"Age"<<setw(4)<<"Address"<<setw(20)<<"Disease"<<setw(15)<<endl;
				for(i=0 ; i<l ; i++)
					cout<<arr[i].getName()<<setw(15)<<arr[i].getUID()<<setw(15)<<arr[i].getAge()<<setw(4)<<arr[i].getAddress()<<setw(20)<<arr[i].getDiseaselist(arr[i].getDisease()-1)<<setw(15)<<endl;
				break;
			}
			case 4:
				cout<<"Exiting Hospital Program"<<endl;
				break;
			default:
				cout<<"Enter proper choices"<<endl;
				break;
		}
	}while(ch!=4);
	return 0;
}
////////////////////END///////////////////
/*
Welcome to the Hospital
Enter a choice
1.Add Customer
2.Serve Customer
3.Display Queue
4.Exit
1
Enter Patient Name: Varun
Enter Patient Age: 19
Enter Patient Address: KandaWalah

High Priority:
1. Accident
2. Hemorrhage(Internal Bleeding)
3. Heart Disease
4. Quarantine Scenario
5. LoveSick
Medium Priority:
6. Cancer
7. Diabetes
Low Priority
8. Cold
9. Viral
10.First CheckUp
Enter Patient Disease: 9
Enter a choice
1.Add Customer
2.Serve Customer
3.Display Queue
4.Exit
1
Enter Patient Name: Jash
Enter Patient Age: 20
Enter Patient Address: Handi

High Priority:
1. Accident
2. Hemorrhage(Internal Bleeding)
3. Heart Disease
4. Quarantine Scenario
5. LoveSick
Medium Priority:
6. Cancer
7. Diabetes
Low Priority
8. Cold
9. Viral
10.First CheckUp
Enter Patient Disease: 7
Enter a choice
1.Add Customer
2.Serve Customer
3.Display Queue
4.Exit
1
Enter Patient Name: Sam
Enter Patient Age: 20
Enter Patient Address: Mananana

High Priority:
1. Accident
2. Hemorrhage(Internal Bleeding)
3. Heart Disease
4. Quarantine Scenario
5. LoveSick
Medium Priority:
6. Cancer
7. Diabetes
Low Priority
8. Cold
9. Viral
10.First CheckUp
Enter Patient Disease: 3
Enter a choice
1.Add Customer
2.Serve Customer
3.Display Queue
4.Exit
3
Name            Age		Address             Disease
Sam         	20		Mananana			4. Quarantine Scenario
Jash            20		Handi             	8. Cold
Varun           19		KandaWalah    		10.First CheckUp
Enter a choice
1.Add Customer
2.Serve Customer
3.Display Queue
4.Exit
2
Patient Name: Sam
Patient Age: 20
Patient Address: Mananana
Patient Disease: 3. Heart Disease
Enter a choice
1.Add Customer
2.Serve Customer
3.Display Queue
4.Exit
2
Patient Name: Jash
Patient Age: 20
Patient Address: Handi
Patient Disease: 7. Diabetes
Enter a choice
1.Add Customer
2.Serve Customer
3.Display Queue
4.Exit
2
Patient Name: Varun
Patient Age: 19
Patient Address: KandaWalah
Patient Disease: 9. Viral
Enter a choice
1.Add Customer
2.Serve Customer
3.Display Queue
4.Exit
2
The Queue is Empty
Enter a choice
1.Add Customer
2.Serve Customer
3.Display Queue
4.Exit
4
Exiting Hospital Program

 * */
