



#include <stdio.h> //pre processor directive
#include <stdlib.h> //pre processor directive

struct node //declaring a structure with data and link part of next node 
{
	int data; //data of the node 
	struct node* next; //link to the next node 
};

struct node *front = NULL; //declaring front pointer, initializing it to NULL
struct node *rear = NULL; //declaring rear pointer, initializing it to NULL

void enqueue(int data)//function to insert a node in queue
{
	struct node* new_node; //creating a newnode 
	new_node = (struct node*)malloc(sizeof(struct node)); //allocating memory to newnode
	new_node->data = data; //inserting data to the newnode 
	new_node->next = NULL; //making the newnode's  link to point to null
	if((front == NULL)&&(rear == NULL)) // if both ront and rear pointer poin to null 
	{
		front = rear = new_node; //setting both of them to nenode 
	}
	else
	{
		rear->next = new_node; //inserting newnode to queue by linkin it to rear's next 
		rear = new_node; //updating rear
	}
	
}

void display()//function to display the queue
{
	struct node* temp; //creating an external pointer temp to iterate 
	if((front == NULL)&&(rear == NULL)) //condition to show empty queue 
	{
		printf("\nQueue is Empty!"); //display message that queue is empty 
	}
	else
	{
		temp = front; //making temp as front
		while(temp) //loops until temp reaches the end of the queue  
		{
			printf(" %d ",temp->data); //queue elements printed 
			temp = temp->next; //updating temp 
		}
	}
}

void dequeue()//function to delete an element from a queue
{
	struct node *temp; //external temp pointer
	temp = front; //making temp as front 
	if((front == NULL)&&(rear == NULL)) //underflow condition 
	{
		printf("\nQueue is Empty!!"); //displays underflow message 
	}
	else{
		front = front->next; //incrementing front
		free(temp); //removing data stored in temp, therefore deleting element 
	}
}
void main ()  //main function
{  
	int choice;   //declaring an int type variable for choice 
	while(choice != 4)   //loop until choice entered is not 4
    	{     
		printf("\n*************************Menu*****************************\n");   //menu 
		 
		printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  //list of opitons in menu 
		printf("\nEnter your choice ?");  //asks input from the user to enter the choice of operation
		scanf("%d",&choice);  //passing the address of the choice variable to store the data entered 
        	switch(choice)   //switch between operations based on the user's choice
		{  
			    case 1:  //if entered choice = 1
				    
				    int val;
				    printf("\n insert val:");
				    scanf("%d",&val);
				    enqueue(val);  //enqueue operation is performed 
				    break;  
			    case 2:  //if entered choice = 2
				    dequeue();  //dequeue operation is performed 
				    break;  
			    case 3:  //if entered choice = 3
				    display();  //display operation is performed 
				    break;   
			    case 4:  //if entered choice = 3
				    exit(0);  //exits the loop 
				    break;  
			    default:   //if none of the choices entered are satisfying with above cases
			    	printf("\nEnter valid choice??\n");  //display "invalid input" to user
		}  
    }  
}  
	

