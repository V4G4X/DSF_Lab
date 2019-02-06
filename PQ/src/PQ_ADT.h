/*
 * PQ_ADT.h
 *
 *  Created on: 15-Jan-2019
 *      Author: v4g4x
 */

#ifndef PQ_ADT_H_
#define PQ_ADT_H_
#include "LLADT.h"

template<class T>
class PQueue{							//3 Level Priority - High, Medium, Low
private:
	SLL<T> ll;
	int f,fm,fl,r;
public:
	PQueue();
	bool isEmpty();
	void add(T data);
	void addM(T data);
	void addH(T data);
	T serve();
};


#endif /* PQ_ADT_H_ */
