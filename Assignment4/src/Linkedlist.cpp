/*
 * Linkedlist.cpp
 *
 *  Created on: 19-Dec-2018
 *      Author: f10
 */
#include<iostream>
#include "Linkedlist.h"
using namespace std;

//creates a new node1 which can be added anywhere
template<class T>
node1<T>* Linkedlist<T>::getnode(T  x){
	node1<T> *temp;
	temp = new node1<T>;
	temp->data=x;
	temp->next=NULL;
	return temp;
}

//constructor
template<class T>
Linkedlist<T>::Linkedlist() {
	head=NULL;
	// Auto-generated constructor stub
}

//destructor
template<class T>
Linkedlist<T>::~Linkedlist() {
	//  Auto-generated destructor stub
	delete head;
}

//creates new head node1
template<class T>
void Linkedlist<T>::insert_first(T x){
	node1<T> *temp=getnode(x);
	temp->next=head;
	head=temp;
}

//creates new node1 at the end
template<class T>
void Linkedlist<T>::insert_end(T x){
	node1<T> *temp=getnode(x);
	if(head==NULL){
		head=getnode(x);
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp=getnode(x);
	}
}

//delete first node1
template<class T>
T Linkedlist<T>::delete_first(){
	node1<T> *temp=NULL;
	T m;
	if(head!=NULL){
		temp=head;
		m=head->data;
		head=head->next;
		delete temp;
	}
	return m;
}

//display all list
template<class T>
char *Linkedlist<T>::display(){
	node1<T> *temp=head;
	char *c=new char[20];
	int i=0;
	while(temp!=NULL){
		*(c+i)=temp->data->data;
		temp=temp->next;
		i++;
	}
	c[i]='\0';
	return c;
}

//return head
template<class T>
T Linkedlist<T>::returnfirst(){
	if(head!=NULL)
		return head->data;
}

//check whether list is empty or not
template<class T>
bool Linkedlist<T>::empty(){
	if(head==NULL)
		return true;
	else
		return false;
}
