#include <iostream>
#include "krus.h"
//#include "krus.cpp"
using namespace std;

int main()
{
    krus k;   //object of class kruskal
    int ch,n;
    struct edge e[20];
    int a[30][30];
    do
    {


    cout<<"----------------MENU----------";//menu
    cout<<"\n1.Create\n2.Display\n3.Convert into sparse\n4.Display\n5.Sorted weights\n6.Minimum cost\n";
    cout<<"\nEnter your choice\n";
    cin>>ch;
    switch(ch)
    {

    case 1:
        cout<<"\nEnter number of nodes you want to enter\n";
        cin>>n;
        k.create(a,n);
        break;
    case 2:
        cout<<"Network is";
        k.display(a,n);  //displays adjacency matrix
        break;
    case 3:
	cout<<"\nSparse matrix created!\n";
    	k.convert(a,e,n);   //converts into sparse matrix
    	break;
    case 4:
    	k.display1(e);    //displays sparse matrix
    	break;
    case 5:
    	k.bubblesort(e,n);   //sorting edges using bubble sort
    	break;
    case 6:
    	int mincost;
    	mincost=k.kruskal(e,n);  //finding the min cost using kruskala algo
    	cout<<"Mincost:"<<mincost;
    	break;


    }
    }while(ch!=7);
    return 0;
}
