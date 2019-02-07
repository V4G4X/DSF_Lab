//============================================================================
// Name        : assignment4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "binarytree.cpp"
using namespace std;

//start main
int main(){
	int n;
	binary_tree<char> b;
	do{
		cout<<"Menu :\n 1.Input prefix\n 2.Input postfix\n 3.Display tree(non recursive)\n 4.Display tree(recursive)\n 5.EXIT";
		cout<<"\nEnter your choice : ";
		cin>>n;
		switch(n){
			case 1:	b.createpre();	//create tree from prefix expression
					break;
			case 2: b.createpost();	//create tree from postfix expression
					break;
			case 3: cout<<"\nInorder traversal : ";
					b.inordern();
					cout<<"\nPreorder traversal : ";
					b.preordern();
					cout<<"\nPostorder traversal : ";
					b.postordern();
					cout<<endl<<endl;
					break;
			case 4: b.display();
					cout<<endl;
					break;
			case 5: break;
		}
	}while(n!=5);
	return 0;
}
