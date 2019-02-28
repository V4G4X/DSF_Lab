#ifndef TREE_H_
#define TREE_H_

typedef struct node1{
	char data;
	node1 *left,*right;
}node1;

class btree{
	node1 *root;
public:
	btree();
	node1* maketree(char x);
	node1 *getroot(){
		return root;
	};
	bool isOperand(char x);
	bool isOperator(char x);

	void postfix();
	void prefix();

	void R_preorder(node1 *p);
	void R_postorder(node1 *p);
	void R_inorder(node1 *p);

	void NR_preorder();
	void NR_postorder();
	void NR_inorder();

	virtual ~btree();
};

#endif /* BTREE_H_ */
