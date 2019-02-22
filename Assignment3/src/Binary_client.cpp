//============================================================================
// Name        : BinaryTree.cpp
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BSTADT.h"
#include "DLLADT.h"
#include "BSTImpl.cpp"
#include "DLLImpl.cpp"
#include "StackADT.h"
#include "StackImpl.cpp"
using namespace std;

int main() {
	BT<int> bo;     //Object of BT
    int choice;
        cout<<"\n*****************************BINARY TREE******************************************";
	do{
        cout<<"\n1.CREATE TREE\n2.DISPLAY RECURSIVE\n3.DISPLAY NON RECURSIVE\n4.LEAF NODES\n5.INSERT\n6.HEIGHT OF TREE\n7.COPY TREE\n8.EXIT"<<endl;
        cout<<"\n ENTER YOUR CHOICE:";
        cin>>choice;

        switch(choice){
        case 1:            //Calling Create function
            bo.Create();
            break;
        case 2:            //Calling Display Recursive function
            cout<<"\n--------------------------------------------------------------------------------------";
            cout<<"\nPreorder:- ";
            bo.DisplayPreorder();
            cout<<endl<<"Inorder:- ";
            bo.DisplayInorder();
            cout<<endl<<"Postorder:- ";
            bo.DisplayPostorder();
            cout<<"\n--------------------------------------------------------------------------------------";
            break;
        case 3:             //Calling Display Non-Recursive function
            cout<<"\n--------------------------------------------------------------------------------------";
            cout<<"\nPreorder:- ";
            bo.Preorder();
            cout<<endl<<"Inorder:- ";
        	bo.Inorder();
			cout<<endl<<"Postorder:- ";
			bo.Postorder();
           cout<<"\n--------------------------------------------------------------------------------------";
			break;
        case 4:           //Calling Display Leaf-Nodes function
            cout<<"\n Leaf nodes are:-";
            bo.Leafnodes();
            break;
        case 5:         //Calling Insert function
            bo.Insert();
            break;
        case 6:           //Calling Display Height function
            bo.Height();
            break;
        case 7:           //Calling Create Copy function
            cout<<"\n--------------------------------------------------------------------------------------";
            bo.CopyTree();
            cout<<"\n--------------------------------------------------------------------------------------";
            break;
        case 8:cout<<"\n*****************************THANK YOU******************************************";
               break;
        default:cout<<"\n INVALID CHOICE";
        }

	}while(choice != 8);
	return 0;
}

