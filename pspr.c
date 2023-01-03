#include<stdio.h>//preprocessor directives
#include<string.h>//preprocessor directives
#include<stdlib.h> //preprocessor directives

#define SIZE 20 //defining size for a 1d array 

char postfix[SIZE], stack[SIZE]; //decalring 2 1d arrays for the postfix expression and stack .
int top = -1; //decalring top, initializing  it to -1

void push(char item) // push function definition 
{
  stack[++top] = item; //increment the top , transfer the data item to stack's top
}

char pop() //pop function definition 
{
  return stack[top--]; //return the deleted value whenever function's called
}


//function to check if it is an operator
int isOperator(char op) 
{
  switch (op) 
  {
	  case '+':
	  case '-':
	  case '/':
	  case '*':
	    return 1;
	  default:
	   return 0;
   }
}

void postfixToprfix()  //function to convert postfix to prefix 
{
  int len, i, j = 0; //declaring variables len, i ,j . initializing j to 0
  char tmp[20]; //declaring a temporary array
  char op1; //declaring a variable op1 of char type 

  printf("\n\nEnter the postfix expression:"); //request to enter a postfix expression
  scanf("%s", postfix); //reading the postfix expression 

  len = strlen(postfix);  // initializing "len" variable to the string length of postfix expression 

  for (i = 0; i < SIZE; i++)  //run loop until i<SIZE is false 
   { stack[i] = '\0'; }//initializing the stack 
   

  for (i = len - 1; i >= 0; i--) //run loop until i>=0
  {
    if (isOperator(postfix[i]))  //if the input character is an operator 
    {
      push(postfix[i]); // it is pushed into the stack.
    } 
    else //if not if the input character is an operand 
    {
      tmp[j++] = postfix[i];   //it is copied to the temporary array 
      while ((top != -1) && (stack[top] == '#'))  //run loop until the stack is empty 
      {
        op1 = pop();  //pop stack's top(first operand) and copy to operand1
        tmp[j++] = pop(); //pop stack's top (second operand is stack's new top after popping 1st operand), copy to temporaray array after concatenating them both
      }
      push('#'); //push them back to the stack 
    }
  }
  tmp[j] = '\0';  //null terminating the string

  i = 0; //initializing i to 0 
  j = strlen(tmp) - 1; // j is length of the temporary array 
  char prefix[20];  //declaring 1d array for prefix expression 

	  while (tmp[i] != '\0')  //run loop unitl the temporary array is not empty 
	  {
	    prefix[j--] = tmp[i++];  //copy all the elements from temporary array to prefix array 
	  }
		
	printf("\n\nPrefix expression is:");
  	printf("%s\n", prefix);

}

int main() 
{
  postfixToprfix();

  return 0;
 }
