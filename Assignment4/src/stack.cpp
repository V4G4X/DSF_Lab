#include<iostream>
#include "linkedlist.h"
#include "linkedlist.cpp"
#include"stack.h"
using namespace std;

template <class T>
stack<T>::stack(){

}

template <class T>
stack<T> ::~stack(){

}

template <class T>
void stack<T> :: push(T x){
	l1.insert_first(x);
}

template <class T>
T stack<T> :: pop(){
	return l1.delete_first();
}

template <class T>
bool stack<T>::isempty(){
	return (l1.isempty());
}

template <class T>
T stack<T>::peep(){
	return l1.top_element();
}
