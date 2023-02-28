


#include <stdio.h> //pre processor directives

#include<stdlib.h>   //pre processor directives

struct node //structure definition for a node
{

	int data; //data part of the node 

	struct node* next; //link to the next node

};

struct node* front = NULL; //declare and initialize front to null

struct node* rear = NULL; //declare and initialize front to null

void enqueue(int item)  //function to enqueue

{  

    struct node* newnode = (struct node*)malloc(sizeof(struct node));//allocating memory to newnode 

    newnode->data=item;  //inserting element to node

    newnode->next=NULL;  // making the newnode's next as null

    if(rear== NULL) //if queue is empty   

    {  

        front=rear=newnode;  //setting front and rerar point to point to new node 

        rear->next=front;   // making rear's next as front since it is a circular queue

    }  

    else  //if queue is not empty and some elements are present in it 

    {  

        rear->next=newnode;  //making the next node of rear as newnode 

        rear=newnode;  //updating rear to newly created node 

        rear->next=front;  //updating the rear to front since it is a circular queue 

    }  

}  

void dequeue()  //dequeue function 

{  

    struct node* temp = front;  //creating a pointer temp, initializing it to front 

    if((front==NULL)&&(rear==NULL))   // if the circular queue is empty 

    {  

        printf("\nQueue is empty");  //print underflow 

    }  

    else if(front==rear) //if only one element is present 

    {  

        front=rear=NULL;  //both front and rear point to null

        free(temp); //de allocating memory thus deleteing the item in queue

    }  

    else  // if more than one element is present 

    {  

        front=front->next; //incrementing front pointer  

        rear->next=front;  //making rear's next point to front -->since it is a circular queue

        free(temp);  //de allocating memory hence deleteing the element 

    }  

}   

   

void display() //function to display elements of circular queue 

{  

    struct node* temp = front;  //declaring a temp pointer , initializing it to front 

    printf("\n The elements in a Queue are : ");   //display message 

    if((front==NULL) && (rear==NULL))  //underflow condition 

    {  

        printf("Queue is empty");  //print underflow 

    }  

  

    else   //if elements are present in circular queue

    {  

        while(temp->next!=front)  //loops until the end of the circular queue

        {  

            printf("%d,", temp->data);  //print data

            temp=temp->next;  // update pointer

        }  

        printf("%d", temp->data);  //print the data present in the last element 

    }  

}  

int main() //main function 
{
	dequeue(); //displays underflow 
	display(); //displays underflow 
	
	enqueue(10); //inserts 10 
	
	printf("\n circular queue after inserting 1st element: "); //display message
	display(); //prints circular queue elements 
	
	enqueue(20); //inserts 20 	
	printf("\n circular queue after inserting 2nd element: "); //display message 
	display(); //prints cirular queue elements 
	
	enqueue(30); //inserts 30 
	
	printf("\n circular queue after inserting 3rd element: "); //display message 
	display(); //prints cirular queue elements
	
	enqueue(40); //inserts 40 
	
	printf("\n circular queue after inserting 4th element: "); //display message
	display(); //prints cirular queue elements
	
	
	
	dequeue(); //delets 1st element 
	
	printf("\n circular queue after deleting 1st element: "); //display message
	display(); //prints cirular queue elements
	
	dequeue(); //deletes 2nd element
	
	printf("\n circular queue after deleting 2nd element: "); //display message
	display();//prints cirular queue elements
}
