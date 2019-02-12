/*
 * graph.h
 *
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
	bool accept;
	bool validate();
}dob;

class Frand{
	char name[MAX];
	int noc;
public:
	Frand();
	Frand(char name[],int noc);
	friend User;
	friend FB;
};

class User{
	Date dob;
	char name[MAX];
	SLL<Frand> friendlist;
public:
	User();
	User(Date dob, char name[]);
	friend FB;
};

class FB{
	SLL<User> userlist;
public:
	bool search(char name[]);
	bool create_ulist(int n);
};

#endif /* GRAPH_H_ */
