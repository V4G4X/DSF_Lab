/*
 * stack.h
 *
 *  Created on: 21-Dec-2018
 *      Author: f10
 */

#include "Linkedlist.cpp"
#ifndef STACK_H_
#define STACK_H_

template<class T>
class stack {
	Linkedlist<T> l;
public:
	stack();
	virtual ~stack();
	void push(T);
	T pop();
	T peep();
	char *display();
	bool isEmpty();
};

#endif /* STACK_H_ */
