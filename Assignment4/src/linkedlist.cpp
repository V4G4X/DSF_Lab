#include<iostream>
#include "linkedlist.h"
using namespace std;

template <class T>
link<T>:: link(){
	head=NULL;
}

template <class T>
link<T>::~link(){
}

template <class T>
void link<T> :: insert_first(T x){
	node<T> *temp=NULL;
	temp=new node<T>;
	temp->data=x;
	temp->next=head;
	head=temp;
}
template <class T>
T link<T> :: delete_first(){
	T x;
	node<T> *temp=NULL;
	temp=head;
	x=temp->data;
	head=temp->next;
	delete(temp);
	return x;

}
template <class T>
bool link<T> :: isempty(){
	if(head==NULL)
		return true;
	else
		return false;
}

template <class T>
T link<T> :: top_element(){
	return(head->data);
}
