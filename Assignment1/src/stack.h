/*
 * stack.h
 */
#include "linked.h"
#ifndef STACK_H_
#define STACK_H_

template <class T>
class stack {
	linked <T> l;
public:
	stack();
	 ~stack();
	void push(T x);
	T peep();
	T pop();
	T isempty();
};
#endif /* STACK_H_ */
