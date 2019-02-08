/*
 * linked.h
 */

#ifndef LINKED_H_
#define LINKED_H_

template<class T>
struct node
{
	T data;
	 node <T>*next;
};
template<typename T>
class linked
{
	node <T>*head;
public:
	linked();

	T isempty();

	node <T>* getnode(T x);
	void insert_first(T x);
	T del_first();
	T display_first();
	virtual ~linked();
};

#endif /* LINKED_H_ */
