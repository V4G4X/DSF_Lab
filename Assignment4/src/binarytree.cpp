/*
 * binarytree.cpp
 *
 *  Created on: 16-Jan-2019
 *      Author: f10
 */

#include "binarytree.h"
#include<cstring>
#include "stack.cpp"
#include<iostream>
#include<iomanip>
using namespace std;

//function creates a new node
template<class T>
node<T>* binary_tree<T>::getnode(T x){
	node<T>* temp=new node<T>;
	temp->data=x;
	temp->lchild=NULL;
	temp->rchild=NULL;
	return temp;
}

//constructor
template<class T>
binary_tree<T>::binary_tree() {
	root=NULL;
	// TODO Auto-generated constructor stub

}

//destructor
template<class T>
binary_tree<T>::~binary_tree() {
	// TODO Auto-generated destructor stub
}

//check if variable or operator
template<class T>
bool binary_tree<T>::alpha(char c){
	if((int(c)<=43 && int(c)>=40 )|| int(c)==45 ||int(c)==47 || c=='%'|| c=='^')
		return false;
	else
		return true;
}

//creation of expression tree from preorder expression
template<class T>
void binary_tree<T>::createpost(){
	char c[40];
	node<T> *temp=NULL;
	int var=0;
	int l;
	do{
		cout<<"Enter the postfix expression : ";
		cin>>c;
		l=strlen(c);
		for(int i=0;i<l;i++){
			if(alpha(c[i])){
				var++;
			}else if(c[i]=='(' || c[i]==')'){
				var=2;
				break;
			}else{
				var--;
			}
		}
	}while(var!=1);
	stack<node<T> *> s;
	cout<<"\n\n|"<<setw(10)<<"char"<<"|"<<setw(30)<<"Stack"<<"|\n\n";
	for(int i=0;i<l;i++){
		if(alpha(c[i])){	//if variable then push to stack
			temp=getnode(c[i]);
			s.push(temp);
		}else{				//if operator then attach variables from stack to its left and right child
			temp=getnode(c[i]);
			temp->rchild=s.pop();
			temp->lchild=s.pop();
			s.push(temp);
		}
		cout<<"|"<<setw(10)<<c[i]<<"|"<<setw(30)<<s.display()<<"|\n";
	}
	root=temp;
}

//create expression tree from prefix expression
template<class T>
void binary_tree<T>::createpre(){
	char c[40];
	node<T> *temp=NULL;
	int var=0;
	int l;
	do{
		cout<<"Enter the prefix expression : ";
		cin>>c;
		l=strlen(c);
		int i;
		for(i=0;i<l;i++){
			if(alpha(c[i])){
				var++;
			}else if(c[i]=='(' || c[i]==')'){
				var=2;
				break;
			}else{
				var--;
			}
		}
	}while(var!=1);
	stack<node<T> *> s;
	cout<<"\n\n|"<<setw(10)<<"char"<<"|"<<setw(30)<<"Stack"<<"|\n\n";
	for(int i=l-1;i>=0;i--){
		if(alpha(c[i])){	//if variable then push to stack
			temp=getnode(c[i]);
			s.push(temp);
		}else{				//if operator then attach variables from stack to its left and right child
			temp=getnode(c[i]);
			temp->lchild=s.pop();
			temp->rchild=s.pop();
			s.push(temp);
		}
		cout<<"|"<<setw(10)<<c[i]<<"|"<<setw(30)<<s.display()<<"|\n";
	}
	root=temp;
}

//inorder traversal of tree
template<class T>
void binary_tree<T>::inordern(){
	if(root==NULL){
		cout<<"\nTree is empty\n";
		return;
	}
	stack<node<T> *> s;
	node<T> *temp=root;
	do{
		while(temp!=NULL){		//traverse to leftmost node
			s.push(temp);
			temp=temp->lchild;
		}
		if(!s.isEmpty()){		//write the parent node and traverse to right
			temp=s.pop();
			cout<<" "<<temp->data;
			temp=temp->rchild;
		}
	}while(temp!=NULL || !s.isEmpty());
}

//preorder traversal of tree
template<class T>
void binary_tree<T>::preordern(){
	if(root==NULL){
			cout<<"\nTree is empty\n";
			return;
	}
	stack<node<T> *> s;
	node<T> *temp=root;
	do{
		while(temp!=NULL){		//traverse to left with printing parent
			s.push(temp);
			cout<<" "<<temp->data;
			temp=temp->lchild;
		}
		if(!s.isEmpty()){		//traverse right
			temp=s.pop();
			temp=temp->rchild;
		}
	}while(temp!=NULL || !s.isEmpty());
}

////postorder traversal of tree
template<class T>
void binary_tree<T>::postordern(){
	if(root==NULL){
			cout<<"\nTree is empty\n";
			return;
	}
	stack<node<T> *> s;
	node<T> *temp=root;
	node<T> *previous;
	s.push(root);
	do{
		temp=s.pop();
		if(temp->lchild==NULL && temp->rchild==NULL){	//if leaf then take it as previous
			previous=temp;
			cout<<" "<<temp->data;
		}else{
			if(temp->rchild==previous || temp->lchild==previous){ //if either of lchild or rchild already traced the take node as previous
				previous =temp;
				cout<<" "<<temp->data;
			}else{
				s.push(temp);
				if(temp->rchild!=NULL)		//push rchild
					s.push(temp->rchild);
				if(temp->lchild!=NULL)		//push lchild
					s.push(temp->lchild);
			}
		}
	}while(!s.isEmpty());
}

//call preorder function
template<class T>
void binary_tree<T>::preorder(){
	preorder(root);
}
//preorder traversal of tree with recursion function
template<class T>
void binary_tree<T>::preorder(node<T> *x){
	if(root==NULL){
		cout<<"\nTree is empty";
	}else{
		if(x!=NULL){
			cout<<" "<<x->data;
			preorder(x->lchild);	//traverse left
			preorder(x->rchild);	//traverse right
		}
	}
}

//call inorder function
template<class T>
void binary_tree<T>::inorder(){
	preorder(root);
}
//inorder traversal of tree with recursion function
template<class T>
void binary_tree<T>::inorder(node<T> *x){
	if(root==NULL){
		cout<<"\nTree is empty";
	}else{
		if(x!=NULL){
			inorder(x->lchild);		//traverse left
			cout<<" "<<x->data;
			inorder(x->rchild);		//traverse right
		}
	}
}

//call postorder function
template<class T>
void binary_tree<T>::postorder(){
	postorder(root);
}
//postorder traversal of tree with recursion function
template<class T>
void binary_tree<T>::postorder(node<T> *x){
	if(root==NULL){
		cout<<"\nTree is empty";
	}else{
		if(x!=NULL){
			postorder(x->lchild);	//traverse left
			postorder(x->rchild);	//traverse right
			cout<<" "<<x->data;
		}
	}
}

//function to display tree in 3 orders
template<class T>
void binary_tree<T>::display(){
		cout<<"\nInorder traversal : ";
		inorder(root);
		cout<<"\nPreorder traversal : ";
		preorder(root);
		cout<<"\nPostorder traversal : ";
		postorder(root);
		cout<<endl;
}
