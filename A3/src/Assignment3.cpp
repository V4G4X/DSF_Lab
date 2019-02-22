//============================================================================
// Name        : Assignment3.cpp
// Author      : soham kotalwar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "tree.h"



int main()  //main function
{
	tree bt;
	int ch;
	int height;
	do{
		cout<<"MENU \n1)Insert\n2)display\n3)Depth\n4)Leaf Nodes\n5)Copy Of Tree\nEnter Your Choice : ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			 bt.insert();
			 bt.preorder(bt.root);
			 cout<<endl;
			break;
		case 2:
			  bt.preorder(bt.root);
			  cout<<endl;
			break;
		case 3:
			height=bt.depth(bt.root);
			cout<<"the Depth is : "<<height<<endl;
			break;
		case 4:
			cout<<"Leaf Nodes Are : ";
			int l;
			l=bt.count(bt.root);
			cout<<endl;
			cout<<"The Total Leaf Nodes Are : "<<l<<endl;
			  break;
		case 5:
			cout<<"Copy of Tree is : ";
			node* p;
			p=bt.copy(bt.root);
			bt.preorder(p);
			cout<<endl;
			  break;
		}

	}while(ch!=6);
}

/***************************** OUTPUT******************************************
 MENU
1)Insert
2)display
3)Depth
4)Leaf Nodes
5)Copy Of Tree
Enter Your Choice : 1
Enter item: 20
20
MENU
1)Insert
2)display
3)Depth
4)Leaf Nodes
5)Copy Of Tree
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 1
Enter item: 25
20 25
MENU
1)Insert
2)display
3)Depth
4)Leaf Nodes
5)Copy Of Tree
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 2
Enter item: 30
20 25 30
MENU
1)Insert
2)display
3)Depth
4)Leaf Nodes
5)Copy Of Tree
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 1
Enter item: 26
20 25 26 30
MENU
1)Insert
2)display
3)Depth
4)Leaf Nodes
5)Copy Of Tree
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 2
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 2
Enter item: 64
20 25 26 30 64
MENU
1)Insert
2)display
3)Depth
4)Leaf Nodes
5)Copy Of Tree
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 1
Enter item: 23
20 25 26 23 30 64
MENU
1)Insert
2)display
3)Depth
4)Leaf Nodes
5)Copy Of Tree
Enter Your Choice : 2
20 25 26 23 30 64
MENU
1)Insert
2)display
3)Depth
4)Leaf Nodes
5)Copy Of Tree
Enter Your Choice : 3
the Depth is : 3
MENU
1)Insert
2)display
3)Depth
4)Leaf Nodes
5)Copy Of Tree
Enter Your Choice : 4
Leaf Nodes Are :    23   64
The Total Leaf Nodes Are : 2
MENU
1)Insert
2)display
3)Depth
4)Leaf Nodes
5)Copy Of Tree
Enter Your Choice : 5
Copy of Tree is : 20 25 26 23 30 64
MENU
1)Insert
2)display
3)Depth
4)Leaf Nodes
5)Copy Of Tree
Enter Your Choice : 6

*/




