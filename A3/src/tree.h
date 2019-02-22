/*
 * tree.h
 *
 *  Created on: 29-Jan-2019
 *      Author: f9
 */
#ifndef TREE_H
#define TREE_H
struct node   					//structure of a node
{
	int data;  //data
	struct node* left;  		//left node of root
	struct node* right; 		//right node of a root
};
class tree   					//tree class
{
	public:
		node* root;
		tree();   				 //constructor
		~tree(); 			     //destructor
	node* maketree(); 			 //make tree function to create a tree
    void insert();    			 //insert function to insert elements in a tree
    void preorder(node*);    //preorder traversal function
    int depth(node*);            //function for depth
    int count(node*);		     // count of terminal nodes function
    node* copy(node*);           // copy of a tree

};

#endif
