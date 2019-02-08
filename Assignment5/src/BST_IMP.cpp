/*
 * BST_IMP.cpp
 *
 *  Created on: 08-Feb-2019
 *      Author: v4g4x
 */
#include <iostream>
#include "BST_ADT.h"

//Node Class Functions
//Default Constructor
template<class T>
Node<T>::Node(){
	lchild = NULL;
	data = (T)0;
	rchild = NULL;
}

//Parameterized Constructor
template<class T>
Node<T>::Node(T data){
	lchild = NULL;
	this->data = data;
	rchild = NULL;
}

//Recursive Mirror function that mirrors individual node links and data to newly allocated nodes
template<class T>
Node<T>* Node<T>::mirror_fun(Node<T>* node){
	this->data = node->data;
	if(node->rchild!=NULL){
		lchild = new Node<T>;
		lchild->mirror_fun(node->rchild);
	}
	if(node->lchild!=NULL){
		rchild = new Node<T>;
		rchild->mirror_fun(node->lchild);
	}
	return this;
}

//BST Class Functions
//Default Constructor
template<class T>
BST<T>::BST(){
	root = NULL;
	mir = 0;
}

//Parameterized Constructor
template<class T>
BST<T>::BST(T data){
	root = new Node<T>*(data);
	mir = 0;
}

//Returns 1 if Empty, 0 if not.
template<class T>
bool BST<T>::isEmpty(){
	if(root==NULL)
		return 1;
	else return 0;
}

//Returns 1 if MirrorTree, 0 if not.
template<class T>
bool BST<T>::isMirror(){
	if(mir)
		return 1;
	else return 0;
}

//Inserts Passed data into Tree
template<class T>
bool BST<T>::insert(T data){
	Node<T>* temp = root;
	while(1){
		if(data>temp->data){
			if(temp->rchild!=NULL)			//Traverse to Right Node
				temp = temp->rchild;
			else{							//Right Branch is Empty
				temp->rchild = new Node<T>*(data);
				return 0;
			}
		}
		else	if(data<temp->data){
			if(temp->lchild!=NULL)			//Traverse to Left Node
				temp = temp->lchild;
			else{
				temp->lchild = new Node<T>*(data);
				return 0;
			}
		}
		else
			return 1;						//Data already exists
	}
}

//Returns 1 if Data exists, 0 if doesn't
template<class T>
bool BST<T>::search(T data){
	Node<T>* temp = root;
	while(1){
		if(data>temp->data){
			if(temp->rchild==NULL)
				return 0;					//Data doesn't Exist
			else
				temp = temp->rchild;		//Traverse to Right Node
		}
		else	if(data<temp->data){
			if(temp->lchild==NULL)
				return 0;					//Data doesn't Exist
			else
				temp = temp->lchild;		//Traverse to Left Node
		}
		else								//Data Match
			return 1;						//Return that Data  exists
	}
}

//Returns a freshly allocated BST, with all nodes Mirrored
template<class T>
BST<T>* BST<T>::mirror(){
	BST<T>* m = new BST<T>;
	m->root->mirror_fun(this->root);
	m->mir=(!m->mir);				//Inverts Value of mir i.r Mirror Flag
	return m;
}

//Traverses all nodes in All Fashions: InOrder, PreOrder, PostOrder
template<class T>
void BST<T>::display(){
	//Inorder Traversal
	if(!isEmpty()){
		inorder(root);
	}
}

//Recursively Inorder Traversal
template<class T>
void BST<T>::inorder(Node<T>* node){
	if()
}
