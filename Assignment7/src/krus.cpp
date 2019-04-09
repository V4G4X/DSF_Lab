/*
 * krus.cpp
 *
 *  Created on: 05-Mar-2019
 */
#include<iostream>
#include "krus.h"
using namespace std;

krus::krus() {
	// TODO Auto-generated constructor stub

}

krus::~krus() {
	// TODO Auto-generated destructor stub
}

void krus::create(int a[30][30],int n)  //creates a input matrix
{


    int i,j;
    for(i=0;i<n;i++)  //input for row
    {

        for(j=i;j<n;j++)   //input for coloumn
        {

            if(i==j)   //validation if row and coloumn are same put weight=0
            {
                a[i][j]=a[j][i]=0;
            }
            else
            {

                cout<<"\nEnter the weight for["<<i<<"]["<<j<<"]";
                cin>>a[i][j];
                a[j][i]=a[i][j];  //a[i][j] is same as a[j][i]
            }
        }
    }

}
void krus::display(int a[30][30],int n)   //displays adjacency matrix
{

    cout<<"\nThe weights of entered edges are"<<endl;
    int i,j;
    for(i=0;i<n;i++)
    {

        for(j=0;j<n;j++)
        {

            cout<<a[i][j];
            cout<<"\t";
        }
        cout<<"\n";

    }
}
void krus::convert(int a[30][30],struct edge e[20],int n)  //converts elements into sparse
{
	int k=1;
	int i,j;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]!=0)
			{
				e[k].startnode=i;
				e[k].endnode=j;
				e[k++].weight=a[i][j];//copying the non zero values

			}
		}
	}e[0].startnode=n;
	e[0].endnode=n;
e[0].weight=k-1;

}
void krus::display1(struct edge e[20])   //function for displaying sparse matrix
{
	int i;

	cout<<"Startnode|"<<"\t\t"<<"Endnode|"<<"\t\t"<<"Weight|"<<endl;
	cout<<e[0].startnode<<"\t\t\t|"<<e[0].endnode<<"\t\t\t|"<<e[0].weight<<"\n";
	cout<<"--------------------------------------------------------------------"<<endl;
	for(i=1;i<=e[0].weight;i++)
	{
		cout<<e[i].startnode<<"\t\t\t|"<<e[i].endnode<<"\t\t\t|"<<e[i].weight<<endl;

	}


}
void krus::bubblesort(struct edge e[],int n)  //sorting elements of sparse matrix using
{                                              //bubble sort
	struct edge temp;
	for(int i=0;i<e[0].weight;i++)
	{
		for(int j=1;j<e[0].weight;j++)
		{
			if(e[j].weight>e[j+1].weight)
			{
				temp=e[j];   //swapping logic
				e[j]=e[j+1];
				e[j+1]=temp;
			}
		}
	}


	for(int i=0;i<e[0].weight;i++)
	{
		cout<<e[i].startnode<<"\t\t\t"<<e[i].endnode<<"\t\t\t"<<e[i].weight<<"\n";
	}

}
void krus::union1(int c[],int pv1,int pv2,int n)  //function for union
{
	for(int i=0;i<n;i++)
	{
		if(c[i]==pv2)
			c[i]=pv1;
	}
}
int krus::find(int c[],int v)
{
	int x;
	x=c[v];
	return x;
}
int krus::kruskal(struct edge e[],int n)  //kruskals algo
{
	int pv1,pv2,c[50],mincost=0;
	for(int i=0;i<n;i++)
		c[i]=i;
	for(int i=0;i<e[0].weight;i++)
	{
		pv1=find(c,e[i].startnode);
		pv2=find(c,e[i].endnode);
		if(pv1!=pv2)
		{
			cout<<e[i].startnode<<"\t"<<e[i].endnode<<"\t"<<e[i].weight<<"\n";
			mincost=mincost+e[i].weight;
			n=n+1;
			union1(c,pv1,pv2,n);
		}
	}
	return mincost;
}
