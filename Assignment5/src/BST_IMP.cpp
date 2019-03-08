/*
 * Bst.cpp
 *
 *  Created on: 01-Feb-2019
 *      Author: e9
 */
//implementation of the functions of class Bst
#include<iostream>
using namespace std;
#include "BST_ADT.h"
template<class T>
Bst<T>::Bst() {
	root=NULL;

}
//function to create node
template<class T>
node<T>* Bst<T>::create_node(T x)
{
	node<T> *p;
	p=new node<T>;
	p->data=x;
	p->lchild=NULL;
	p->rchild=NULL;
}
//to call insert function
template<class T>
void Bst<T>::create_tree()
{
	T x;
	int check=0;
	node<T> *p;
	do
	{
		check=0;
		cout<<"Enter data of node you want to insert\n";
		cin>>x;
		p=create_node(x);
		insert(p);
		call_inorder();
		call_preorder();
		call_postorder();
		cout<<"Do you want to continue inserting\n";
		cout<<"Enter 1 to continue\n";
		cin>>check;
	}while(check == 1);
}
//insert a  node in tree
template<class T>
void Bst<T>::insert(node<T> *p)
{
	node<T> *pwalk,*parent;
	if(root==NULL)
	{
		root=p;
	}
	else
	{
		pwalk=root;
		while(pwalk!=NULL)
		{
			parent=pwalk;
			if(p->data < pwalk->data)
			{
				pwalk=pwalk->lchild;
			}
			else
			{
				pwalk=pwalk->rchild;
			}

		}
		if(p->data < parent->data)
			parent->lchild=p;
		else
			parent->rchild=p;
	}
}
//function to call insert
template<class T>
void Bst<T>::rec_create()
{
	T x;
	int check=0;
	node<T> *p;
	do
	{
		check=0;
		cout<<"Enter data of node you want to insert\n";
		cin>>x;
		p=create_node(x);
		root =rec_insert(root,p);
		call_inorder();
		call_preorder();
		call_postorder();
		cout<<"Do you want to continue inserting\n";
		cout<<"Enter 1 to continue\n";
		cin>>check;
	}while(check == 1);
}
//recurrsive function to insert a node
template<class T>
node<T>* Bst<T>::rec_insert(node<T> *base ,node<T> *p)
{
	if(base==NULL)
	{
		base=p;
		return base;
	}
	else
	{
		if(p->data < base->data)
			base->lchild=rec_insert(base->lchild,p);
		else
			base->rchild=rec_insert(base->rchild,p);

	}
	return base;
}
//function to call search function
template<class T>
void Bst<T>::searchbst(T key)
{
	node<T> *p;
	p=search(root, key);
	if(p==NULL)
		cout<<"Node not found\n";
	else
		cout<<"Node found\n";
	call_inorder();
	call_preorder();
	call_postorder();

}
//function to search an element int the tree
template<class T>
node<T>* Bst<T>::search(node<T> *base,T key)
{
	if(base==NULL)
		return NULL;
	if(key< base->data)
	{
		return search(base->lchild,key);
	}
	else if(key > base->data)
	{
		return search(base->rchild,key);
	}
	else
	{
		return base;
	}
}
//calling inorder
template<class T>
void Bst<T>::call_inorder()
{
	cout<<"Inorder traversal :";
	inorder(root);
	cout<<endl;
}
//displaying inorder traversals
template<class T>
void Bst<T>::inorder(node<T> *base)
{
	if(base !=NULL)
	{
		inorder(base->lchild);
		cout<<base->data<<" ";
		inorder(base->rchild);

	}
}
//calling preorder
template<class T>
void Bst<T>::call_preorder()
{
	cout<<"Preorder traversal :";
	preorder(root);
	cout<<endl;
}
//displaying preorder taversal
template<class T>
void Bst<T>::preorder(node<T> *base)
{
	if(base !=NULL)
	{
		cout<<base->data<<" ";
		preorder(base->lchild);
		preorder(base->rchild);

	}
}
//calling postorder
template<class T>
void Bst<T>::call_postorder()
{
	cout<<"Postorder traversal :";
	postorder(root);
	cout<<endl;
}
//displaying postorder traversal
template<class T>
void Bst<T>::postorder(node<T> *base)
{
	if(base !=NULL)
	{

		postorder(base->lchild);
		postorder(base->rchild);
		cout<<base->data<<" ";

	}
}
//caaling delete function
template<class T>
void Bst<T>::call_delete(T key)
{
	node<T> *p;
	p=delete_node(root,key);
	if(p!=NULL)
	{
		cout<<"Deleted successfully\n";
	}
	else
	{
		cout<<"Could not delete node\n";
	}
}
//finding min from right subtree
template<class T>
node<T>* Bst<T>::find_min(node<T> *p)
{
	while(p->lchild!=NULL)
		p=p->lchild;
	return p;
}
//function to delete a node from the tree
template <class T>
node<T>* Bst<T>::delete_node(node<T>* NODE,T data){
	if(NODE==NULL)
		return NODE;
	else if(data<NODE->data)
		NODE->lchild=delete_node(NODE->lchild,data);
	else if(data>NODE->data)
		NODE->rchild=delete_node(NODE->rchild,data);
	else{
		if(NODE->lchild==NULL && NODE->rchild==NULL){
			delete(NODE);
			NODE=NULL;
		}
		else if(NODE->lchild==NULL){
			node<T>* temp=NODE;
			NODE=NODE->rchild;
			delete(temp);
		}
		else if(NODE->rchild==NULL){
			node<T>* temp=NODE;
			NODE=NODE->lchild;
			delete(temp);
		}
		else{
			node<T>* temp=find_min(NODE->rchild);
			NODE->data=temp->data;
			NODE->rchild=delete_node(NODE->rchild,temp->data);
		}
	}
	return NODE;
}
//calling mirror function
template<class T>
void Bst<T>::call_mirror()
{
	cout<<"Tree before mirror:\n";
	call_preorder();
	call_inorder();
	call_postorder();
	mirror_bst(root);
	cout<<"Tree after mirror:\n";
	call_preorder();
	call_inorder();
	call_postorder();
	mirror_bst(root);
}
//function to find mirror of the tree
template<class T>
void Bst<T>::mirror_bst(node<T> *base)
{
	if(base)
	{
		node<T> *temp;
		temp=base->rchild;
		base->rchild=base->lchild;
		base->lchild=temp;
		mirror_bst(base->lchild);
		mirror_bst(base->rchild);
	}

}
