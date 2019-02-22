/*
 * linked.h
 *
 *  Created on: Jan 10, 2019
 */

#ifndef LINKED_H_
#define LINKED_H_



template<typename T>
struct node{
	T data;
	struct node<T>* next;
};

template<class T>
class linked {
	node<T>* head;
public:
	linked();
	node<T> *getnode(T );
	void insert_first(T );
	T delete_first();
	T  show_head();
	void display();
	bool empty();
	virtual ~linked();
};


#endif /* LINKED_H_ */
