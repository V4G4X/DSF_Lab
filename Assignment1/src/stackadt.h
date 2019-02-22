/*
 * stackadt.h
 *  Created on: Jan 10, 2019
 */


#include "linked.h"


#ifndef STACKADT_H_
#define STACKADT_H_

template<class T>
class stackadt {
	linked<T> L;
public:
	stackadt();
	bool isempty();
	void push(T x);
	T pop();
	T peep();
	virtual ~stackadt();
};

#endif /* STACK_H_ */




