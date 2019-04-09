/*
 * dijkstra.h
 *
 *  Created on: 09-Apr-2019
 *      Author: v4g4x
 */

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <iostream>
#define infinity 1000
using namespace std;

class dijikstras// class dijikstras
{
private:
    int a_mat[20][20],no;
public:
	//function declaration (public members)
    void create();
    void insert_d();
    void display();
    void dijikstras_algo(int);


};

void dijikstras::create()//function for creating adjacency matrix
{
    cout<<endl;
    cout<<"HOW MAY CITIES YOU WANT TO ENTER"<<endl;
    cin>>no;

    for(int i=0;i<no;i++)
        for(int j=0;j<no;j++)
            a_mat[i][j]=-1;

    cout<<endl;
    cout<<"Adjecency Matrix :"<<endl;

    for(int i=0;i<no;i++)// displays adjecency matrix
    {
        for(int j=0;j<no;j++)
        {
           cout<<a_mat[i][j];
           cout<<"\t";
        }
        cout<<"\n";
    }
}

void dijikstras::insert_d()//insertion function
{
    int i=0,j=0,k=0,l=0;
    while(1)
    {
        cout<<"ENTER THE SOURCE \t";
        cin>>i;
        cout<<endl;
        cout<<"ENTER THE DESTINATION \t"<<endl;
        cin>>j;
        cout<<endl;
        if(a_mat[i][j]!=-1)// validation of duplicate nodes present
        {
            cout<<endl;
            cout<<"YOU HAVE ALREADY ENTERED DISTANCE FOR THESE TWO CITIES ENTER THE VALID CITIES AGAIN"<<endl;
        }
        else
            break;
    }
    cout<<"ENTER THE DISTANCE \t";
    cin>>k;
    a_mat[i][j]=k;
    a_mat[j][i]=k;
}

void dijikstras::display()// display of adjecency matrix after the insertion of distances between the nodes
{
    for(int i=0;i<no;i++)
    {
        for(int j=0;j<no;j++)
        {
           cout<<a_mat[i][j];
           cout<<"\t";
        }
        cout<<"\n";
    }
}

void dijikstras::dijikstras_algo(int start_node)// dijikstras algo to find minimum spanning tree
{
    int visited[no],distance[no],parent[no],cost[20][20],count=0,min_distance,nextnode;
     for(int i=0;i<no;i++)// corresponding cost matrix
    {
        for(int j=0;j<no;j++)
        {
            if(i==j)
            {
                cost[i][j]=0;//for diag ele cost=0
            }
            else if(a_mat[i][j]==-1)
            {
                cost[i][j]=infinity;
            }
            else
            {
                cost[i][j]=a_mat[i][j];
            }
        }
    }
    for(int i=0;i<no;i++)// displaying cost matrix
    {
        for(int j=0;j<no;j++)
        {
           cout<<cost[i][j];
           cout<<"\t";
        }
        cout<<"\n";
    }

    for(int i=0;i<no;i++)
    {
        distance[i]=cost[start_node][i];//distance array
        visited[i]=0;
        parent[i]=start_node;//parent array
    }
    distance[start_node]=0;
    visited[start_node]=1;
    count=1;



    while(count<no-1)// to create mst
    {
        min_distance=infinity;
        for(int i=0;i<no;i++)//  to find next node
        {
            if(distance[i]<min_distance && !visited[i])
            {
                min_distance=distance[i];
                nextnode=i;
            }
        }
        visited[nextnode]=1;//marking next node as 1
        for(int i=0;i<no;i++)//loop to set distance array according to next node
        {
            if(!visited[i])
            {
                if(min_distance+cost[nextnode][i]<distance[i])
                {
                    distance[i]=min_distance+cost[nextnode][i];
                    parent[i]=nextnode;
                }
            }
        }
        count++;
    }
    int j=0;
    for(int i=0;i<no;i++)// to display single source multiple destination mst
	{
		if(i!=start_node)
		{
			cout<<"\n\n\tDistance of node "<<i<<" from node "<<start_node<<" is : "<<distance[i];
			cout<<"\n\tIts path is : "<<i;
			j=i;
			do
			{
				j=parent[j];
				cout<<"<-"<<j;
			}while(j!=start_node);
		}
	}

}



#endif /* DIJKSTRA_H_ */
