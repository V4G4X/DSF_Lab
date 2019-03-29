/*
 * Hash.h
 *
 *  Created on: 19-Mar-2019
 *      Author: v4g4x
 */

#ifndef HASH_H_
#define HASH_H_

#include <iostream>

typedef struct Record{
	long int phoneNo = 999;
	char name[50] = "#########";
	int rollNo = 111;
	int chain = -2;
}Record;

class Hash{
private:
	int rec=0;
	int len = 10;
	Record* hTable = new Record[len];
	bool isFull();
	bool isEmpty();
public:
	void printTable();
	void insert();
	void insertReplace();
	Record search(long int phoneNo);
	void dlete(long int phoneNo);
	void dleteReplace(long int phoneNo);
};

#endif /* HASH_H_ */
