/* DLLADT file
 * DLLADT.h
 *
 *  Created on: 21-Jan-2019
 *      Author: e9
 */
/*
NAME:Sampada Gaikwad
ROLLNO:23118
*/
#ifndef DLLADT_H_
#define DLLADT_H_
#include "StackADT.h"

//Structure for Node
template<class T>
struct node{
	T data;
	node* left;    //Left Link
	node* right;   //Right Link
};

//Class DLL
template<class T>
class DLL{
public:
    node<T> *root;
    stack<node<T>*> sobj;   //Object of stack

	DLL();                 //Constructor
	//Methods for DLL
	node<T>* getNode();
	node<T>* Create();
	void Inorder(node<T>*);
	void Preorder(node<T>*);
	void Postorder(node<T>*);
	void InorderRec(node<T>*);
	void PreorderRec(node<T>*);
	void PostorderRec(node<T>*);
	void Insert(node<T>*);
	void LeafNodes(node<T>*);
	int Height(node<T>*);
	node<T>* CopyBinaryTree(node<T>*);
};

#endif /* DLLADT_H_ */
