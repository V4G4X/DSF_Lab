#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

template<typename T>
struct node{
	T data;
	node<T> *next;
};

template<class T>
class link{
	struct node<T> *head;
public:
	link();
	void display();
	void insert_first(T x);
	T delete_first();
	bool isempty();
	T top_element();

	virtual ~link();
};

#endif /* LINK_H_ */
