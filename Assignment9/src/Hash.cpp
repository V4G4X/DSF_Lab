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

void Hash::printTable(){
	cout<<"\tName\t\tRoll no\t\tPhone No\t\tchain\n";
	for(int i=0 ; i<len ; i++)
		cout<<(i)<<". "<<hTable[i].name<<"\t\t"<<hTable[i].rollNo<<"\t\t"<<hTable[i].phoneNo<<"\t\t"<<hTable[i].chain<<endl;
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
//	cout<<"Enter Name: ";
//	cin.getline(r.name,50);
//	cout<<"Enter Roll No.: ";
//	cin>>r.rollNo;
//	cin.ignore();
	r.chain=-1;

	int hKey= r.phoneNo%len;							//Calculate HashKey
	if(hTable[hKey].chain==-2)							//Enter Record as-is if location is Empty i.e Record doesn't exist
		hTable[hKey] = r;
	else if(hKey==hTable[hKey].phoneNo%len){			//If a record exists, AND if bucket matches
		while(hTable[hKey].chain!=-1)						//Move to end of chain of current bucket
			hKey = hTable[hKey].chain;
		int prev = hKey;									//Then store current index
		while(hTable[hKey].chain!=-2)						//Look for subsequent empty record
			hKey = (hKey+1)%len;
		hTable[hKey] = r;									//Store our record in It
		hTable[prev].chain = hKey;							//Let the previous record know where the next one is
	}
	else{												//If a Record exists BUT Bucket doesn't match
		while(hTable[hKey].chain!=-2 && (hTable[hKey].phoneNo%len!=r.phoneNo%len))//Probe forward to look for empty record OR chain beginning
			hKey = (hKey+1)%len;
		if(hTable[hKey].phoneNo%len==r.phoneNo%len){		//Found Beginning of chain
			while(hTable[hKey].chain!=-1)					//Move till end of chain
				hKey = hTable[hKey].chain;
			int prev = hKey;								//Then store current index
			while(hTable[hKey].chain!=-2)					//Look for subsequent empty record
				hKey = (hKey+1)%len;
			hTable[hKey] = r;								//Store our record in It
			hTable[prev].chain = hKey;						//Let the previous record know where the next one is
		}
		hTable[hKey] = r;									//Store our record in It
	}
	rec++;												//Increment record count by 1
}

void Hash::insertReplace(){
	if(isFull()){
		cout<<"Hash Table is Full"<<endl;
		return;
	}
	Record r;								//Enter Data
	cout<<"Enter Phone Number: ";
	cin>>r.phoneNo;
//	cin.ignore();
//	cout<<"Enter Name: ";
//	cin.getline(r.name,50);
//	cout<<"Enter Roll No.: ";
//	cin>>r.rollNo;
	cin.ignore();
	r.chain=-1;

	int hKey = r.phoneNo%len;
	if(hTable[hKey].chain!=-2){						//A record already exists
		if(hKey == hTable[hKey].phoneNo%len){			//Record is part of same bucket
			while(hTable[hKey].chain!=-1)					//Move till end of bucket's chain
				hKey = hTable[hKey].chain;
			int prev = hKey;
			while(hTable[hKey].chain!=-2)					//Probe for an empty record
				hKey = (hKey+1)%len;
			hTable[hKey] = r;								//Add record there
			hTable[prev].chain = hKey;
		}
		else{											//Records are of different buckets
			Record temp = hTable[hKey];
			int newKey = temp.phoneNo%len;
			while(hTable[hTable[newKey].chain].phoneNo!=temp.phoneNo)	//Traverse till newKey is index of just before the node to be moved
				newKey = hTable[newKey].chain;
			int prev = newKey;
			while(hTable[newKey].chain!=-2)					//Probe for an empty record
				newKey = (newKey+1)%len;
			hTable[newKey] = temp;							//Copy record to new empty place
			hTable[prev].chain = newKey;					//Let previous node of chain know of new location
			hTable[hKey] = r;
		}
	}
	else{											//Empty Record available
		hTable[hKey] = r;								//Add record there
	}
	rec++;
}

Record Hash::search(long int phoneNo){
	Record r ;
	int hKey = phoneNo%len;						//Find HashKey of required record
	r=hTable[hKey];
	while(r.phoneNo!=phoneNo){
		if(r.chain==-1 || r.chain==-2)			//If chain ends and Record not found, return a blank one
			return *(new Record);
		hKey = r.chain;							//Move to next kink of Chain
		r=hTable[hKey];
	}
	return r;
}

void Hash::dlete(long int phoneNo){
	if(isEmpty()){
		cout<<"Hash Table is Empty"<<endl;
		return;
	}

}

void Hash::dleteReplace(long int phoneNo){
	if(isEmpty()){
		cout<<"Hash Table is Empty"<<endl;
		return;
	}
	int prev=-1;
	int hKey = phoneNo%len;							//Find hashKey of record to be deleted
	while(hTable[hKey].phoneNo!=phoneNo){
		if(hTable[hKey].chain==-1 || hTable[hKey].chain==-2)//if chain ends without kink found, it's absent
			return;
		prev = hKey;
		hKey = hTable[hKey].chain;					//Move to next kink in chain
	}
	if(prev!=-1)							//The node to be deleted is not at the beginning
		hTable[prev].chain = hTable[hKey].chain;
	hTable[hKey] = *(new Record);
	rec--;									//Decrement record count by 1
}


