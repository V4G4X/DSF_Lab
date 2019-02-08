/*
 * stack.cpp
 */
#include "linked.h"
#include "linked.cpp"
#include "stack.h"
template<class T>
void stack<T>::push(T x)
{
	l.insert_first(x);
}

template<class T>
T stack<T>::pop()
{
	T a;
	a=l.del_first();
	return a;
}
template<class T>
T stack<T>::isempty()
{
	int a;
	a=l.isempty();
	return a;
}
template<class T>
T stack<T>::peep()
{
	T a;
	a=l.display_first();
	return a;
}
template<class T>
stack<T>::stack() {
	// TODO Auto-generated constructor stub

}
template<class T>
stack<T>::~stack() {
	// TODO Auto-generated destructor stub
}

