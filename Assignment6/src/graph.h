/*
 * graph.h
 *  Created on: 12-Feb-2019
 *      Author: v4g4x
 */
#ifndef GRAPH_H_
#define GRAPH_H_
#define MAX 50
//#include "LLADT.h"

class Frand;
class User;
class FB;

typedef struct Date{
	int dd,mm,yy;
	bool accept(int dd,int mm,int yy);
//	bool validate();
}Date;

class Frand{
	User* fr;
	int noc;
	Frand* link;
public:
	Frand();
	Frand(User* fr,int com);
	friend User;
	friend FB;
	void printFriends();
};

class User{
	Date dob;
	char *name;
	char *uid;
	User* nlink;
	Frand* dlink;
	char* generateID();
	bool friendExists(char *name);
public:
	User();
	User(Date dob, char name[]);
	bool addFriend(User* dost,int noc);
	friend Frand;
	friend FB;
};

class FB{
	int len;			//Stores length of list;
	User* userlist;
	int getIndex(User* node);
public:
	void printList();
	User* search(char name[]);
	bool create_ulist(int n);
	bool create_friendlist();
	void maxminComments(int &less0, char* &least0 , int &large0 , char* &largest0);
	char* maxFriend(int &max);
	void birthdayMonth(int m);
	friend User;
};

#endif /* GRAPH_H_ */
