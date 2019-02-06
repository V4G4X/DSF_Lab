#include <iostream>
#include "LLADT.h"
#include "LL_IMP.cpp"
#include "PQ_ADT.h"
using namespace std;

template<class T>
PQueue<T>::PQueue(){
	f=0;fm=0;fl=0;r=0;
}

template<class T>
bool PQueue<T>::isEmpty(){
	if(ll.isEmpty())
		return 1;
	else return 0;
}

template<class T>
void PQueue<T>::add(T data){
	ll.insert(data,r);
	r++;
}

template<class T>
void PQueue<T>::addM(T data){
	ll.insert(data,fl);
	fl++;
	r++;
}

template<class T>
void PQueue<T>::addH(T data){
	ll.insert(data,fm);
	fm++;
	fl++;
	r++;
}

template<class T>
T PQueue<T>::serve(){
	T data = ll.getdata(0);
	ll.dlete(0);
	if(fm!=0) fm--;
	if(fl!=0) fl--;
	r--;
	return data;
}
