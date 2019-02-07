/*
 * stack.cpp
 *
 *  Created on: 21-Dec-2018
 *      Author: f10
 */

#include "stack.h"
#include <iostream>
using namespace std;

template<class T>
stack<T>::stack() {
	// TODO Auto-generated constructor stub

}

template<class T>
stack<T>::~stack() {
	// TODO Auto-generated destructor stub
}

template<class T>
void stack<T>::push(T x){
	l.insert_first(x);
}


template<class T>
T stack<T>::pop(){
	return l.delete_first();
}

template<class T>
T stack<T>::peep(){
	return l.returnfirst();
}

template<class T>
bool stack<T>::isEmpty(){
	return l.empty();
}

template<class T>
char *stack<T>::display(){
	return l.display();
}
