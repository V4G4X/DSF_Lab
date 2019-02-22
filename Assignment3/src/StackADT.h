//Stack ADT
/*
NAME:Sampada Gaikwad
ROLLNO:23118
*/
#ifndef STACKADT_H_INCLUDED
#define STACKADT_H_INCLUDED
#define MAX 50

//Structure for stack
template<class T>
struct Stack
{
		int top;
		T arr[MAX];
};

//Class Stack
template<class T>
class stack{
	private:
        Stack<T> s;   //Object of Stack
	public:
		stack();      //Constructor
		//Methods for stack operations
		void push(T);
		T pop();
		T peep();
		int isEmpty();
		int isFull();
};

#endif // STACKADT_H_INCLUDED
