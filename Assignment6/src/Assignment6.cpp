//============================================================================
// Name        : Assignment6.cpp
// Author      : Varun Gawande
// Description : FB Graph in C++, Ansi-style
//============================================================================

#include <iostream>
#include "graph.h"
#include <ctime>
#include <string.h>
using namespace std;

int main() {
	cout<<"Welcome to FB sub-system\n";
	int ch;
	do{
		cout<<"1.Create User List\n2.Create Friend Relations\n3.Find User with Max Friends(Uses BFS)\n4.Find Max and Min Comments(Uses DFS)\n5.Find Users with Birthday this month\n6.Exit"<<endl;
		FB network;
		cin>>ch;
		cin.ignore();
		switch(ch){
		case 1:{
			int n;
			cout<<"Enter total number of Users: ";
			cin>>n;
			cin.ignore();
			network.create_ulist(n);
			break;
		}
		case 2:{
			network.create_friendlist();
			break;
		}
		case 3:{
			int max;
			char *maxFriend = network.maxFriend(max);
			cout<<maxFriend<<"has most friends i.e"<<max<<".\n";
			break;
		}
		case 4:{
			int less,large;
			char *least=NULL,*largest=NULL;
			network.maxminComments(less,least,large,largest);
			cout<<least<<"has least comments i.e"<<less<<".\n";
			cout<<largest<<"has most comments i.e"<<large<<".\n";
			break;
		}
		case 5:{
			int m;
			cout<<"Enter current month number: ";
			cin>>m;
			cin.ignore();
			network.birthdayMonth(m);
			break;
		}
		case 6:{
			cout<<"Exiting Program\n";
			break;
		}
		default:{
			cout<<"Enter Proper choices\n";
			break;
		}
		}
	}while(ch!=6);
	return 0;
}
