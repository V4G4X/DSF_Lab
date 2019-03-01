//============================================================================
// Name        : Assignment5.cpp
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node{
	int d;
	node *rp,*lp;
	friend class ET;
};

class ET{
	node *root;
public:
	ET(){
		root=NULL;
}
	node *getnode(){
		node *n;
		n=new node;
		n->lp=n->rp=NULL;
		cout<<"\nEnter Data:";
		cin>>n->d;
		return n;
	}
	void insert(node *r,node*n);
	void inorder(node *r);
	void displev();
	//void mirror(node *r);
	void delnode();
	node* getroot(){
		return root;
	}
};
void ET::insert(node *r,node*n)
{
	if(r->d>n->d)
	{
		if(r->lp==NULL)
			r->lp=n;
		else
			insert(r->lp,n);
	}
	else
	{
		if(r->d<n->d)
		{
			if(r->rp==NULL)
				r->rp=n;
			else
				insert(r->rp,n);
		}
		else
		{
			cout<<"\nDuplicate element found";
			delete(n);
			break;
		}
	}
}
void ET::displev()
{
	node *q[50],*root;
	int f,r;
	q[0]=root;f=r=0;
	while(f<=r)
	{
		r=q[f];f++;
		cout<<"r->d"<<" ";
		if(root->lp!=NULL)
		{
			r++;q[r]=root->lp;
		}
		if(root->rp!=NULL)
		{
			r++;q[r]=root->rp;
		}
	}
}

void ET::delnode()
{
	node *r,*p;
	int data,cont,i=0;
	do
	{
		inorder(root);
		cout<<"\nEnter Data:";
		cin>>data;
		p=r=root;
		while(r!=NULL)
		{
			if(r->d==data)
				break;
			else
			{
				if(r->d>data)
				{
					p=r;r=r->lp;
					i=1;
				}
				else
				{
					p=r;r=r->rp;
					i=2;
				}
			}
		}
		if(r==NULL)
			cout<<"\n"<<data<<"not present";
		else
		{
			if(i==1)
			{
				p->lp=r->rp;
				if(r->lp!=NULL)
					insert(p,r->lp);
			}
			else
			{
				if(i==2)
				{
					p->rp==r->rp;
					if(r->lp==NULL)
						insert(p,r->lp);
				}
				else
				{
					if(r->rp==NULL)
						root=r->lp;
					else
					{
						root=r->rp;
						if(r->lp!=NULL)
							insert(root,r->lp);
					}
				}

			}
		}
		r->lp=r->rp=NULL;
		delete(r);
		inorder(root);
		cout<<"\ncontinue(1:yes):";
		cin>>cont;

	}while(cont==1);

}

void ET::inorder(node* r)
{
	if(r!=NULL)
	{
		inorder(r->lp);
		cout<<r->d<<" ";
		inorder(r->rp);
	}

}

int main()
{
	ET x;
	int ch,cont;
	do
	{
		cout<<"****************MENU*************\n1.Insert\n2.Inorder\n3.Display level\n4.Delete\n\tEnter Choice:";
		cin>>ch;
		switch(ch){
		case 1:
			x.insert(x.getroot(),n);
		}

	}while(ch!=5);

}





