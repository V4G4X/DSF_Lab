/*
 * LLADT.h
 *  Created on: 08-Jan-2019
 *      Author: v4g4x
 */
#ifndef LLADT_H_
#define LLADT_H_

template<class T>
class SLL;

template<class T>
class Node{
private:
	T data;
	Node* next;
public:
	Node(T data);
	friend SLL<T>;
};

template<class T>
class SLL{
private:
	Node<T>* head;
	int len;
	Node<T>* getnode(T data);
public:
	SLL();
	int length();
	bool create(int i);
	bool isEmpty();
	void print();
	T getdata(int i);
	bool insert(T data, int ch);
	bool dlete(int ch);
};

#endif /* LLADT_H_ */
