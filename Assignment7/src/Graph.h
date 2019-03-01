/*
 * Graph.h
 *  Created on: 01-Mar-2019
 *      Author: v4g4x
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <string>

using namespace std;


class Graph{
private:
	int node_len;
	char **names;
	int **adj;
	int getIndex(char *name);
public:
	Graph(int c, char v[][50]);
	bool connect(char name1[],char name2[], int w);
};



#endif /* GRAPH_H_ */
