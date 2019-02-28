//==========================================================
// Author      : Varun Gawande
//==========================================================
#include <iostream>
#include"tree.h"
using namespace std;

int main(){
	btree b;
	int ch;
	do{
		cout<<"\n1.Create postfix expression \n2.Create prefix expression ";
		cout<<"\n3.Recursive Inorder \n4.Recursive Postorder \n5.Recursive Preorder\n";
		cout<<"6.Non_Rec Preorder \n7.Non_Rec Inorder \n8.Non_Rec Postorder\n9.Exit\n";
		cout<<"\nEnter your choice :: ";
		cin>>ch;
		switch(ch){
		case 1:
			b.postfix();
			break;
		case 2:
			b.prefix();
			break;
		case 3:
			cout<<"\nInorder :: ";
			b.R_inorder(b.getroot());
			break;
		case 4:
			cout<<"\nPost-order :: ";
			b.R_postorder(b.getroot());
			break;
		case 5:
			cout<<"\nPre-order :: ";
			b.R_preorder(b.getroot());
			break;
		case 6:
			cout<<"\nPre-order :: ";
			b.NR_preorder();
			break;
		case 7:
			cout<<"\nInorder :: ";
			b.NR_inorder();
			break;
		case 8:
			cout<<"\nPostorder :: ";
			b.NR_postorder();
			break;
		}
	}while(ch!=9);
	return 0;
}
