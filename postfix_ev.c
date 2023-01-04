//program to evaluate a prefix expression
#include<stdio.h> //pre processor directives
#include<stdlib.h> //pre processor directives
#include<string.h> //pre processor directives
#include<ctype.h>  //pre processor directives

#define SIZE 20 //size of the array ---> 20

int stack[SIZE]; //declaring stack's array of int type 
int top=-1; //declaring the top of the stack , initializing it to -1

//push function 
void push(int item)
{
	if(stack[top]!=SIZE-1) //checking if the stack is full
	{
		top=top+1; //if not incrementing the top 
		stack[top]=item;//and pushing the new data item into the stack 
	}
}
int pop() //pop function
{
	return stack[--top]; //returning the element deleted each time function is called
}











int ev_prfx(char *postfix) //function to evaluate a postfix expression
{
	
	int op1,op2; //operands 1 and 2 -->declaration
	
	
	int len=strlen(postfix); // size of the postfix expression
	
	int x; //int tyoe variable
	
	
	
	for(x=0;x<len;x++)   //runs loop until the end of the expression 
	{ 
		
		
		if(isdigit(postfix[x])) //checking if the symbol is an operand or digit 
		{
			push(postfix[x]-48); //if it is a digit it is pushed into the stack
		}
		else //if the element is an operator then,
		{
			op1=stack[top];
			pop(); //popping 1st operand 
			op2=stack[top];
			pop(); //popping 2nd operand 
			
			switch(postfix[x]) //switching between different operations to perform the desired operation 
			{
				case '+': //if +
					push(op1+op2); //add the operands and push the result to stack 
					break;
				case '-'://if -
					push(op1-op2);//subtract the operands push the result to satck
					break;
				case '*': //if *
					push(op1*op2); //multiply operands, push result to stack
					break;
				case '/': //if / 
					push(op1/op2);//divide operands , push result to the stack 
					break;
			}
		}
	}
	printf("\nthe result is: %d\n\n",stack[top]); //printing the result.
}
	
int main() //the main function 
{
	char postfix[SIZE]; //declaring postfix array 
	
	printf("\n\nenter the postfix expression:"); // requesting the user to enter the postfix expression 
	scanf("%s",postfix); //reading the expression
	
	ev_prfx(postfix); //calling the function to evaluate 
}
	
	
					
				
		
	
	
	


