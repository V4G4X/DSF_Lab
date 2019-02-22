/*
 * linked.cpp
 *
 *  Created on: Jan 10, 2019
 */


#include "linked.h"
#include <iostream>
using namespace std;

template<class T>
linked<T>::linked() {
	head = NULL;
}
template<class T>
node<T>* linked<T>::getnode(T value) {
	node<T>*temp = new (node<T>);
	temp->data = value;
	temp->next = NULL;
	return (temp);
}
template<class T>
void linked<T>::insert_first(T value) {
	node<T>*temp = getnode(value);
	temp->next = head;
	head = temp;
}

template<class T>
T linked<T>::delete_first() {
	T x;
	node<T>*temp = head;
	x = head->data;
	head = head->next;
	delete temp;
	return x;
}

template<class T>
void linked<T>::display() {
	node<T>*temp = head;
	while(temp!=NULL){
		cout << temp->data <<"\n";
		temp = temp->next;
	}
}
template<class T>
T linked<T>::show_head() {
	T temp = head->data;
	return(temp);
}
template<class T>
bool linked<T>::empty() {
	if(head==NULL)
		return true;
	return false;
}
template<class T>
linked<T>::~linked() {
	delete head;
}


