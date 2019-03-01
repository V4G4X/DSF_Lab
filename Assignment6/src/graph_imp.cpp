/*
 * graph_imp.cpp
 *  Created on: 15-Feb-2019
 *      Author: v4g4x
 */

#include <iostream>
#include <ctime>
#include <string.h>
#include "graph.h"
#include "LLADT.h"
#include "LL_IMP.cpp"
using namespace std;

#define MAX 50

bool Date::accept(int dd,int mm,int yy){
	this->dd = dd;
	this->mm = mm;
	this->yy = yy;
	return 1;
}

bool FB::create_ulist(int n){
	int i;
	for(i=0 ; i<n ; i++){
		char name[MAX];
		Date dob;
		cout<<"User No: "<<i+1<<"\nEnter Name: ";
		cin.getline(name,MAX);
		int dd,mm,yy;
		{
			cout<<"Enter Date of Birth in DD MM YY, Separate by Spaces"<<endl;
			cin>>dd;
			cin>>mm;
			cin>>yy;
			cin.ignore();
		}
		dob.accept(dd,mm,yy);
		User *u = new User(dob,name);
				userlist.insert(u,userlist.length()+1);
	}
	return 0;
}

User::User() {
	name = NULL;
	uid = NULL;
}

User::User(Date dob, char name[]){
	this->dob = dob;
	this->name = name;
	generateID();
}

char* User::generateID(){
	{
		time_t now = time(0);
		uid = ctime(&now);
		strcat(name,uid);
	}
	return uid;
}

bool User::create_friendlist(int n){
	int i;
		for(i=0 ; i < n ; i++){
			int j;
			for(j=0 ; i < i ; j++){
			}
		}
}
