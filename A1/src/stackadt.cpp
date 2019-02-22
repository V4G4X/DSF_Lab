/*
 * stackadt.cpp
 *
 *  Created on: Jan 10, 2019
 */


#include "stackadt.h"
#include "linked.h"
#include <iostream>
using namespace std;

template<class T>
stackadt<T>::stackadt() {

}

template<class T>
bool stackadt<T>::isempty() {
	if(L.empty()==true)
		return true;
	return false;
}

template<class T>
void stackadt<T>::push(T value) {
	L.insert_first(value);
}

template<class T>
T stackadt<T>::pop() {
	return (L.delete_first());
}

template<class T>
T stackadt<T>::peep() {
	return (L.show_head());
}

template<class T>
stackadt<T>::~stackadt() {

}

