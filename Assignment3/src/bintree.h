/*
 * bintree.h
 *
 *  Created on: 29-Jan-2019
 *      Author: f9
 */

#ifndef BINTREE_H_
#define BINTREE_H_
template<class T>
struct node
{
	node <T>*l_child;
	T data;
	node <T>*r_child;
};
template<class T>
class bin_tree {
	node<T>*root;
	node<T>*temp;
public:
	bin_tree();
	void initialise();
	node<T>*getnode(T x);
	void insert(T x);
	void call_insert_rec(T x);
	node<T>* insert_rec(T x,node<T>*root);
	void display();
	node<T>* copy(node<T>* temp);
	node<T>* call_copy();
	void disp_inorder(node<T>* temp);
	void disp_preorder(node<T>* temp);
	void disp_postorder(node<T>* temp);
	void call_inorder();
	void call_preorder();
	void call_postorder();
	virtual ~bin_tree();
};

#endif /* BINTREE_H_ */
