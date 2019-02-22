/*  DLL Implementation file
 * DLLImpl.cpp
 *
 *  Created on: 21-Jan-2019
 *      Author: e9
 */
/*
NAME:Sampada Gaikwad
ROLLNO:23118
*/
#include<iostream>
#include<math.h>
#include "DLLADT.h"
#include "StackADT.h"
using namespace std;

//Constructor
template<class T>
DLL<T>::DLL(){
	root = NULL;
}

//Function for allocating memory to node
template<class T>
node<T>* DLL<T>::getNode()
{
	node<T>* temp = new node<T>;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

//Function for creating node
template<class T>
node<T>* DLL<T>::Create()
{
	node<T>* temp;
	int dir;

    root = getNode();           //Allocating memory
	cout<<"Enter the root node data:- ";
	cin>>root->data;            //Getting input
	temp = root;

	while(dir != -1){
		cout<<"Do you want to insert on left(0) or right(1) of "<<temp->data<<" or press (-1) to exit:- ";
		cin>>dir;

		if(dir == 0)
		{
			if(temp->left != NULL)   //Checking left part
			{
				temp = temp->left;   //Moving to left part
				continue;
			}
			temp->left = getNode();
			temp = temp->left;
			cout<<"Enter the data:- ";
			cin>>temp->data;
			temp = root;
		}
		else if(dir == 1)
		{
			if(temp->right != NULL)  //Checking right part
			{
				temp = temp->right;  //Moving to right part
				continue;
			}
			temp->right = getNode();
			temp = temp->right;
			cout<<"Enter the data:- ";
			cin>>temp->data;
			temp = root;
		}
		else if(dir == -1)
		{
			break;                //Exiting
		}
		else
		{
			cout<<"Enter the correct choice!!!"<<endl;
		}
	}
}

//Function for Inorder Recursive Display
template<class T>
void DLL<T>::InorderRec(node<T>* temp)
{
    if(temp == NULL)
	{
        return;
    }

    InorderRec(temp->left);    //Calling recursively
    cout<<temp->data<<" ";     //Displaying data
    InorderRec(temp->right);   //Calling recursively
}

//Function for Postorder Recursive Display
template<class T>
void DLL<T>::PostorderRec(node<T>* temp)
{
    if(temp == NULL)
	{
        return;
    }

    PostorderRec(temp->left);    //Calling recursively
    PostorderRec(temp->right);   //Calling recursively
    cout<<temp->data<<" ";       //Displaying data
}

//Function for Preorder Recursive Display
template<class T>
void DLL<T>::PreorderRec(node<T>* temp)
{
    if(temp == NULL)
	{
        return;
    }

    cout<<temp->data<<" ";       //Displaying data
    PreorderRec(temp->left);     //Calling recursively
    PreorderRec(temp->right);    //Calling recursively
}

//Function for Inorder Non-Recursive Display
template<class T>
void DLL<T>::Inorder(node<T>* temp)
{
	int top = -1;
	node<T>* item;

	if(temp == NULL)     //Checking root
	{
		cout<<"Empty Tree"<<endl;
	}

	while(temp != NULL || top != -1)   //Traversing the tree
	{
		while(temp != NULL)
		{
			top++;
			sobj.push(temp);          //Pushing node into the stack
			temp = temp->left;        //Moving to left
		}

		if(top != -1)
		{
			item = sobj.pop();        //Popping node from stack
			top--;
			cout<<item->data<<" ";
			temp = item->right;       //Moving to right
		}
	}
}

//Function for Preorder Non-Recursive Display
template<class T>
void DLL<T>::Preorder(node<T>* temp)
{
	node<T>* item;
	int top = -1;

	if(temp == NULL)      //Checking root
	{
		cout<<"Empty Tree"<<endl;
		return;
	}

	while(temp != NULL || top != -1)   //Traversing the tree
	{
		while(temp != NULL)
		{
			cout<<temp->data<<" ";
			top++;
			sobj.push(temp);          //Pushing node to stack
			temp = temp->left;        //Moving to left
		}

		if(top != -1)
		{
			item = sobj.pop();        //Popping node from stack
			top--;
			temp = item->right;       //Moving to right
		}
	}
}

//Function for Postorder Non-Recursive Display
template<class T>
void DLL<T>::Postorder(node<T>* temp)
{
	int top = -1,flag=0;
	node<T>* item;
	stack<int> s;

	if(temp == NULL)            //Checking root
	{
		cout<<"Empty Tree"<<endl;
		return;
	}

	while(temp != NULL || top != -1)        //Traversing the tree
	{
		while(temp != NULL)
		{
			top++;
			sobj.push(temp);              //Pushing node to stack
			s.push(1);
			temp = temp->left;            //Moving to left
		}

		if(top != -1)
        {
			item = sobj.pop();            //Popping node from stack
			top--;
			if(s.pop() == 1)
			{
				temp = item->right;        //Moving to right
				sobj.push(item);           //Pushing node to stack
				s.push(2);
				top++;
			}
			else
			{
				cout<<item->data<<" ";     //Displaying Data
			}
		}
	}
}

//Function for Leaf Nodes Display
template<class T>
void DLL<T>::LeafNodes(node<T>* temp)
{
    int top = -1,flag=0;
	node<T>* item;
	stack<int> s;

	if(temp == NULL)   //Checking root
	{
		cout<<"Empty Tree"<<endl;
		return;
	}

	while(temp != NULL || top != -1)    //Traversing the tree
	{
		while(temp != NULL)
		{
			top++;
			sobj.push(temp);            //Pushing node to stack
			s.push(1);
			temp = temp->left;          //Moving to left
		}

		if(top != -1)
        {
			item = sobj.pop();         //Popping node from stack
			top--;
			if(s.pop() == 1)
			{
				temp = item->right;     //Moving to right
				sobj.push(item);        //Pushing node to stack
				s.push(2);
				top++;
			}
			else if(item->left == NULL && item->right == NULL)  //Checking Condition
			{
				cout<<item->data<<" ";
			}
		}
	}
}

template<class T>
void DLL<T>::Insert(node<T>* temp)
{
    int dir,flag=0;

    if(root != NULL)    //Checking root
    {
        temp = root;
    }
    else
    {
        root = getNode();           //Allocating memory
        cout<<"Enter the root node data:- ";
        cin>>root->data;            //Getting input
        temp = root;
    }

	do{
		cout<<"Do you want to insert on left(0) or right(1) of "<<temp->data<<" :- ";
		cin>>dir;

		if(dir == 0)
		{
			if(temp->left != NULL)   //Checking left part
			{
				temp = temp->left;   //Moving to left part
				continue;
			}
			temp->left = getNode();
			temp = temp->left;
			cout<<"Enter the data:- ";
			cin>>temp->data;
			temp = root;
			flag = 1;
		}
		else if(dir == 1)
		{
			if(temp->right != NULL)  //Checking right part
			{
				temp = temp->right;  //Moving to right part
				continue;
			}
			temp->right = getNode();
			temp = temp->right;
			cout<<"Enter the data:- ";
			cin>>temp->data;
			temp = root;
			flag = 1;
		}
		else
		{
			cout<<"Enter the correct choice!!!"<<endl;
		}
	}while(flag != 1);
}

//Function for height calculation
template<class T>
int DLL<T>::Height(node<T>* temp)
{
    int height;

    if(temp == NULL)     //Checking root
    {
        return -1;
    }
    else
    {   //Recursive calling
        return (1 + (max(Height(temp->left),Height(temp->right))));
    }
}

//Function for creating copy of tree
template<class T>
node<T>* DLL<T>::CopyBinaryTree(node<T>* temp)
{
    if(temp == NULL)      //Checking root
    {
        return NULL;
    }

    node<T>* clone = getNode();         //Allocating new node
    clone->data = temp->data;

    clone->left = CopyBinaryTree(temp->left);     //Recursive calling with left subtree
    clone->right = CopyBinaryTree(temp->right);   //Recursive calling with right subtree

    return clone;            //Returning copy of tree
}
