/*
 * graph.h
 *  Created on: 12-Feb-2019
 *      Author: v4g4x
 */
#ifndef GRAPH_H_
#define GRAPH_H_
#define MAX 50
#include "LLADT.h"

class Frand;
class User;
class FB;

typedef struct Date{
	int dd,mm,yy;
	bool accept(int dd,int mm,int yy);
	bool validate();
}Date;

class Frand{
	User* fr;
	int noc;
	User* link;
public:
	Frand();
	Frand(User* fr,int com);
	friend User;
	friend FB;
};

class User{
	Date dob;
	char *name;
	char *uid;
	User* nlink;
	Frand* dlink;
	char* generateID();
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
public:
	User* search(char name[]);
	bool create_ulist(int n);
	bool create_friendlist();
	friend User;
};

#endif /* GRAPH_H_ */
