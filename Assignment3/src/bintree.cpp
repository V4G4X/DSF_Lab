/*
 *  bintree.cpp
 *
 *  Created on: 29-Jan-2019
 *  Author: e9
 */
#include<iostream>
using namespace std;
#include "bintree.h"

template<class T>
bin_tree<T>::bin_tree(){
	root=NULL;
	temp=NULL;
}
template<class T>
bin_tree<T>::~bin_tree(){
}
template<class T>
node<T>* bin_tree<T>::getnode(T x){
	node<T>*temp=new node <T>;
	temp->data=x;
	temp->l_child=NULL;
	temp->r_child=NULL;
	return temp;
}

template<class T>
void bin_tree<T>::insert(T x){
	node <T>*p;
	int ch;
	p=getnode(x);
	if(root==NULL){
		root=p;
		return;
	}
	else{
		node<T>*temp=root;
		int flag=0;
		do{
			cout<<"Enter position to insert";
			cout<<"\n1.Left\n2.Right";
			cin>>ch;
			switch(ch){
			case 1:
				if(temp->l_child==NULL){
					temp->l_child=p;
					flag=1;
				}
				else{
					temp=temp->l_child;
				}
				break;
			case 2:
					if(temp->r_child==NULL){
						temp->r_child=p;
						flag=1;
					}
					else{
						temp=temp->r_child;
					}
			}
		}while(flag==0);
	}
	display();

}
template<class T>
void bin_tree<T>::initialise(){
	temp=root;
}
template<class T>
node<T>* bin_tree<T>::call_copy(){
	initialise();
	temp=copy(temp);
	return temp;
}
template<class T>
node<T>* bin_tree<T>::copy(node<T>* temp){
	if(root==NULL)
		return root;
	else{
	temp->data=root->data;
	temp->l_child=copy(root->l_child);
	temp->r_child=copy(root->r_child);
	}
	return temp;
}
template<class T>
void bin_tree<T>::call_inorder(){
	initialise();
	disp_inorder(temp);
}
template<class T>
void bin_tree<T>::call_preorder(){
	initialise();
	disp_preorder(temp);
}
template<class T>
void bin_tree<T>::call_postorder(){
	initialise();
	disp_postorder(temp);
}
template<class T>
void bin_tree<T>::disp_inorder(node<T>* temp){
	if(temp!=NULL)
	{
		disp_inorder(temp->l_child);
		cout<<temp->data<<"->";
		disp_inorder(temp->r_child);
	}
}
template<class T>
void bin_tree<T>::disp_preorder(node<T>* temp){
	if(temp!=NULL)
	{
		cout<<temp->data<<"->";
		disp_preorder(temp->l_child);
		disp_preorder(temp->r_child);
	}
}

template<class T>
void bin_tree<T>::disp_postorder(node<T>* temp){
	if(temp!=NULL)
	{
		disp_postorder(temp->l_child);
		disp_postorder(temp->r_child);
		cout<<temp->data<<"->";
	}
}
template<class T>
void bin_tree<T>::display(){
	cout<<"\nInorder traversal :";
	call_inorder();
	cout<<"\nPreorder traversal :";
	call_preorder();
	cout<<"\nPostorder traversal :";
	call_postorder();
}
template<class T>
void bin_tree<T>::call_insert_rec(T x){
	root=insert_rec(x,root);
}
template<class T>
node<T>* bin_tree<T>::insert_rec(T x,node<T>*R){
	int ch;
	if(R==NULL){
		R=getnode(x);
		return R;
	}
	else{
		node<T>*temp=R;
		cout<<"\nEnter position \n1.Left\n2.Right";
		cin>>ch;
		if(ch==1){
		temp->l_child=insert_rec(x,temp->l_child);
		}
		else
		temp->r_child=insert_rec(x,temp->r_child);

	}
	return R;
}
