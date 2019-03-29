/*
 * HashReplacement.h
 *
 *  Created on: 29-Mar-2019
 *      Author: v4g4x
 */

#ifndef HASHNONREP_H_
#define HASHNONREP_H_

typedef struct RecordNR{
	long int phoneNo = 999;
	char name[50] = "#########";
	int rollNo = 111;
	int chain = -2;
}RecordNR;

class HashNR{
private:
	int rec=0;
	int len = 10;
	RecordNR* hTable = new RecordNR[len];
	bool isFull();
	bool isEmpty();
public:
	void printTable();
	void insert();
	RecordNR search(long int phoneNo);
	void dlete(long int phoneNo);
};



#endif /* HASHNONREP_H_ */
