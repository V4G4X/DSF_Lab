/*
 * STACKLL.h
 *
 *  Created on: 07-Feb-2019
 *      Author: v4g4x
 */

#ifndef STACKLL_H_
#define STACKLL_H_
#include "LLADT.h"

template<class T>
class Stack {
private:
	SLL<T> ll;
public:
	Stack();
	Stack(T data);
	bool IsEmpty();
	void push(T data);
	T pop();
	T peek();
};



#endif /* STACKLL_H_ */
