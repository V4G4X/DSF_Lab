/*
 * graph_imp.cpp
 *  Created on: 15-Feb-2019
 *      Author: v4g4x
 */

#include <iostream>
#include <ctime>
#include <string.h>
#include "graph.h"
#include <stack>
#include <queue>
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
		if(i==0){ userlist = u;
		temp = userlist;
		}
		else{
			temp->nlink = u;
			temp=temp->nlink;
		}
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
	time_t now = time(0);
	uid = ctime(&now);
	strcat(uid,name);
	return uid;
}

bool User::addFriend(User* dost,int noc){
	//If "User:.addFriend("Dost",noc) this will add Dost in User's friend list and noc is no. of comments by dost on User
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

int FB::getIndex(User* node){
	User* temp = userlist;
	int i;
	while(temp){
		if(node==temp)
			return i;
		i++;
		temp=temp->nlink;
	}
	return -1;
}

User* FB::search(char name[]){
	User* temp = userlist;
	while(temp){
		if(strcasecmp(name,temp->name)==0)
			return temp;
		temp=temp->nlink;
	}
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
			if(dost==NULL){
				cout<<"The entered User does not exist, moving on to Next"<<endl;
				continue;
			}
			int a,b;
			//a -> No. of comments by dost on temp;
			//b -> No. of comments by temp on dost;
			cout<<"No. of comments by "<<dost->name<<" on "<<temp->name<<": ";
			cin>>a;
			cout<<"No. of comments by "<<temp->name<<" on "<<dost->name<<": ";
			cin>>b;
			cin.ignore();
			dost->addFriend(temp,b);
			temp->addFriend(dost,a);
		}
	}
	return 0;
}

bool node_unvisited(bool *arr,int len){
	for(int i=0 ; i< len ;i++){
		if(arr[i]==0)
			return 1;
	}
	return 0;
}

void FB::maxminComments(int &less0, char* least0 , int &large0 , char* largest0){		//Implements DFS
	stack<User*> st;
	User* temp = userlist;
	int *count = new int[len];
	bool *visit = new bool[len];
	st.push(temp);
	while(node_unvisited(visit,len)){
		User *temp2 = st.top();
		st.pop();
		int v = getIndex(temp2);
		if(visit[v]==1)	continue;
		visit[v] = 1;
		Frand* temp3 = temp2->dlink;
		while(temp3){
			st.push(temp3->fr);
			int index = getIndex(temp3->fr);
			count[index]+=temp3->noc;
			temp3=temp3->link;
		}
	}
	int large=count[0];
	int less=count[0];
	temp=userlist;
	User* largest=temp;
	User* least=temp;
	for(int i=0 ; i<len ; i++){
		if(large<count[i]){
			large = count[i];
			largest = temp;
		}
		if(less>count[i]){
			less = count[i];
			least = temp;
		}
		temp=temp->nlink;
	}
	cout<<largest->name<<" has most comments with "<<large<<" no. of comments"<<endl;
	cout<<least->name<<" has least comments with "<<less<<" no. of comments"<<endl;\
	less0=less;		strcpy(least0,least->name);
	large0=large;	strcpy(largest0,largest->name);
}

char* FB::maxFriend(int &max){															//Implements BFS
	User* temp = userlist;
	bool *visit = new bool[len];
	char *name = new char[MAX];
	queue<User*> q;
	q.push(temp);
	while(!q.empty()){
		temp=q.front();
		q.pop();
		Frand* temp2 = temp->dlink;
		int count=0;
		while(temp2){
			count++;
			if(visit[getIndex(temp2->fr)]==0)
				q.push(temp2->fr);
			temp2=temp2->link;
		}
		if(max<count){
			max = count;
			name = strcpy(name,temp->name);
		}
	}
	return name;
	/*	int* count = new int[len];
	for(int i=0 ; i< len ; i++){
		Frand* temp2 = temp->dlink;
		while(temp2){
			count[i]++;
			temp2=temp2->link;
		}
		temp=temp->nlink;
	}
	temp=userlist;
	max = count[0];
	for(int i=0 ; i<len ; i++){
		if(max<count[i]){
			max = count[i];
			most = temp;
		}
		temp=temp->nlink;
	}*/
}

void FB::birthdayMonth(int m){
	User* temp = userlist;
	bool flag=0;
	for(int i=0 ; i<len ; i++){
		if(m==temp->dob.mm){
			cout<<temp->name<<" has Birthday This month\n";
			flag=1;
		}
		temp=temp->nlink;
	}
	if(!flag)
		cout<<"There were no Birthdays this month\n";
}
