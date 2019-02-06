//============================================================================
// Name        : Priority_Queue.cpp
// Author      : Varun Gawande
// Copyright   : Your copyright notice
// Description : Hospital Priority Queue in C++, Ansi-style
//============================================================================
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

#include <iostream>
#include "PQ_ADT.h"
#include "PQ_IMP.cpp"
using namespace std;

class Patient{
	char name[50];
	int  age;
	char address[50];
	char diseaselist[11][50] = {"1. Accident","2. Hemorrhage","3. Heart Disease","4. Quarantine Scenario","5. LoveSick","6. Cancer","7. Diabetes","8. Cold","9. Viral","10.First CheckUp"};
	int disease;
	char priority;
public:
	void accept(){
		cout<<"Enter Patient Name: ";
		cin.getline(name,50);
		cout<<"Enter Patient Age: ";
		cin>>age;
		cin.ignore();
		cout<<"Enter Patient Address: ";
		cin.getline(address,50);
		cout<<"\nHigh Priority:\n1. Accident\n2. Hemorrhage(Internal Bleeding)\n3. Heart Disease\n4. Quarantine Scenario\n5. LoveSick\nMedium Priority:\n6. Cancer\n7. Diabetes\nLow Priority\n8. Cold\n9. Viral\n10.First CheckUp"<<endl;
		do{
			cout<<"Enter Patient Disease: ";
			cin>>disease;
			if(disease>0 && disease<=5)
				priority = 'h';
			else if(disease>5 && disease<=7)
				priority = 'm';
			else if(disease>8 && disease<=10)
				priority = 'l';
			else{
				cout<<"Incorrect Choice\n";
				continue;
			}
		}while(0);
		cin.ignore();
	}

	void print(){
		cout<<"Patient Name: "<<name<<endl;
		cout<<"Patient Age: "<<age<<endl;
		cout<<"Patient Address: "<<address<<endl;
		//		cout<<"Patient Disease: "<<disease<<endl;
		cout<<"Patient Disease: "<<diseaselist[disease-1]<<endl;
	}

	char getPriority(){
		return priority;
	}
};

int main() {
	Patient p;
	PQueue<Patient> pq;
	cout<<"Welcome to the Hospital"<<endl;
	int ch;
	do{
		cout<<"Enter a choice\n1.Add Customer\n2.Serve Customer\n3.Exit"<<endl;
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
			case 3:
				cout<<"Exiting Hospital Program"<<endl;
				break;
			default:
				cout<<"Enter proper choices"<<endl;
				break;
		}
	}while(ch!=3);
	return 0;
}