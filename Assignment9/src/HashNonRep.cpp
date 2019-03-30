/*
 * HashNonRep.cpp
 *
 *  Created on: 29-Mar-2019
 *      Author: v4g4x
 */

#include <iostream>
#include "HashNonRep.h"
using namespace std;

bool HashNR::isEmpty(){
	if(rec==0) return 1;
	else return 0;
}

bool HashNR::isFull(){
	if(rec==len) return 1;
	else return 0;
}

void HashNR::printTable(){
	cout<<"\tName\t\tRoll no\t\tPhone No\t\tchain\n";
	for(int i=0 ; i<len ; i++)
		cout<<(i)<<". "<<hTable[i].name<<"\t\t"<<hTable[i].rollNo<<"\t\t"<<hTable[i].phoneNo<<"\t\t"<<hTable[i].chain<<endl;
}

void HashNR::insert(){
	if(isFull()){
		cout<<"Hash Table is Full"<<endl;
		return;
	}
	RecordNR r;								//Enter Data
	cout<<"Enter Phone Number: ";
	cin>>r.phoneNo;
	cin.ignore();
//	cout<<"Enter Name: ";
//	cin.getline(r.name,50);
//	cout<<"Enter Roll No.: ";
//	cin>>r.rollNo;
//	cin.ignore();
	r.chain=-1;

	int hKey= r.phoneNo%len;							//Calculate HashKey
	if(hTable[hKey].chain==-2)							//Enter RecordNR as-is if location is Empty i.e RecordNR doesn't exist
		hTable[hKey] = r;
	else if(hKey==hTable[hKey].phoneNo%len){			//If a RecordNR exists, AND if bucket matches
		while(hTable[hKey].chain!=-1)						//Move to end of chain of current bucket
			hKey = hTable[hKey].chain;
		int prev = hKey;									//Then store current index
		while(hTable[hKey].chain!=-2)						//Look for subsequent empty RecordNR
			hKey = (hKey+1)%len;
		hTable[hKey] = r;									//Store our RecordNR in It
		hTable[prev].chain = hKey;							//Let the previous RecordNR know where the next one is
	}
	else{												//If a RecordNR exists BUT Bucket doesn't match
		while(hTable[hKey].chain!=-2 && (hTable[hKey].phoneNo%len!=r.phoneNo%len))//Probe forward to look for empty RecordNR OR chain beginning
			hKey = (hKey+1)%len;
		if(hTable[hKey].phoneNo%len==r.phoneNo%len){		//Found Beginning of chain
			while(hTable[hKey].chain!=-1)					//Move till end of chain
				hKey = hTable[hKey].chain;
			int prev = hKey;								//Then store current index
			while(hTable[hKey].chain!=-2)					//Look for subsequent empty RecordNR
				hKey = (hKey+1)%len;
			hTable[hKey] = r;								//Store our RecordNR in It
			hTable[prev].chain = hKey;						//Let the previous RecordNR know where the next one is
		}
		hTable[hKey] = r;									//Store our RecordNR in It
	}
	rec++;												//Increment RecordNR count by 1
}

RecordNR HashNR::search(long int phoneNo){
	RecordNR r ;
	int prev = -1;
	int hKey = phoneNo%len;
	while((phoneNo%len)!=(hTable[hKey].phoneNo%len))	//Linearly Probe for matching bucket
		hKey++;
	//hKey is now at matching bucket, and beginning of chain
	while(hTable[hKey].phoneNo!=phoneNo){
		if(hTable[hKey].chain==-1 || hTable[hKey].chain==-2)//if chain ends without kink found, it's absent
			return *(new RecordNR);
		prev = hKey;
		hKey = hTable[hKey].chain;					//Move to next kink in chain
	}
	if(prev!=-1)							//The node to be deleted is not at the beginning
		hTable[prev].chain = hTable[hKey].chain;
	r = hTable[hKey];
	return r;
}

void HashNR::dlete(long int phoneNo){
	if(isEmpty()){
		cout<<"Hash Table is Empty"<<endl;
		return;
	}
	int prev = -1;
	int hKey = phoneNo%len;
	while((phoneNo%len)!=(hTable[hKey].phoneNo%len))	//Linearly Probe for matching bucket
		hKey++;
	//hKey is now at matching bucket, and beginning of chain
	while(hTable[hKey].phoneNo!=phoneNo){
		if(hTable[hKey].chain==-1 || hTable[hKey].chain==-2)//if chain ends without kink found, it's absent
			return;
		prev = hKey;
		hKey = hTable[hKey].chain;					//Move to next kink in chain
	}
	if(prev!=-1)							//The node to be deleted is not at the beginning
		hTable[prev].chain = hTable[hKey].chain;
	hTable[hKey] = *(new RecordNR);
	rec--;									//Decrement RecordNR count by 1
}




