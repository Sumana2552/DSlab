


#include<stdio.h>//pre processor directives

#define MAX 4 //queue array size 

int cqueue_arr[MAX]; //declaration of the circular queue array 
int front = -1; //declaraion and intialization of the front to -1
int rear = -1;//declaration and intialization of the front to -1


void enqueue(int item) //function to enqueue
{
	if((front == 0 && rear == MAX-1) || (front == rear+1)) //circular queue overflow condition 
	{
		printf("Queue Overflow \n"); //displays message 
		return;
	}
	if (front == -1)  // if queue is empty
	{
		front = 0; //setting front to 0 
		rear = 0;//setting rear to 0 
	}
	else
	{
		if(rear == MAX-1) //indicates that only one element is present 	
			rear = 0; //setting rear to 0 
		else
			rear = rear+1; //incrementing rear
	}
	cqueue_arr[rear] = item ; //item is inserted 
}

void dequeue() //function to dequeue element 
{
	if (front == -1) //underflow condition 
	{
		printf("Queue Underflow\n");
		return ;
	}
	printf("Element deleted from queue is : %d\n",cqueue_arr[front]); //prints item to be deleted 
	if(front == rear) //single element in queue 
	{
		front = -1;//set front to -1
		rear=-1;//set rear to -1
	}
	else //otherwise
	{	
		if(front == MAX-1) //if front is at the last element
			front = 0; //set front to zero 
		else
			front = front+1; //increment front 
	}
}

void display() //function to dispay elements of the circular queue
{
	int front_pos = front,rear_pos = rear; //creating two variables front_pos and rear_pos and initializing them to front and rear 
	if(front == -1) // condition for an empty queue
	{
		printf("Queue is empty!!\n");  //message that displays queue is empty 
		return;
	}
	printf("printing queue elements \n"); //message that shows that queue elements are being printed 
	if( front_pos <= rear_pos ) //if the front pointer is at a position before the rear pointer 
		while(front_pos <= rear_pos) // looping until the position where front and rear pointer are pointing to the same element(indicates the end of the circular queue)  from the position where front is currently present 
		{
			printf("%d ",cqueue_arr[front_pos]); //printing values 
			front_pos++; //incrementing the front
		}
	else
	{
		while(front_pos <= MAX-1) //looping from  a position where front is bfore the last element till the end 
		{
			printf("%d ",cqueue_arr[front_pos]); //print values 
			front_pos++; //incrementing the front
		}
		front_pos = 0; //setting front to 0 
		while(front_pos <= rear_pos) //looping until front is before a position than rear or as the same position as rear -->indicates circular queue's end 
		{
			printf("%d ",cqueue_arr[front_pos]); //printing vales
			front_pos++; //incrementing the front
		}
	}
	printf("\n"); //formatting the output 
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
	
	enqueue(50); //doesn't insert element displays overflow 
	
	dequeue(); //delets 1st element 
	
	printf("\n circular queue after deleting 1st element: "); //display message
	display(); //prints cirular queue elements
	
	dequeue(); //deletes 2nd element
	
	printf("\n circular queue after deleting 2nd element: "); //display message
	display();//prints cirular queue elements
}
	
	
	
	

