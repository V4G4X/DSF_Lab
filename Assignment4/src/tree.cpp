#include "tree.h"
#include "stack.h"
#include "stack.cpp"

btree::btree(){
	root=NULL;
}

btree::~btree(){

}

bool btree :: isOperand(char x){
	if( (x>='0' && x<='9')  || (x>='a' && x<='z')||(x>='A' && x<='Z') )
		return true;
	else
		return false;
}
bool btree :: isOperator(char x){
	if(x=='^' || x=='*' || x=='/' || x=='+' || x=='-' || x=='%' || x=='(' || x== ')')
		return true;
	else
		return false;
}
node1 * btree :: maketree(char x){
	node1* temp = new node1;
	temp->left = NULL;
	temp->right = NULL;
	temp->data = x;
	return temp;
}
void btree :: R_inorder(node1 *p){
	if(p!=NULL){
		//left,root,right
		R_inorder(p->left);
		cout<<p->data<<" ";
		R_inorder(p->right);node1* getroot();
	}
}
void btree :: R_preorder(node1 *p){
	if(p!=NULL){
		//root,left,right
		cout<<p->data<<" ";
		R_preorder(p->left);
		R_preorder(p->right);
	}
}
void btree :: R_postorder(node1 *p){
	if(p!=NULL){
		//left,right,root
		R_postorder(p->left);
		R_postorder(p->right);
		cout<<p->data<<" ";
	}node1* getroot();
}
void btree :: postfix(){
	string post;
	stack<node1*>s;
	cout<<"\n\tEnter your post_fix expression :: ";
	cin>>post;
	char x;
	int i=0;
	while(post[i]!='\0'){
		x=post[i];
		if(isOperand(x)){
			// if operand found then push it directly into stack
			node1* temp = maketree(x);
			s.push(temp);
		}
		if(isOperator(x)){
			//if operator found then pop two operands and assign themnode1* getroot();
			// the right and left link and again push the whole node
			// into the stack
			node1 * temp = maketree(x);
			temp->right=s.pop();
			temp->left=s.pop();
			s.push(temp);
		}
		i++;
	}
	//final node at top of stack will be the root node of the tree
	root=s.pop();
}
void btree::NR_inorder(){
	node1 *p=root;
	stack<node1*>s;
	if(p==NULL){
		cout<<"\n\tEmpty";
		return;
	}
	do{
		//1st go to leftmost node
		while(p!=NULL){
			s.push(p);
			p=p->left;
		}
		if(!s.isempty()){
			//pop and display
			p=s.pop();
			cout<<p->data<<" ";
			p=p->right; //go to right
		}
	}while(p!=NULL || (!s.isempty()));
}

void btree::NR_postorder(){
	stack<node1*>s;
	node1 *p=root;
	node1 *q=root;
	if(p==NULL){
		cout<<"Empty";
		return;
	}
	s.push(p);
	while(!s.isempty()){
		p=s.pop();
		if(p->right==NULL && p->left==NULL){
			q=p;
			cout<<" "<<p->data;
		}
		else{
			if(p->right==q || p->left==q){
				q=p;
				cout<<" "<<p->data;
			}
			else{
				s.push(p);
				if(p->right)
					s.push(p->right);
				if(p->left)
					s.push(p->left);
			}
		}
	}
}

void btree::NR_preorder(){
	stack<node1*>s;
	node1* p=root;
	if(p==NULL){
		cout<<"Empty";
		return;
	}
	//start from root push it in stack
	s.push(p);
	while(!s.isempty()){
		//pop and display initial condition of root will be satisfied here
		p=s.pop();
		cout<<p->data<<" ";
		//push right and then left coz preorder is rt-l-r
		if(p->right!=NULL)
			s.push(p->right);
		if(p->left!=NULL)
			s.push(p->left);
	}
}

void btree :: prefix(){
	string pre;
	stack<node1*>s;
	cout<<"\n\tEnter your pre_fix expression :: ";
	cin>>pre;
	char x;
	int i=0;
	while(pre[i]!='\0')
		i++;
	i--;
	while(i>=0){
		x=pre[i];
		if(isOperand(x)){
			// if operand found then push it directly into stack
			node1* temp = maketree(x);
			s.push(temp);
		}
		if(isOperator(x)){
			//if operator found then pop two operands and assign them
			// the left and right link and again push the whole node
			// into the stack
			node1 * temp = maketree(x);
			temp->left=s.pop();
			temp->right=s.pop();
			s.push(temp);
		}
		i--;
	}
	//final node at the top of stack will be the root node of the tree
	root=s.pop();
}
