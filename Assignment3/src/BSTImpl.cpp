/*  BT Implementation file
 * BTImpl.cpp
 *
 *  Created on: 21-Jan-2019
 *      Author: e9
 */
/*
NAME:Sampada Gaikwad
ROLLNO:23118
*/
#include<iostream>
#include "BSTADT.h"
#include "DLLADT.h"
#include "StackADT.h"
using namespace std;

//Function for creating tree
template<class T>
void BT<T>::Create(){
	obj.Create();
}

//Function for displaying preorder tree
template<class T>
void BT<T>::DisplayPreorder()
{
    obj.PreorderRec(obj.root);
}

//Function for displaying postorder tree
template<class T>
void BT<T>::DisplayPostorder()
{
    obj.PostorderRec(obj.root);
}

//Function for displaying inorder tree
template<class T>
void BT<T>::DisplayInorder()
{
    obj.InorderRec(obj.root);
}

//Function for displaying inorder tree
template<class T>
void BT<T>::Inorder()
{
	obj.Inorder(obj.root);
}

//Function for displaying preorder tree
template<class T>
void BT<T>::Preorder()
{
	obj.Preorder(obj.root);
}

//Function for displaying postorder tree
template<class T>
void BT<T>::Postorder()
{
	obj.Postorder(obj.root);
}

//Function for inserting node in the tree
template<class T>
void BT<T>::Insert()
{
	obj.Insert(obj.root);
}

//Function for displaying leaf nodes
template<class T>
void BT<T>::Leafnodes()
{
	obj.LeafNodes(obj.root);
}

//Function for height
template<class T>
void BT<T>::Height()
{
    int height;

    height = obj.Height(obj.root);

    cout<<"Height of Binary Tree is "<<height<<endl;
}

//Function for making copy of tree
template<class T>
void BT<T>::CopyTree()
{
    node<T>* temp;
    temp = obj.CopyBinaryTree(obj.root);

    cout<<"\nOriginal Tree:- ";
    obj.InorderRec(obj.root);
    cout<<endl;
    cout<<"Copied Tree:- ";
    obj.InorderRec(temp);
    cout<<endl;
}
