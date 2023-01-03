//implementation of stack using array

#include<stdio.h> //pre processor directive
#include<stdlib.h>//pre processor directive 
# define SIZE 10 //defining the size of the stack

int stack[SIZE]; //declaring the stack 
int top=-1; //declaring and initializing the top of the stack

void push(int item) //function definition for the push operation 
{
	if(top==SIZE-1)  //condition to check if the stack is full
	{
		printf("\nstack overflow"); // then the stack is full therefore,printing stack overflow 
	}
	
	else //if the stack is not full 
	{
		top++; //incrementing the top 
		stack[top]=item; //inserting the incoming data item into the stack 
		printf("\ninserted element successfull\n"); //displaying a confirmation message for the inserted element 
	}
}
void pop() //defining a function to perform pop operation 
{
	if(top==-1)  // condition to checkk if the stack is empty 
	{
		printf("\nstack underflow");//if the stack is empty, we print stack underflow
	}
	
	else //if the stack is not empty 
	{
		printf("\nitem to be deleted:%d",stack[top]); //item to be deleted is the stack's top which is printed before deletion 
		top--; //decrementing the top thus deleting the item 
	}
}
void display() 
{
	if(top==-1)  // condition to check if the stack is empty 
	{
		printf("\nstack is empty! cannot display elments"); //since the stack is empty printing stack is empty no elements to be displayed 
	}
	else //if the stack isn't empty 
	{
		for(int i=0;i<SIZE;i++) //running a for loop until the last element of the stack
		{
			printf("\nelement_%d:%d",i+1,stack[i]);//printing the all the elements of the stack.
		}
	}
}

void main() //the main function 
{
	int choice; //declaring a variable to enter the choice during run time.
	int element;  //declaring a variable to represent the incoming element.
	
	while(choice!=4) //until the choice is 4 the loop gets executed
	{
		printf("\n\n*************MENU****************\n\n"); //menu 
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit"); // options in the menu 
		printf("\nenter:"); // requesting input from the user during run time 
		scanf("%d",&choice); //requesting input from the user during run time

		switch(choice) //switch case for the entered choice (from options 1-4 of the menu)
		{
			case 1:  //if choice is 1 
				printf("enter the element to be pushed :"); //requesting user to enter the element to be pushed
				scanf("%d",&element);// scanf to implement the input 
				
				push(element); //pushing the entered element  
				break;
			case 2: //if choice is 2
				pop();//calling pop function
				break;
			case 3:  //if choice is 3
				display();//calling display function
				break;	
			case 4: //if choice is 4 
				exit(0); //exit the loop
				break;	
			default: //if choice does not belong to the menu then 
				printf("invalid selection");  //printing a message as invalid selection
		}
	}
}
