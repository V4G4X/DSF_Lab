//============================================================================
// Name        : Assignment5.cpp
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

template<class T>
struct node
{
	T data;
	node *lchild;
	node *rchild;
};

template<class T>
class BST
{
	private: node<T> *root;

	public:

	BST();
	node<T>* setRoot(node<T> *temp);
	node<T>* getRoot();
	node<T>* getNode(T data);
	void insertNR(T data);
	node<T>* insertR(node<T> *parent, T data);
	bool searchR(node<T> *root, T data);
	bool searchNR(T data);
	node<T>* deleteBST(node<T> *root, T data);
	node<T>* mirror(node<T> *root);
	void inOrder(node<T> *root);
	void preOrder(node<T> *root);
	void postOrder(node<T> *root);
	void display();
};

template<class T>
BST<T> :: BST()
{
	root = NULL;
}

template<class T>
node<T>* BST<T> :: getRoot()
{
	return root;
}

template<class T>
node<T>* BST<T> :: setRoot(node<T> *temp)
{
	root = temp;
}


template<class T>
node<T>* BST<T> :: getNode(T data)
{
	node<T> *temp = new node<T>;
	temp->data = data;
	temp->lchild = NULL;
	temp->rchild = NULL;
	return temp;
}

template<class T>
void BST<T> :: insertNR(T data)
{
	node<T> *temp=root, *parent=NULL;
	if(root == NULL)
	{
		root = getNode(data);
		return;
	}
	while(temp!=NULL)
	{
		parent = temp;
		if(data < temp->data)
			temp = temp->lchild;
		else
			temp = temp->rchild;
	}
	if(data < parent->data)
		parent->lchild = getNode(data);
	else
		parent->rchild = getNode(data);
}

template<class T>
node<T>* BST<T> :: insertR(node<T> *parent, T data)
{
	if(parent == NULL)
	{
		parent = getNode(data);
		return parent;
	}
	if(data > parent->data)
		parent->rchild = insertR(parent->rchild, data);

	else if(data < parent->data)
		parent->lchild = insertR(parent->lchild, data);
	else if(data == parent->data)
		return NULL;
}

template<class T>
bool BST<T> :: searchR(node<T> *root, T data)
{
	if(root == NULL)
		return false;
	if(data == root->data)
		return true;
	if(data < root->data)
		return searchR(root->lchild, data);
	if(data > root->data)
		return searchR(root->rchild, data);
}

template<class T>
bool BST<T> :: searchNR(T data)
{
    // Traverse untill root reaches to dead end
    while (root != NULL)
    {
        // pass right subtree as new tree
        if (data > root->data)
            root = root->rchild;

        // pass left subtree as new tree
        else if (data < root->data)
            root = root->lchild;
        else
            return true;// if the key is found return 1
    }
    return false;
}

template<class T>
node<T>* BST<T> :: deleteBST(node<T> *root, T data)
{
	node<T> *temp=NULL;

	if(root == NULL)
		return NULL;
	if(data < root->data)
		root->lchild = deleteBST(root->lchild, data);
	if(data > root->data)
		root->rchild = deleteBST(root->rchild, data);
	if(data == root->data)
	{
		if(root->lchild == NULL && root->rchild == NULL)
		{
			delete root;
			return NULL;
		}
		if(root->lchild == NULL)
		{
			temp = root->rchild;
			delete root;
			return temp;
		}
		if(root->rchild == NULL)
		{
			temp = root->lchild;
			delete root;
			return temp;
		}
        // node with two children: Get the inorder predecessor
		temp = root->lchild;
		while(temp->rchild != NULL)
			temp = temp->rchild;
        root->data = temp->data;
        root->lchild = deleteBST(root->lchild, temp->data);
    }
    return root;
}

template<class T>
node<T>* BST<T> :: mirror(node<T> *root)
{
	node<T> *temp ;
	if(root == NULL) return NULL;

	temp = root->rchild;
	root->rchild = root->lchild;
	root->lchild = temp;

	mirror(root-> lchild);
	mirror(root-> rchild);

	return root;
}

template<class T>
void BST<T> :: inOrder(node<T> *root)
{
	if(root != NULL)
	{
		inOrder(root->lchild);
		cout <<" "<< root->data;
		inOrder(root->rchild);
	}
	return;
}

template<class T>
void BST<T> :: postOrder(node<T> *root)
{
	if(root != NULL)
	{
		postOrder(root->lchild);
		postOrder(root->rchild);
		cout <<" "<< root->data;
	}
}

template<class T>
void BST<T> :: preOrder(node<T> *root)
{
	if(root != NULL)
	{
		cout <<" "<< root->data;
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
}

template<class T>
void BST<T> :: display()
{
	cout << "\n InOrder Trversal:";
	inOrder(root);
	cout << "\n PreOrder Traversal:";
	preOrder(root);
	cout << "\n PostOrder Traversal:";
	postOrder(root);
}

int main()
{
	BST<int> b;
	int data;
	node<int> *ele, *temp;

	int choice;
	while(true)
	{
		cout << "\n ---------------:: MENU ::------------------";
		cout << "\n\t ";
		cout << "\n 1) Insert Recursive";
		cout << "\n 2) Insert Non-Recursive";
		cout << "\n 3) Search Recursive";
		cout << "\n 4) Search Non-Recursive";
		cout << "\n 5) Delete ";
		cout << "\n 7) Mirror image";
		cout << "\n 8) Display";
		cout << "\n 0) Exit";
		cout << "\n\t Enter your choice ";
		cin >> choice;
		cout << "\n -------------------------------------------";

		switch(choice)
		{
		case 1:
			cout << "\n Enter the data ";
			cin >> data;
			b.setRoot(b.insertR(b.getRoot(), data));
			cout << "Binary search Tree  \n ";
			b.display();
			break;

		case 2:
			cout << "\n Enter the data ";
			cin >> data;
			b.insertNR(data);
			cout << "Binary search Tree -: \n ";
			b.display();
			break;

		case 3:
			cout << "\n Enter the element you want to search : ";
			cin >> data;

			if(b.getRoot() == NULL)
				cout << "\n Empty Tree";
			else
			{
				if(b.searchR(b.getRoot(),data))
					cout << "\n Element found -:" <<data;
				else
					cout << "\n Element not found";
			}
			break;

		case 4:
			cout << "\n Enter the element you want to search : ";
			cin >> data;

			if(b.getRoot() == NULL)
				cout << "\n Empty Tree";
			else
			{
				if(b.searchR(b.getRoot(),data))
					cout << "\n Element found -:" <<data;
				else
					cout << "\n Element not found";
			}
			break;

		case 5:
			cout << "\n Enter the data you want to delete ";
			cin >> data;
			cout << "Binary search Tree before deletion -: \n ";
			b.inOrder(b.getRoot());
			b.deleteBST(b.getRoot(),data);
			cout << "\nBinary search Tree after deletion -: \n ";
			b.display();
			break;

		case 6:
			node<int> *r;
			cout <<"\n Original tree -: ";
			b.display();
			r = b.mirror(b.getRoot());
			cout << "\n Mirror tree is -:";
			b.inOrder(r);
			break;

		case 7:
			b.display();
			break;

		case 0: return 0;

		default:
			cout << "\n Please Enter Correct Choice";
			break;
		}
	}
}
