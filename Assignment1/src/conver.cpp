//============================================================================
// Name        : coversion.cpp
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stackadt.h"
#include "stackadt.cpp"
#include "linked.cpp"
using namespace std;

//CLASS DEFINITION
class Expression
{
	char infix[30];
	char postfix[30];
	char prefix[30];
public:
	void input();
	void display_postfix();
	void display_prefix();
	void infix_to_postfix(int);
	void infix_to_prefix(int);
	int  postfix_evaluate();
	int  prefix_evaluate();
	bool valid_expression();
	void display_passwise();
};

//MEMBER FUNCTION DEFINITION
void Expression::input()
{
	cout << "INPUT: ";  cin >> infix;
}
void Expression::display_postfix()
{
	cout << "INFIX: " << infix << "\nPOSTFIX: " << postfix << "\n";
}
void Expression::display_prefix()
{
	cout << "INFIX: " << infix << "\nPREFIX: " << prefix << "\n";
}
int Precedence(char ch)
{
	if(ch=='+' || ch=='-')
		return 1;
	else if(ch=='*' || ch==47 || ch=='%')
		return 2;
	else return 3;
}
int Associativity(char ch)
{
	if(ch=='^')		//right to left
		return 1;
	else return 0;	//left to right
}
bool Isalpha(char x)
{
	if((x>=48 && x<=57)||(x>=65 && x<=90)||(x>=97 && x<=122))	//0-9 & A-Z & a-z
		return true;
	else
		return false;
}

bool isdigit(char str){
	if(str>=48 && str<=57)
		return true;
	return false;

}

bool Expression::valid_expression(){
	int i = 0,opd = 0,opt = 0;
	while(infix[i]!='\0'){
		if(Isalpha(infix[i]) )
			opd++;
		else if(infix[i]!='(' && infix[i]!=')')
			opt++;
		i++;
	}
	//no of operands = no of operators + 1
	if(opt!=opd-1)
		return false;
	//consecutive operators or operands
	i=1;
	while(infix[i]!='\0') {
		if(Isalpha(infix[i])==Isalpha(infix[i-1]) && infix[i]!='(' && infix[i-1]!=')')
			return false;
		if(infix[i]==')' && !Isalpha(infix[i-1]))
			return false;
		if(infix[i-1]=='(' && !Isalpha(infix[i]))
			return false;
		i++;
	}
	//expression starts with closing brace
	if(infix[0]==')')
		return false;
	return true;
}

void Expression::infix_to_postfix(int x)
{
	stackadt<char> S;
	stackadt<char> S1;
	int i=0,k=0;

	while(infix[i]!='\0')
	{	if(x==1)
		cout << infix[i] << "\t\t";
	if(infix[i]=='(')			//opening brace
		S.push(infix[i]);
	else if(Isalpha(infix[i]))	//operand
		postfix[k++]=infix[i];
	else if(infix[i]==')') {	//closing brace
		while(S.peep()!='(') {
			postfix[k++]=S.pop();
		}
		S.pop();
	}
	else {									//operator
		if(S.isempty() || S.peep()=='(')
			S.push(infix[i]);
		else if(Precedence(infix[i])>Precedence(S.peep()))
			S.push(infix[i]);				//push over other operator
		else if(Precedence(infix[i])<Precedence(S.peep())) {
			while(!S.isempty() && S.peep()!='(' && Precedence(infix[i])<Precedence(S.peep()) )
				postfix[k++]=S.pop();		//poping till the condition
			if(S.isempty() || Precedence(infix[i])!=Precedence(S.peep()))
				S.push(infix[i]);			//push after poping
			else {
				if(Associativity(infix[i])==0) {//left to right after poping
					postfix[k++]=S.pop();
					S.push(infix[i]);
				}
				else
					S.push(infix[i]);		//right to left after poping
			}
		}
		else {
			if(Associativity(infix[i])==0) {//left to right
				postfix[k++]=S.pop();
				S.push(infix[i]);
			}
			else
				S.push(infix[i]);			//right to left

		}
	}
	if(x==1){
		while(!S.isempty()){
			cout << S.peep();
			S1.push(S.pop());
		}
		while(!S1.isempty()){
			S.push(S1.pop());
		}
		postfix[k]='\0';
		cout << "\t\t\t" << postfix << endl;}
	i++;
	}
	while(!S.isempty())							//poping remaining operator
		postfix[k++]=S.pop();
	postfix[k]='\0';
	if(x==1){
		cout << "---------------------------------------------------" << endl;
		cout << "After Poping remaining operators: " << postfix << endl;}
}


void Expression::infix_to_prefix(int x)
{
	stackadt<char> S;
	stackadt<char> S1;
	int len  = strlen(infix);
	int i=len-1,k=0;

	while(i>=0)
	{	if(x==1)
		cout << infix[i] << "\t\t";
	if(infix[i]==')')				//closing brace
		S.push(infix[i]);
	else if(Isalpha(infix[i]))		//operand
		prefix[k++]=infix[i];
	else if(infix[i]=='(') {		//opening brace
		while(S.peep()!=')') {
			prefix[k++]=S.pop();
		}
		S.pop();
	}
	else {								//operator
		if(S.isempty() || S.peep()==')')
			S.push(infix[i]);
		else if(Precedence(infix[i])>Precedence(S.peep()))
			S.push(infix[i]);			//push over other operator
		else if(Precedence(infix[i])<Precedence(S.peep())) {
			while(!S.isempty() && S.peep()!=')' && Precedence(infix[i])<Precedence(S.peep()) )
				prefix[k++]=S.pop();	//poping till the condition
			if(S.isempty() || Precedence(infix[i])!=Precedence(S.peep()))
				S.push(infix[i]);		//push after pop
			else {
				if(Associativity(infix[i])==1) {//right to left after poping
					prefix[k++]=S.pop();
					S.push(infix[i]);
				}
				else
					S.push(infix[i]);			//left to right after poping
			}
		}
		else {
			if(Associativity(infix[i])==1) {	//right to left
				prefix[k++]=S.pop();
				S.push(infix[i]);
			}
			else
				S.push(infix[i]);				//left to right

		}
	}
	if(x==1){
		while(!S.isempty()){
			cout << S.peep();
			S1.push(S.pop());
		}
		while(!S1.isempty()){
			S.push(S1.pop());
		}
		prefix[k]='\0';
		cout << "\t\t\t" << prefix << endl;}
	i--;
	}
	while(!S.isempty())			//poping remaining operator
		prefix[k++]=S.pop();
	prefix[k]='\0';
	if(x==1){
		cout << "---------------------------------------------------" << endl;
		cout << "After Poping remaining operators: " << prefix << endl;}
	len=strlen(prefix);
	char temp;
	for(i=0;i<len/2;i++) {		//for proper display of prefix
		temp=prefix[i];
		prefix[i]=prefix[len-i-1];
		prefix[len-i-1]=temp;
	}
	if(x==1)
		cout << "After reversing: " << prefix << endl;
}

int calculate(int operand1,int operand2,char operatr){
	if(operatr=='+')	//add
		return(operand1+operand2);
	if(operatr=='-')	//sub
		return(operand1-operand2);
	if(operatr=='*')	//multiply
		return(operand1*operand2);
	if(operatr=='/')	//divide
		return(operand1/operand2);
	if(operatr=='^')	//exponent
		return(operand1^operand2);
	return 0;
}

int Expression::postfix_evaluate(){
	stackadt<int>S1;
	int i=0;
	int opd1,opd2,Result;
	int value;
	char opr;
	while(postfix[i]!='\0') {
		if(Isalpha(postfix[i])){
			if(!isdigit(postfix[i])){	//char operand is found
				cout << "Value of " << postfix[i] << " :";	//input from user
				cin >> value;
				S1.push(value);	//push value in stack
			}
			else {				//integer operand is found
				value = postfix[i]-'0';
				S1.push(value);
			}
		}
		else {					//operator is found
			opd2 = S1.pop();
			opd1 = S1.pop();
			opr = postfix[i];
			Result = calculate(opd1,opd2,opr);	//operate on top two operands opr1,opr2
			S1.push(Result);	//push result
		}
		i++;					//traversing the expression
	}
	Result = S1.pop();
	return Result;
}

int Expression::prefix_evaluate() {
	stackadt<int>S1;
	int len = strlen(prefix);
	int i = len-1;
	int opd1,opd2,Result;
	int value;
	char opr;
	while(i>=0) {
		if(Isalpha(prefix[i])){		// char operand is found
			if(!isdigit(prefix[i])){
				cout << "Value of " << prefix[i] << " :";
				cin >> value;
				S1.push(value);
			}
			else {				//int operand is found
				value = prefix[i]-'0';
				S1.push(value);
			}
		}
		else {					//operator is found
			opd1 = S1.pop();
			opd2 = S1.pop();
			opr = prefix[i];
			Result = calculate(opd1,opd2,opr);	//operate on top two operands opr1,opr2
			S1.push(Result);	//push result
		}
		i--;					//traversing the expression
	}
	Result = S1.pop();
	return Result;
}
int main()
{
	Expression e;
	do{
		e.input();
	}while(false==e.valid_expression());
	int ch,Result;
	do{							//for multiple interaction with user
		cout << "\n*****Expression Conversion*****\n1. Edit Expression\n2. Postfix\n3. Prefix\n4. Postfix Evaluate\n5. Prefix Evaluate\n6. Exit\nYour choice: ";
		cin >> ch;
		switch(ch){
		case 1:
			do{
				e.input();
			}while(false==e.valid_expression());	//input expression
			break;
		case 2:
			cout << "infix\t\t" << "stack\t\t\t" << "postfix\n";
			cout << "------------------------------------------------" << endl;
			e.infix_to_postfix(1);	//postfix expression & display
			e.display_postfix();
			break;
		case 3:
			cout << "infix\t\t" << "stack\t\t\t" << "prefix\n";
			cout << "------------------------------------------------" << endl;
			e.infix_to_prefix(1);	//prefix expression & display
			e.display_prefix();
			break;
		case 4:
			e.infix_to_postfix(0);	//postfix evaluate
			e.display_postfix();
			Result = e.postfix_evaluate();
			cout << "Value of Expression: " << Result<< endl;
			break;
		case 5:
			e.infix_to_prefix(0);	//prefix evaluate
			e.display_prefix();
			Result = e.prefix_evaluate();
			cout << "Value of Expression: " << Result<< endl;
			break;
		case 6:
			cout << "Program Terminated !";
			return 0;
		default:
			cout << "\n!!!Enter Valid Choice!!!";
		}
	}while(1);
}
