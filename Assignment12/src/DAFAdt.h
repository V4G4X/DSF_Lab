/*
 * DAFAdt.h
 */
#include<fstream>
#include<iostream>
#ifndef DAFADT_H_
#define DAFADT_H_
using namespace std;

typedef struct EMPLOYEE {
	char name[10];
	int emp_id;
	int salary;
	int chain;
} Rec;

class DAFAdt {
	Rec Records;
	int filesize;
	fstream DAfile;
	char Filename[30];
public:
	DAFAdt();
	void Create();
	void Display(int);
	void Update();
	void Delete();
	void Append();
	void Search();
	void init();
	int update_chain(int, int, int);
};

#endif /* DAFADT_H_ */
