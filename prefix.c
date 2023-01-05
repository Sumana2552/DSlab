//converting an infix to prefix expression 
#include<stdio.h>
#include<string.h>
#define SIZE 100 //defining the size of the stack

char stack[SIZE]; //declaring a 1D array for stack 
int top=-1;  //declaring and intializing the top of the stack to -1
//push function dfn 
void push(char item)
{	if(top!=SIZE-1) //condition to check if the stack is empty 
	{	
		
		stack[++top]=item;
	}	                       //inserting the incoming item into the stack by incrementing the top 
}
//pop function dfn 
char pop()
{
	return stack[--top]; // deleting an item of the stack by decrementing the top when called 
}
//function to check the operator precedence 
int precedence(char operator) 
{
	if(operator == '('||operator==')') //if the incoming operators are "(",")" 
	{
		return 0; //then return 0
	}
	if(operator== '+'||operator=='-') //if the incoming operators are "+","-" 
	{
		return 1; //then return 1
	}
	if(operator=='*'||operator=='/') //if the incoming operators are "*","/" 
	{
		return 2; //then return 2
	}
	
}
//function to check if the incoming item is an operator or not 

int chkOperator(char operator)
{
	switch(operator)//using a switch case to include all possible operators 
	{
		case '+': 
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
		case '^':
		case '#':
		case '%'://if one of the above mentioned operators are present in the incoming item, then return the value 1
			return 1;
		break;
		default: //if the incoming data item does not have the above mentioned operators then return value 0 
			return 0;
	}
}


void revstr(char *st) //fucntion to reverse a string
{
	int i, temp, len; //declaring 3 variables 
	
	len=strlen(st); //size of the string
	
	for(i=0;i<len/2;i++) //run until i<len\2
	{
		temp=st[i]; //transfer item from st to temp
		st[i]=st[len-i-1]; //item from end of the st to start of the st
		st[len-i-1]=temp; //temp to  item from the end of st
		
	} 
	
}
















//function dfn to convert infix to prefix 
void convert(char infix[SIZE],char prefix[SIZE])
{
	int j=0,i; //declaring two int type variables i and j, initializing j to 0
	char ip_element;//declaring incoming element 
	stack[top++]='#'; //initializing the stack
	
	
	
	revstr(infix);  //reverse th infix expression to read from right to left 
	
	

	for(i=0;i<strlen(infix);i++) //for loop that runs from the 1st element of infix to the last elements of the infix expression
	{
	
		
		
		ip_element=infix[i];//the infix expression's elements are trasferred to the variable ip_element for conversion 
		
		
		
		if(chkOperator(ip_element)==0) //condition to check if the incoming element is an operand 
		{
			prefix[j]=ip_element; //the incoming element(which is an operand) is copied to postfix[] 
			++j;//incrementing the prefix array elements as they get added into the array post conversion from infix 
			
		}
		else //if the condition is false then 
		{
			if(ip_element==')')//condition to check if the incoming element is ")" 
			{
				push(ip_element); //if true it is pushed into the stack 
			}
			else if(ip_element=='(')// condition to check if the input element is "(" then 
				
			{
				
					while(stack[top]!=')');//until ")" is found
					{
						prefix[j]=pop();
						j++;//pop the stack's top and transfer it to prefix[]					
					}	
					
				pop();//pop the   )
			}
			
			
			else if(precedence(ip_element)<precedence(stack[top])) //condition to check if the incoming data item has a precedence lesser than that of the stack's top 
			{
				push(ip_element); //if true push the element into the stack
			}
			else //if false
			{
				while(precedence(ip_element)>=precedence(stack[top])) //condition to say if the incoming data item has greater or equal precedence to the 														one which is present in the stack.//

				{


					prefix[j]=pop();//if the while condition is true then the stack's top is popped and printed
					j++;
				}
				push(ip_element); /*  push the incoming element into the stack after popping out the 
								operator or element of greater or equal precedence than this incoming element */
			}
			
		}
	}


	while(stack[top]!='#')//while the stack's not empty ==>stack's full
	{
		prefix[j]=pop(); //all the elements of the stack are popped,copied to prefix[]
		j++; //incrementing the stack elements 
	}

	//null terminating the string 
	
	prefix[j]='\0';
	revstr(prefix); //reversing the expression again
	
	



} 








void main() //main function without any return type 
{
	
	char prefix[SIZE]; //declaring a 1d array prefix
	
	char infix[]="2*(3+7)*1"; //declaring the infix array to store the expression
	
	
					
	
	
	

	convert(infix,prefix); //calling the convert function 
	
		
	printf("\n\nthe infix expression:%s\n",infix); //printing the infix expression 
	printf("\n\nthe prefix expression after the conversion:%s\n\n",prefix); //printing the prefix expression after the conversion 
	
	
}

