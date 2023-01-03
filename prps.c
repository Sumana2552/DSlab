#include<stdio.h> //preprocessor directives
#include<string.h> //preprocessor directives
#include<stdlib.h> //preprocessor directives

#define SIZE 20 //defining size of 1d array to be 20 

char prefix[SIZE], stack[SIZE]; //declaring 1d array for postfix exp and stack
int top = -1; //declaring top initializing to -1

void push(char item) //defining push function
{
  stack[++top] = item; //incrementing stack's top and copying item to stack's top
}

char pop() //defing the pop function
{
  return stack[top--]; //returning the value deleted from stack whenever called
}

int chk_Operand(char op) //function to check if the input character is an operand 
{
  return (op >= 'a' && op <= 'z') || (op >= 'A' && op <= 'Z');
}

//function to check if input character is an operator
int isOperator(char op) 
{
	  switch (op) 
	  {
		  case '+':
		  case '-':
		  case '/':
		  case '*':
		    return 1; //if the input character is any of the operators mention above in cases then return 1 
		   	break;
		  default:
		  	return 0;//if not the return 0
	  }
}

void revstr(char *st) //function to reverse a string
{
	int i, temp, len; //declaring variables len , temp and i.
	
	len=strlen(st); //initializing len to the size of the string to be reversed
	
	for(i=0;i<len/2;i++) //loop until i=len/2
	{
		temp=st[i]; //copy string content to temp 
		st[i]=st[len-i-1]; // copy last element of the string to 1st place of string 
		st[len-i-1]=temp; //copy the character from temp to the string's last position 
		
	} 
	
}






void postfixToprfix()  //converting postfix to prefix
{
  int len, i, j = 0; //declaring variables len, i ,j . initializing j to 0
  char tmp[20]; //declaring a temporary array
  char op1; //decalring a variable op1 of char type 

  printf("\n\nEnter the prefix expression:"); //request to enter a prefix expression
  scanf("%s", prefix); //reading the prefix expression 

  len = strlen(prefix);  // initializing "len" variable to the string length of prefix expression 
  
  revstr(prefix); //reversing the prefix expression for the convenience of being read from rght to left

  for (i = 0; i < SIZE; i++)  //run loop until i<SIZE is false 
   { stack[i] = '\0'; }//initializing the stack 
   

  for (i = len - 1; i >= 0; i--) //run loop until i>=0
  {
    if (isOperator(prefix[i]))  //if the input character is an operator 
    {
      push(prefix[i]); // it is pushed into the stack.
    } 
    else //if not if the input character is an operand 
    {
      tmp[j++] = prefix[i];   //it is copied to the temporary array 
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
  char postfix[20];  //declaring 1d array for prefix expression 

	  while (tmp[i] != '\0')  //run loop unitl the temporary array is not empty 
	  {
	    postfix[j--] = tmp[i++];  //copy all the elements from temporary array to postfix array 
	  }
	  
	  revstr(postfix); //reverse the expression in postfix 
		
	printf("\n\nPostfix expression is:");
  	printf("%s\n", postfix);

}

int main() 
{
  postfixToprfix();

  return 0;
 }
