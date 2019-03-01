/*
 * Graph.cpp
 *
 *  Created on: 01-Mar-2019
 *      Author: v4g4x
 */

#include <iostream>
#include <strings.h>
#include <string.h>
#include "Graph.h"
#define MAX 50
using namespace std;

int Graph::getIndex(char name[]){
	int i;
	for(i=0 ; i<node_len ; i++)
		if(strcasecmp(name,names[i])==0)
			return i;
	return -1;
}

Graph::Graph(int c,char v[][MAX]){
	node_len = c;
	int i;
	names = new char*[c];
	for(i=0  ; i< c ; i++){
		names[i] = new char[MAX];
		names[i] = strcpy(names[i],v[i]);
	}
	adj = new int*[c];
	for(i=0 ; i<c ; i++)
		adj[i] = new int[c];
}

bool Graph::connect(char name1[],char name2[] , int w){
	int a = getIndex(name1);
	int b = getIndex(name2);
	if(a==-1 || b==-1)			//Case where atleast one name is wrong
		return 1;
	adj[a][b] = w;
	adj[b][a] = w;
	adj[a][a] = 0;				//In case the user send the name twice(Bad User), we handle that exception
	adj[b][b] = 0;
	return 0;
}
