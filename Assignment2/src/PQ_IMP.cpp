#include <iostream>
#include "LLADT.h"
#include "LL_IMP.cpp"
#include "PQ_ADT.h"
using namespace std;
//Functions of Class PQueue
//Default Constructor
template<class T>
PQueue<T>::PQueue(){
	f=0;fm=0;fl=0;r=0;
}

//Returns 1(TRUE) if Empty
template<class T>
bool PQueue<T>::isEmpty(){
	if(ll.isEmpty())
		return 1;
	else return 0;
}

//Returns the entire contents of PQueue in form Array
template<class T>
T* PQueue<T>::getVector(int& i){
	T* array = new T[ll.length()];
	for(i=0 ; i<ll.length() ; i++)
		array[i] = ll.getdata(i);
	return array;
}

//Adds given Data to Queue in low Priority
template<class T>
void PQueue<T>::add(T data){
	ll.insert(data,r);
	r++;
}

//Adds given Data to Queue in Medium Priority
template<class T>
void PQueue<T>::addM(T data){
	ll.insert(data,fl);
	fl++;
	r++;
}

//Adds given Data to Queue in High Priority
template<class T>
void PQueue<T>::addH(T data){
	ll.insert(data,fm);
	fm++;
	fl++;
	r++;
}

//Dequeue Function
template<class T>
T PQueue<T>::serve(){
	T data = ll.getdata(0);
	ll.dlete(0);
	if(fm!=0) fm--;
	if(fl!=0) fl--;
	r--;
	return data;
}
