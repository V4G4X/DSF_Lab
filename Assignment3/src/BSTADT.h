/*  BTADT File
 *  BTADT.h
 *
 *  Created on: 21-Jan-2019
 *      Author: h9
 */
/*
NAME:Sampada Gaikwad
ROLLNO:23118
*/
#ifndef BSTADT_H_
#define BSTADT_H_
#include "DLLADT.h"
#include "StackADT.h"

//Class for Binary Tree
template<class T>
class BT{
private:
	DLL<T> obj;     //DLL object
public:
    //Methods for operation on tree
	void Create();
	void DisplayInorder();
	void DisplayPreorder();
	void DisplayPostorder();
	void Inorder();
	void Preorder();
	void Postorder();
	void Insert();
	void Leafnodes();
	void Height();
	void CopyTree();
};



#endif /* BSTADT_H_ */
