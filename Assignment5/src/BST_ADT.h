/*
 * BST_ADT.h
 *
 *  Created on: 08-Feb-2019
 *      Author: v4g4x
 */
#ifndef BST_ADT_H_
#define BST_ADT_H_

template<class T>
class BST;

template<class T>
class Node{
private:
	Node* lchild;
	T data;
	Node* rchild;
public:
	friend class BST<T>;
	Node();
	Node(T data);
	Node<T>* mirror_fun(Node<T>* node);
};


template<class T>
class BST{
private:
	Node<T>* root;
	bool mir;				//0 for un-mirrored, 1 for mirrored
	void inorder(Node<T> *node);
	void inorder_nr();
public:
	BST();
	BST(T data);
	bool isEmpty();
	bool isMirror();
	bool insert(T data);
	bool search(T data);
	BST<T>* mirror();
	void display();
	void display_level();
	T dlete(T data);
	int height();
};



#endif /* BST_ADT_H_ */
