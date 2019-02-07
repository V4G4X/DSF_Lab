//============================================================================
// Name        : Assignment3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "bintree.h"
#include "bintree.cpp"

using namespace std;

int main(){
	int ch;
	bin_tree <int>b;
	int data;
	do{
		cout<<"\nEnter your choice :";
		cout<<"\n1.Insert\n2.Insert Recursive\n3.Display\n4.Copy\n5.Exit";
		cin>>ch;
		switch(ch){
		case 1:
			cout<<"\nEnter data :";
			cin>>data;
				b.insert(data);
			break;
		case 2:
			cout<<"\nEnter data :";
			cin>>data;
			b.call_insert_rec(data);
			break;
		case 3:
			b.display();
			break;
		case 4:
			bin_tree<int>* cp = b.call_copy();
			cp->display();
			break;
		}
	}while(ch!=5);
	return 0;
}
