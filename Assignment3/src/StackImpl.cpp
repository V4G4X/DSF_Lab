//Stack Implementation file
/*
NAME:Sampada Gaikwad
ROLLNO:23118
*/
#include<iostream>
#include"StackADT.h"
using namespace std;

//Constructor
template<class T>
stack<T>::stack(){
    s.top = -1;
}

//Function for checking stack is empty or not
template<class T>
int stack<T>::isEmpty(){
	if(s.top == -1){
		return 1;
	}
	else{
		return 0;
	}
}

//Function for checking stack is full or not
template<class T>
int stack<T>::isFull(){
	if(s.top == MAX-1){
		return 1;
	}
	else{
		return 0;
	}
}

//Function for push
template<class T>
void stack<T>::push(T n){
	int check;
	int cont=1;

	check = isFull();   //Checking stack is full or not
	if(check == 0)
	{
		s.top += 1;
		s.arr[s.top] = n;   //Pushing the data
	}
	else
	{
		cout<<"Stack Overflow"<<endl;
	}
}

//Function for pop
template<class T>
T stack<T>::pop(){
	int check;
	T data;

	check = isEmpty();    //Checking stack is empty or not

	if(check == 0){
		data = s.arr[s.top];  //Popping the data
		s.top -= 1;
	}
	else{
		return NULL;
	}

	return data;
}

//Function for peep
template<class T>
T stack<T>::peep(){
	return s.arr[s.top];
}
