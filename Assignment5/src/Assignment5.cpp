#include <iostream>
using namespace std;
#include "BST_ADT.h"
#include "BST_IMP.cpp"
int main() {
	cout<<"Binary search tree\n";
	Bst<int> obj;
	int op,key;
	do
	{
		cout<<"1.Insert(non-recurrsive)\n";
		cout<<"2.Insert(recurrsive)\n";
		cout<<"3.Display (Traversals)\n";
		cout<<"4.Search element in the tree\n";
		cout<<"5.Delete element from tree\n";
		cout<<"6.Mirror\n";
		cout<<"7.Exit\n";
		cout<<"Enter your choice\n";
		cin>>op;
		switch(op)
		{
			case 1:obj.create_tree();
					break;
			case 2:obj.rec_create();
					break;
			case 3:obj.call_inorder();
					obj.call_preorder();
					obj.call_postorder();
					break;
			case 4:cout<<"Enter key that you want to search\n";
					cin>>key;
					obj.searchbst(key);
					break;
			case 5:cout<<"Enter key that you want to delete\n";
					cin>>key;
					obj.call_delete(key);
					break;
			case 6:obj.call_mirror();
					break;
			case 7:cout<<"Thank you\n";
					break;
			default:cout<<"Invalid input\n";
		}
	}while(op!=7);
	return 0;
}
