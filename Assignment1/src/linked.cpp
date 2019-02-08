/*
 * linked.cpp
 *
 */

#include "linked.h"
#include<iostream>
using namespace std;
template<class T>

T linked<T>::display_first()
{
	return head->data;
}
template<class T>
//Function that allocates dynamic memory for node structure
node <T>* linked<T>::getnode(T x)
{
		node <T>*temp=new node<T>;
		temp->data=x;
		temp->next=NULL;
		return temp;
}

//Function inserts a node at first position
template<class T>
void linked<T>::insert_first(T x)
{
	if(head==NULL)
	{
		head=getnode(x);
		head->data=x;
	}
	else
	{
	node<T>* temp=getnode(x);
	temp->next=head;
	head=temp;
	}
}
//Function deletes a node from first position
template<class T>
T linked<T>::del_first()
{

	if(head->next==NULL)
	{

		T a= head->data;
		head=NULL;
		return a;
	}
	else
	{
		T a= head->data;
	node <T>*temp=head;
	head=head->next;
	delete(temp);
	return a;

	}
}
//Function returns 1 if list is empty
template<class T>
T linked<T>::isempty()
{
	if(head==NULL)
	{
		return 1;
	}
	return 0;
}

template<class T>
linked<T>::linked() {
	// TODO Auto-generated constructor stub
head=NULL;
}
template<class T>
linked<T>::~linked() {
	// TODO Auto-generated destructor stub
}


