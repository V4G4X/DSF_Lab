//============================================================================
// Name        : LLimp.cpp
// Author      : Varun Gawande
// Copyright   : Your copyright notice
// Description : Implementation of LLADT.h
//============================================================================

#include <iostream>
#include "LLADT.h"
using namespace std;

template<class T>
Node<T>::Node(T data){
	this->data = data;
	next = NULL;
}

template<class T>
SLL<T>::SLL(){
	head = NULL;
	len=0;
}

template<class T>
int SLL<T>::length(){
	return len;
}

template<class T>
bool SLL<T>::create(int i){
	if(len!=0){
		return 0;
	}
	T data;
	if(i>=1){
		cout<<"Data Node: 1"<<endl;
		cout<<"Enter data: ";
		cin>>data;
		head = getnode(data);
	}
	else return 0;
	Node<T>* tra = head;
	len=i;
	for(i=1 ; i<len ; i++){
		cout<<"Data Node: "<<(i+1)<<endl;
		cout<<"Enter data: ";
		cin>>data;
		tra->next = getnode(data);
		tra = tra->next;
	}
	return 1;
}

template<class T>
bool SLL<T>::isEmpty(){
	if(head==NULL)
		return 1;
	else
		return 0;
}

template<class T>
void SLL<T>::print(){
	int i;
	if(isEmpty()){
		cout<<"The SLL is empty\n";
		return;
	}
	Node<T> *tra = head;
	for(i=0 ; i<len ; i++){
		cout<<tra->data<<endl;
		tra=tra->next;
	}
}


template<class T>
T SLL<T>::getdata(int i){
	int j=0;
	if(isEmpty()){
//		cout<<"The SLL is empty\n";
		T B;
		return B;
	}
	Node<T> *tra = head;
	while(j<i){
		if(j==len-1) return tra->data;
		tra=tra->next;
		j++;
	}
	return tra->data;
}

template<class T>
bool SLL<T>::insert(T data, int ch){
	if(ch==0){
		Node<T>* newn = new Node<T>(data);
		newn->next = head;
		head = newn;
		len++;
		return 1;
	}
	else if(ch<len && ch>0){
		int i;
		Node<T>* tra = head;
		for(i=0 ; i<ch-1 ; i++)
			tra = tra->next;
		Node<T>* newn = new Node<T>(data);
		newn->next = tra->next;
		tra->next = newn;
		len++;
		return 1;
	}
	else if(ch>=len){
		Node<T>* tra = head;
		int i;
		for(i=0 ; i<len-1 ; i++)
			tra = tra->next;
		Node<T>* newn = new Node<T>(data);
		tra->next = newn;
		len++;
		return 1;
	}
	else
		return 0;
}

template<class T>
bool SLL<T>::dlete(int ch){
	if(ch==0){
		Node<T>* deln = head;
		head = head->next;
		delete deln;
		len--;
		return 1;
	}
	else if(ch<len-1 && ch>0){
		int i;
		Node<T>* tra = head;
		for(i=0 ; i<ch-1 ; i++)
			tra = tra->next;
		Node<T>* deln = tra->next;
		tra->next = deln->next;
		delete deln;
		len--;
		return 1;
	}
	else if(ch>=len-1){
		Node<T>* tra = head;
		int i;
		for(i=0 ; i<len ; i++)
			tra = tra->next;
		delete tra;
		len--;
		return 1;
	}
	else
		return 0;
}

template<class T>
Node<T>* SLL<T>::getnode(T data){
	Node<T> *link = new Node<T>(data);
	return link;
}
