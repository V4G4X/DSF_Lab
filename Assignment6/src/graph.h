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
	int noc;
	User* link;
public:
	Frand();
	Frand(char name[],int noc);
	friend User;
	friend FB;
};

class User{
	Date dob;
	char *name;
	SLL<Frand> friendlist;
	char *uid;
	char* generateID();
public:
	User();
	User(Date dob, char name[]);
	bool create_friendlist(int n);
	friend Frand;
	friend FB;
};

class FB{
	SLL<User*> userlist;
public:
	bool search(char name[]);
	bool create_ulist(int n);
	friend User;
};

#endif /* GRAPH_H_ */
