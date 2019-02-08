//============================================================================
// Name        : STACKLL.cpp
// Author      : Varun Gawande
// Description : Implementation of STACKLL.h
//============================================================================

#include <iostream>
#include "STACKLL.h"
#include "LLADT.h"
#include "LL_IMP.cpp"
using namespace std;

template<class T>
Stack<T>::Stack(){
}

template<class T>
Stack<T>::Stack(T data){
	ll.insert(data,ll.length());
}

template<class T>
bool Stack<T>::IsEmpty(){
	if(ll.isEmpty())
		return true;
	else return false;
}

template<class T>
void Stack<T>::push(T data){
	ll.insert(data,ll.length());
}

template<class T>
T Stack<T>::peek(){
	return ll.getdata(ll.length());
}
template<class T>
T Stack<T>::pop(){
	T *temp = new T;
	*temp = peek();
	if(IsEmpty())
		return (T)NULL;
	ll.dlete(ll.length());
	return *temp;
}
