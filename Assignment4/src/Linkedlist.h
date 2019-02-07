/*
 * Linkedlist.h
 *
 *  Created on: 19-Dec-2018
 *      Author: f10
 */
#include<iostream>
using namespace std;
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


template<class T>
struct node1
{
	T data;
	struct node1<T> *next;
};

template<class T>
class Linkedlist
{
	node1<T> *head;
public:
	Linkedlist();
	node1<T> *getnode(T);
	void insert_first(T);
//	void insert_mid(T);
	void insert_end(T);
	T delete_first();
	char *display();
	T returnfirst();
	bool empty();
	~Linkedlist();
};
#endif /* LINKEDLIST_H_ */
