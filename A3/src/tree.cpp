/*
 *  tree.cpp
 *
 *  Created on: 29-Jan-2019
 *  Author: f9
 */
#include <iostream>
using namespace std;
#include "tree.h"

tree::tree()   			//constructor with root= NULL
{
	root=NULL;
}

tree::~tree()
{
  //empty destructor
}

node* tree::maketree()   //create function to accept data
{
	node* p;
	p=new(node);
	cout << "Enter item: ";
     cin >>p->data;
	p->left=NULL;
	p->right=NULL;
	return p;
}
 void tree::insert()    //function to insert elements in tree
{
	 int ch1;
	 int flag=0;
	if (root == NULL)
	    {
	       root=maketree();
	    }
	else
	{
		node*p=root;
		do               //to insert whether at right or left
		 {
				cout<<"MENU \n1)Insert At Left\n2)Insert At Right\nEnter Your Choice : ";
				cin>>ch1;
				switch(ch1)
				{
				case 1:
					if(p->left==NULL)
					{
					    p->left=maketree();
					    flag=1;
					}
					else
						p=p->left;
					break;
				case 2:
					if(p->right==NULL)
					{
						p->right=maketree();
				      	flag=1;
					}
					else
						p=p->right;
					break;
				}

			}while(flag!=1);
	}

}
 void tree::preorder(node* root)   //function for traversal of tree from root/left/right
 {

     if (root == NULL)
     {
         return;
     }
     else if (root != NULL)
     {
    	 cout <<root->data<< " ";
    	 preorder(root->left);
    	 preorder(root->right);
     }
 }
  int tree::count(node* root)  //function for count no. of  terminal nodes in an tree
  {
  	int i;
  	if(root==NULL)
  	  return 0;
  	if(root->left==NULL && root->right==NULL)
  	{
  		cout<<"   "<<root->data;
  		return 1;
	}

  	i=count(root->left)+count(root->right);
  	return i;
  }
   node* tree::copy(node* root)  //function to create an copy of tree
   {

   	node* cpyroot=NULL;
   	if(root!=NULL)
   	{
   	   	cpyroot=new node;
   		cpyroot->left=NULL;
   		cpyroot->right=NULL;
	   cpyroot->data=root->data;
	   cpyroot->left=copy(root->left);
	   cpyroot->right=copy(root->right);
	}
     	return cpyroot;

   }
 int tree::depth(node* root)  //functon to calculate depth of a tree
 {
	 int lheight;
	 int rheight;
	 if(root==NULL)
		 return 0;
	 if(root->left==NULL && root->right==NULL)
         return 0;
       lheight=depth(root->left);
       rheight=depth(root->right);
	 if(lheight>rheight) {
		   lheight=lheight+1;
	       return lheight;
		 }
	 else{
		 rheight=rheight+1;
		 return rheight;
        }
	 }


