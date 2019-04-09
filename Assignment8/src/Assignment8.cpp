//============================================================================
// Name        : dijlkshtra.cpp
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "dijkstra.h"


int main()
{
    int no1,start_node,choice;
    dijikstras d;


    while(1)
    {
  		cout<<"\n____MENU____";
  		cout<<"\n1.Create\n2.Insert Vertices\n3:Display Shortest paths\n4:Exit : ";
      cout<<"\nEnter your choice::";
  		cin>>choice;

  		switch(choice)
  		{
        case 1:
  	        d.create();//creation of adjecency matrix
  	        break;
  	    case 2://insertion of distances between the nodes
            cout<<"HOW MANY DISTANCES YOU WANT TO ENTER"<<endl;
            cin>>no1;
            for(int i=0;i<no1;i++)
            {
                d.insert_d();
            }
  	        break;
  	    case 3:// dijikstras algorithm to find minimum spanning tree
            cout<<endl;
            cout<<"ENTER THE STARTING NODE"<<endl;
            cin>>start_node;
            d.dijikstras_algo(start_node);
            break;
        case 4:
            return 0;
  		}
    }
    cout<<"\n";
    return 0;
}


