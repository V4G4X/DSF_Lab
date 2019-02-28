#ifndef STACK_H_
#define STACK_H_

#include "linkedlist.h"
template <class T>
class stack {
	link <T> l1;
public:
	stack();
	void push(T x);
	T pop();
	bool isempty();
	T peep();
	virtual ~stack();
};

#endif /* STACK_H_ */
