#include<stdio.h> //pre processor directives 
#include<stdlib.h>//pre processor directives 

struct node //defining a node with dat anad link part 
{
	int data; //data present in the node 
	struct node * next; //link that stores the address of the next node 
}*top = NULL; //top pointer that points to the first node of the stack


void push(int item) //function to insert an element
{
	struct node * newnode = (struct node*)malloc(sizeof(struct node)); //allocating memory to create and store a newnode 
	
	
	newnode->data = item; //inserting data 
	newnode->next = top;  //updating the top 
	
	top = newnode; //updating the top 
	printf("\n insertion done\n");
	
}
void pop() //function to delete an element -pop
{
    if(top == NULL) //condition to check if the stack exists 
    {	
        printf("\n nothing to delete.");
    }
    else
    {
        struct node* temp = top; //creating an external temp pointer that points to top 
        int val = temp->data; //storing the value of the node to be deleted for displaying 
        top = temp->next; //making the next element (2nd) as top
        free(temp) ; //removing the data from temp thus deleting 
    }
}
void display()// function to print the stack elements 
{	
    if(top == NULL) //if top is null
    {	
        printf("\n underflow!"); //list is empty 
    }
    else
    {
        struct node *ptr = top; // assigning ptr to top 
        while(ptr != NULL) //loop until  ptr pointer is not null 
        {	
            printf("\n %d",ptr->data); //print values
            ptr = ptr->next; //update the ptr 
        }
    }
}
void peek() //peek function
{
	if(top == NULL)
	{
		printf("\n underflow"); //if there is no element 
	}
	else
	{
		printf("\ntop:%d\n",top->data); //printing the stack's top 
	}
}
void main() //main function 
{
	int choice; //choice variable to take user's choice 
	
	while(choice!=5) //loop until; choice is not 5
	{
		printf("\n\n*************MENU************\n\n"); //menu 
		
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.PEEK\n5.EXIT\n"); //menu options
		
		
		printf("\n enter your choice:"); //displays message 
		scanf("%d",&choice); //scans choice of the user 
		
		switch(choice) //switches between the options of menu  to match the choice of the user 
		{	
			case 1:
				int val1; //variable to insert item 
				printf("\n enter val:");
				scanf("%d",&val1); //scans item 
				
				push(val1); //calling push
				break;
			case 2:
				pop(); //caling the pop function
				break;
			
			case 3:
				display(); //calling display function 
				break;
			case 4: 
				peek();//calling the peek function 
				break;
			case 5:
				exit(0); //terminating the program
				break;
			default:
				printf("invalid selection");
		}
	}
}
