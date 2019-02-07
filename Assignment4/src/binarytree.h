/*
 * binarytree.h
 *
 *  Created on: 16-Jan-2019
 *      Author: f10
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

template<class T>
struct node{
	T data;
	node<T> *lchild;
	node<T>	*rchild;
};

template<class T>
class binary_tree {
	node<T> *root;
public:
	binary_tree();
	virtual ~binary_tree();
	node<T>* getnode(T);
	bool alpha(char);
	void createpre();
	void createpost();
	void preorder(node<T> *);
	void postorder(node<T> *);
	void inorder(node<T> *);
	void preorder();
	void inorder();
	void postorder();
	void inordern();
	void postordern();
	void preordern();
	void display();
};

#endif /* BINARYTREE_H_ */
