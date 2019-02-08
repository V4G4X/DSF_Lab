//============================================================================
// Name        : Assignment1.cpp
// Description : Expression Conversion in C++, Using StackADT
//============================================================================

#include <iostream>
#include "stack.h"
#include "stack.cpp"

using namespace std;

class expression{

	char infix[50],postfix[50],prefix[50];
public:
	void evaluate_pre();
	void evaluate_post();
	void display_infix();
	void display_prefix();
	void display_postfix();
	void i_prefix();
	void input();
	void i_postfix();
	int isvalid();
};

int precedence(char c){
	if(c=='+' || c=='-')
		return 1;
	else if(c=='*' || c=='/' || c=='%')
		return 2;
	else if(c=='^')
		return 3;
}

int isoperator(char c){
	if(c=='+' || c=='-' || c=='/' || c=='*' || c=='^' || c=='%')
		return 1;
	return 0;
}

int associativity(char c){
	if(c=='+'|| c=='-' || c=='*' || c=='/' || c=='%')
		return 1;
	return 2;
}

int length_exp(char infix[]){
	int i=0;
	while(infix[i]!='\0')
		i++;
	return i;
}

void expression::evaluate_pre(){
	char ch;
	int op1,op2,c;
	int res=0;
	stack<int>r;
	int length=length_exp(prefix);
	while(length>=0)	{
		ch=prefix[length-1];
		if(isoperator(ch)){
			switch(ch){
			case '+':
				op1=r.pop();
				op2=r.pop();
				res=op1+op2;
				r.push(res);
				break;
			case '-':
				op1=r.pop();
				op2=r.pop();
				res=op1-op2;
				r.push(res);
				break;
			case '*':op1=r.pop();
			op2=r.pop();
			res=op1*op2;
			r.push(res);
			break;
			case '/':op1=r.pop();
			op2=r.pop();
			res=op1/op2;
			r.push(res);
			break;
			case '^':op1=r.pop();
			op2=r.pop();
			res=op1;
			while(op2>1){
				res=res*op1;
				op2--;
			}
			r.push(res);
			break;
			case '%':op1=r.pop();
			op2=r.pop();
			res=op1%op2;
			r.push(res);
			break;
			}
		}
		else if(isalnum(ch)){
			if(isalpha(ch)){
				cout<<"\nEnter value of "<<ch;
				cin>>c;
				r.push(c);
			}
			else
				r.push(ch-'0');

		}
		length=length-1;
	}
	cout<<"\nEvaluation of prefix is :"<<r.pop();
}

void expression::evaluate_post(){
	char ch;
	int op1,op2,c;
	int res=0;
	int i=0;
	stack<int>r;

	while(postfix[i]!='\0'){
		ch=postfix[i];
		if(isoperator(ch)){
			switch(ch){
			case '+':
				op2=r.pop();
				op1=r.pop();
				res=op1+op2;
				r.push(res);
				break;
			case '-':
				op2=r.pop();
				op1=r.pop();
				res=op1-op2;
				r.push(res);
				break;
			case '*':op2=r.pop();
			op1=r.pop();
			res=op1*op2;
			r.push(res);
			break;
			case '/':op2=r.pop();
			op1=r.pop();
			res=op1/op2;
			r.push(res);
			break;
			case '^':op2=r.pop();
			op1=r.pop();
			res=op1;
			while(op2>1){
				res=res*op1;
				op2--;
			}
			r.push(res);
			break;
			case '%':op2=r.pop();
			op1=r.pop();
			res=op1%op2;
			r.push(res);
			break;
			}
		}
		else if(isalnum(ch)){
			if(isalpha(ch)){
				cout<<"\nEnter value of "<<ch;
				cin>>c;
				r.push(c);
			}
			else
				r.push(ch-'0');

		}
		i++;

	}
	cout<<"\nEvaluation of postfix is :"<<r.pop();
}

int alphanum(char infix[]){
	int i=0,k=0;
	char ch;
	while(infix[i]!='\0'){
		ch=infix[i];
		if(ch=='(' || ch==')')
			i++;
		else{
			i++;
			k++;
		}
	}
	return k;
}

void expression::i_prefix(){
	stack  <char>s;
	char ch;
	int length=length_exp(infix);
	int k=alphanum(infix);
	prefix[k]='\0';
	k--;
	while(length>=0){
		ch=infix[length-1];
		if(isalnum(ch)){
			prefix[k]=ch;
			k--;
		}
		else if(isoperator(ch)){
			if(s.isempty() || s.peep()==')'){
				s.push(ch);
			}
			else if(precedence(s.peep())<precedence(ch))
				s.push(ch);
			else if(precedence(s.peep())>precedence(ch)){
				prefix[k]=s.pop();
				k--;
				if(!s.isempty()){
					if(precedence(s.peep())==precedence(ch)){
						prefix[k]=s.pop();
						k--;
					}
				}
				s.push(ch);
			}
			else if(precedence(s.peep())==precedence(ch)){
				if(associativity(ch)==2){
					prefix[k]=s.pop();
					s.push(ch);
					k--;
				}
				else
					s.push(ch);
			}
		}
		else if(ch==')')
			s.push(ch);
		else if(ch=='('){
			while(s.peep()!=')'){
				prefix[k]=s.pop();
				k--;
			}
			s.pop();
		}
		length--;
	}
	while(!s.isempty()){
		prefix[k]=s.pop();
		k--;
	}
	display_prefix();
}

void expression::i_postfix(){
	char ch;
	stack  <char>s;
	int i=0,k=0;
	while(infix[i]!='\0'){
		ch=infix[i];
		if(isalnum(ch)){
			postfix[k]=ch;
			k++;
		}
		else if(ch=='('){
			s.push(ch);
		}
		else if(ch==')'){
			while(s.peep()!='('){
				postfix[k]=s.pop();
				k++;
			}
			s.pop();
		}
		else if(isoperator(ch)){

			if(s.isempty() || s.peep()=='(')
				s.push(ch);
			else if(precedence(s.peep())<precedence(ch))
				s.push(ch);
			else if(precedence(s.peep())>precedence(ch)){
				postfix[k]=s.pop();
				k++;
				if(!s.isempty()){
					if(precedence(s.peep())==precedence(ch)){
						postfix[k]=s.pop();
						k++;
					}
				}
				s.push(ch);

			}
			else if(precedence(s.peep())==precedence(ch)){
				if(associativity(ch)==1){
					postfix[k]=s.pop();
					k++;
					s.push(ch);
				}
				else
					s.push(ch);
			}
		}

		else if(s.isempty() || s.peep()=='(')
			s.push(ch);
		i++;
	}
	while(!s.isempty()){
		postfix[k]=s.pop();
		k++;
	}
	postfix[k]='\0';
	display_postfix();
}

int expression::isvalid(){
	int i=0,op=0,opnd;
	while(infix[i]!='\0'){
		char ch=infix[i];
		if(isoperator(ch))
			op++;
		else if(isalnum(ch))
			opnd++;
		if(isalnum(ch) || isoperator(ch) || ch=='(' || ch==')')
			return 1;
		i++;
	}
	/*if(!opnd==op+1)
	{
		return 0;
	}*/

}

int isalnum(char c){
	if((c>='A' && c<='Z')|| (c>='a' && c<='z')|| (c>='0' && c<='9'))
		return 1;
	return 0;
}

void expression::input(){
	cout<<"Enter the expression :";
	cin>>infix;
	if(isvalid())	{
		display_infix();
	}
}

void expression::display_infix(){
	int j=0;
	cout<<"\nEntered infix expression is :";
	while(infix[j]!='\0'){
		cout<<infix[j];
		j++;
	}
}

void expression::display_postfix(){
	int j=0;
	cout<<"\nPostfix expression is :";
	while(postfix[j]!='\0'){
		cout<<postfix[j];
		j++;
	}

}

void expression::display_prefix(){
	int j=0;
	cout<<"\nPrefix expression is :";
	while(prefix[j]!='\0'){
		cout<<prefix[j];
		j++;
	}
}

int main(){
	int ch,flag=0;
	expression e;
	do{
		cout<<"\n1.Input\n2.Postfix conversion\n3.Prefix conversion\n4.Postfix evaluation\n5.Prefix evaluation\n6.Exit";
		cout<<"\nEnter your choice :";
		cin>>ch;
		if(flag==0 && ch!=1){
			cout<<"\nEnter input first";
			ch=1;
		}
		switch(ch){
		case 1:
			e.input();
			if(!e.isvalid()){
				cout<<"\nInvalid Expression";
				break;
			}
			flag=1;
			break;
		case 2:
			e.i_postfix();
			flag=1;
			break;
		case 3:
			e.i_prefix();
			flag=1;
			break;
		case 4:
			e.i_postfix();
			e.evaluate_post();
			flag=1;
			break;
		case 5:
			e.i_prefix();
			e.evaluate_pre();
			flag=1;
			break;
		case 6:
			break;
		default:
			cout<<"\nInvalid choice";
		}
	}while(ch!=6);
	return 0;
}
/////////////////END/////////////////









































/*     OUTPUT

1.Input
2.Postfix conversion
3.Prefix conversion
4.Postfix evaluation
5.Prefix evaluation
6.Exit
Enter your choice :1
Enter the expression :((A+B)+C*(D/E))+F

Entered infix expression is :((A+B)+C*(D/E))+F
1.Input
2.Postfix conversion
3.Prefix conversion
4.Postfix evaluation
5.Prefix evaluation
6.Exit
Enter your choice :2

Postfix expression is :AB+CDE/*+F+
1.Input
2.Postfix conversion
3.Prefix conversion
4.Postfix evaluation
5.Prefix evaluation
6.Exit
Enter your choice :3

Prefix expression is :+++AB*C/DEF
1.Input
2.Postfix conversion
3.Prefix conversion
4.Postfix evaluation
5.Prefix evaluation
6.Exit
Enter your choice :4

Postfix expression is :AB+CDE/*+F+
Enter value of A14

Enter value of B12

Enter value of C10

Enter value of D8

Enter value of E6

Enter value of F4

Evaluation of  postfix is :40
1.Input
2.Postfix conversion
3.Prefix conversion
4.Postfix evaluation
5.Prefix evaluation
6.Exit
Enter your choice :4

Postfix expression is :AB+CDE/*+F+
Enter value of A14

Enter value of B12

Enter value of C10

Enter value of D8

Enter value of E6

Enter value of F4

Evaluation of  postfix is :40
1.Input
2.Postfix conversion
3.Prefix conversion
4.Postfix evaluation
5.Prefix evaluation
6.Exit
Enter your choice :1
Enter the expression :A*(B+C)-D/E

Entered infix expression is :A*(B+C)-D/E
1.Input
2.Postfix conversion
3.Prefix conversion
4.Postfix evaluation
5.Prefix evaluation
6.Exit
Enter your choice :2

Postfix expression is :ABC+*DE/-
1.Input
2.Postfix conversion
3.Prefix conversion
4.Postfix evaluation
5.Prefix evaluation
6.Exit
Enter your choice :3

Prefix expression is :-*A+BC/DE
1.Input
2.Postfix conversion
3.Prefix conversion
4.Postfix evaluation
5.Prefix evaluation
6.Exit
Enter your choice :3

Prefix expression is :-*A+BC/DE
1.Input
2.Postfix conversion
3.Prefix conversion
4.Postfix evaluation
5.Prefix evaluation
6.Exit
Enter your choice :4

Postfix expression is :ABC+*DE/-
Enter value of A14

Enter value of B12

Enter value of C10

Enter value of D8

Enter value of E6

Evaluation of  postfix is :307
1.Input
2.Postfix conversion
3.Prefix conversion
4.Postfix evaluation
5.Prefix evaluation
6.Exit
Enter your choice :1
Enter the expression :((A+B)*(C+D)/(E-F))+G

Entered infix expression is :((A+B)*(C+D)/(E-F))+G
1.Input
2.Postfix conversion
3.Prefix conversion
4.Postfix evaluation
5.Prefix evaluation
6.Exit
Enter your choice :2

Postfix expression is :AB+CD+*EF-/G+
1.Input
2.Postfix conversion
3.Prefix conversion
4.Postfix evaluation
5.Prefix evaluation
6.Exit
Enter your choice :3

Prefix expression is :+/*+AB+CD-EFG
1.Input
2.Postfix conversion
3.Prefix conversion
4.Postfix evaluation
5.Prefix evaluation
6.Exit
Enter your choice :4

Postfix expression is :AB+CD+*EF-/G+
Enter value of A14

Enter value of B12

Enter value of C10

Enter value of D8

Enter value of E6

Enter value of F4

Enter value of G2

Evaluation of  postfix is :236
1.Input
2.Postfix conversion
3.Prefix conversion
4.Postfix evaluation
5.Prefix evaluation
6.Exit
Enter your choice :6

 */
