/*
 * Hash.cpp
 *
 *  Created on: 19-Mar-2019
 *      Author: v4g4x
 */

#include <iostream>
#include "Hash.h"
using namespace std;

bool Hash::isEmpty(){
	if(rec==0) return 1;
	else return 0;
}

bool Hash::isFull(){
	if(rec==len) return 1;
	else return 0;
}

void Hash::insert(){
	if(isFull()){
		cout<<"Hash Table is Full"<<endl;
		return;
	}
	Record r;								//Enter Data
	cout<<"Enter Phone Number: ";
	cin>>r.phoneNo;
	cin.ignore();
	cout<<"Enter Name: ";
	cin.getline(r.name,50);
	cout<<"Enter Roll No.: ";
	cin>>r.rollNo;
	cin.ignore();
	r.chain=-1;

	int hKey= r.phoneNo%len;				//Calculate HashKey
	if(hTable[hKey].chain==-2)				//Enter Record as-is if location is Empty
		hTable[hKey] = r;
	else if(hTable[hKey].chain==-1){		//If a record exists,
		int prev = hKey;					//Then store current index
		while(hTable[hKey].chain!=-2)		//Look for subsequent empty record
			hKey = (hKey+1)%len;
		hTable[hKey] = r;					//Store our record in It
		hTable[prev].chain = hKey;			//Let the previous record know where the next one is
	}
	rec++;									//Increment record count by 1
}

Record Hash::search(long int phoneNo){
	Record *r = NULL;
	int hKey = phoneNo%len;
	*r=hTable[hKey];
	while(r->phoneNo!=phoneNo){
		if(r->chain==-1 || r->chain==-2)
			return *(new Record);
		hKey = r->chain;
		*r=hTable[hKey];
	}
	return *r;
}

void Hash::dlete(long int phoneNo){
	if(isEmpty()){
		cout<<"Hash Table is Empty"<<endl;
		return;
	}
	int hKey = phoneNo%len;
	while(hTable[hKey].phoneNo!=phoneNo){
		if(hTable[hKey].chain==-1 || hTable[hKey].chain==-2)
			return;
		hKey = hTable[hKey].chain;
	}
	hTable[hKey] = *(new Record);
	rec--;									//Decrement record count by 1
}

void Hash::insertReplace(){
	if(isFull()){
			cout<<"Hash Table is Full"<<endl;
			return;
		}
		Record r;								//Enter Data
		cout<<"Enter Phone Number: ";
		cin>>r.phoneNo;
		cin.ignore();
		cout<<"Enter Name: ";
		cin.getline(r.name,50);
		cout<<"Enter Roll No.: ";
		cin>>r.rollNo;
		cin.ignore();
		r.chain=-1;
}
