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
	User* temp = userlist;
	len=n;
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
		temp->nlink = u;
		temp=temp->nlink;
	}
	return 0;
}

Frand::Frand(){
	fr=NULL;
	noc=0;
	link=NULL;
}

Frand::Frand(User* fr, int noc){
	this->fr = fr;
	this->noc = noc;
	link = NULL;
}

User::User(){
	name = NULL;
	generateID();
	nlink = NULL;
	dlink = NULL;
}

User::User(Date dob, char name[]){
	this->dob = dob;
	this->name = name;
	generateID();
	nlink = NULL;
	dlink = NULL;
}

char* User::generateID(){
	{
		time_t now = time(0);
		uid = ctime(&now);
		strcat(name,uid);
	}
	return uid;
}

bool User::addFriend(User* dost,int noc){
	//If A.addFriend(B,5) this will add B in A's friend list and 5 is no. of comments by B on A
	Frand* temp = dlink;
	while(temp->link){
		if(strcasecmp(temp->fr->name,dost->name)==0)
			return 1;
		temp=temp->link;
	}
	//Now temp is last adjacent node
	temp->link = new Frand(dost,noc);
	return 0;
}

User* FB::search(char name[]){
	User* temp = userlist;
	while(temp)
		if(strcasecmp(name,temp->name)==0)
			return temp;
	return NULL;
}

bool FB::create_friendlist(){
	int i,j;
	User* temp = userlist;
	int c;
	if(userlist==NULL)	return 1;
	for(i=0 ; i < len ; i++){				//Traverses to each user
		cout<<"Enter No. of Friends of "<<temp->name<<": ";
		cin>>c;
		for(j=0 ; j<c ; j++){
			cout<<"Enter name of friend "<<(j+1)<<": ";
			char naam[MAX];
			cin.getline(naam,MAX);
			User* dost = search(naam);
			int a,b;
			//a -> No. of comments by dost on temp;
			//b -> No. of comments by temp on dost;

		}
	}
	return 0;
}
