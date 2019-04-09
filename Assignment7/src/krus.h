/*
 * krus.h
 *
 *  Created on: 05-Mar-2019
 */

#ifndef KRUS_H_
#define KRUS_H_
struct edge
{

    int startnode;
    int endnode;
    int weight;
};
class krus    //class kruskals
{
public: //member functn declaration
	krus();
	virtual ~krus();
    void create(int a[30][30],int n);
    void display(int a[30][30],int n);
    void convert(int a[30][30],struct edge e[],int n);
    void display1(struct edge e[]);
    void bubblesort(struct edge e[],int n);
    void union1(int c[],int pv1,int pv2,int n);
    int find(int c[],int v);
    int kruskal(struct edge e[],int n);

};

#endif /* KRUS_H_ */
