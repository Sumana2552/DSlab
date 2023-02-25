/* NAME : G SRI PRABHA SUMANA 
USN: 1NT21IS058
SEC:A SEM: III BRANCH: ISE*/


#include<stdio.h>   //pre processor directives
#include<stdlib.h>  //pre processor directives

#define max 5  //size of queue array

 
void enqueue();  //function prototype for enqueue operation
void dequeue();  //function prototype for dequeue operation
void display();  //function prototype for display operation
int front = -1, rear = -1;  //declaring & initializing front and rear to -1
int queue[maxsize];  //declaring & inittializing array  for queue 


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
				    enqueue();  //enqueue operation is performed 
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
void enqueue()  //function to enqueue
{  
	    int item;  //declaring a variable "item" to store data to be entered 
	    printf("\nEnter the element\n");  //asking the user to enter the element 
	    scanf("\n%d",&item);      // passing address of the variable "item" to store the data entered
	    
	    if(rear == maxsize-1) //condition to check if the queue is full 
	    {  
		printf("\noverflow!!\n");  //displaying that the queue is full
		return;  
	    }  
	    
	    if(front == -1 && rear == -1)  //condition to check if both front and rear point to null
	    {  
		front = 0; //setting front to 0  
		rear = 0;  //setting rear to 0 
	    } //this condition is true when nothing is present and the element to be inserted is stored as the 1st element of the queue. 
	    
	    else    //if none of the above conditions are true 
	    {  
		rear = rear+1;  //then rear is incremented t
	    }  
	    queue[rear] = item;  //item is inserted
	    printf("\nValue inserted!");  //confirmation message to the user that the item is inserted 
	      
}  

void dequeue()  //function to dequeue an element 
{  
	    int item; //variable declaration to store the value to be deleted for displaying during runtime   
	    if (front == -1 || front > rear)  //condition to check if the queue is empty 
	    {  
	    
			printf("\nunderflow!!\n");  //displaying message to the user that the queue is empty if the above condition is true
			return;  
		      
	    }  
	    
	    else  //if the abive conditions are false 
	    {  
			item = queue[front]; // storing the item to be deleted in the variabel item 
			
			if(front == rear)  //if both front and rear point to the same element--.indicates that there is only one element in the queue
			{  
			    front = -1;  //setting front to -1 
			    rear = -1 ;  //setting rear to -1
			}  
			
			else   
			{  
			    front = front + 1;  //incrementing front thus deleting the element 
			}  
			printf("\nvalue deleted:");  //value that is deleted 
	    }  
	      
      
}  
      
void display()   //function to display all the elements of the queue
{  
	    int i;  //variable of int type to iterate the loop block
	    if(rear == -1)  //condition for an empty queue 
	    {  
	    	printf("\nEmpty queue\n");  //displaying a message to the user that the queue is empty hence nothing can be displayed 
	    }  
	    else  
	    {   
	    	printf("\nprinting values:");  //message displaying that says that all the elementsa are being printed 
		for(i=front;i<=rear;i++)  //loops until the end of the queue
		{  
		    printf("\n%d\n",queue[i]);  //printing the elements one after another 
		}     
	    }  
}
