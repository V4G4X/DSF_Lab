/*
 * Bst.h
 *
 *  Created on: 01-Feb-2019
 *      Author: e9
 */
//Bst Adt
#ifndef BST_H_
#define BST_H_
template<class T>
struct node
{
	T data;
	struct node<T> *lchild;
	struct node<T> *rchild;
};
template<class T>
class Bst {
	node<T> *root;
public:
	Bst();
	//virtual ~Bst();
	node<T>* create_node(T x);
	void create_tree();
	void insert(node<T> *p);
	void rec_create();
	node<T>* rec_insert(node<T> *base,node<T> *p);
	void searchbst(T key);
	node<T>* search(node<T> *base,T key);
	void call_inorder();
	void inorder(node<T> *base);
	void call_preorder();
	void preorder(node<T> *base);
	void call_postorder();
	void postorder(node<T> *base);
	void call_delete(T key);
	node<T>* delete_node(node<T> *base,T key);
	void call_mirror();
	void mirror_bst(node<T> *base);
	node<T>* find_min(node<T> *p);

};

#endif /* BST_H_ */
