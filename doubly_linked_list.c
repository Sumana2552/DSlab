


// PROGRAM TO IMPLEMENT DOUBLY LINKED LIST

#include <stdio.h>//pre processor directive 
#include <stdlib.h>//pre processor directive


struct node //structure definition for a node in DLL
{
	int data; //data stored in the node
	struct node *prev, *next; // links connecting previous and the next node
};
struct node* head = NULL; //creating a head pointer

// Function to traverse the linked list
void traverse()
{
	
	if (head == NULL)//DLL is empty  
	{
		printf("\nList is empty\n"); //displays message 
		return;
	}
	
	struct node* temp; //external pointer temp 
	temp = head; //temp points to head node 
	while (temp != NULL) //until the DLL's end
	{
		printf("Data = %d\n", temp->data); //prints dat a
		temp = temp->next; //update temp pointer 
	}
}

// Function to insert at the front of the linked list
void insertAtFront()
{
	int data; //data to be inserted
	struct node* temp; //creating a pointer to create a node
	temp = (struct node*)malloc(sizeof(struct node)); //creating an newnode called as temp 
	printf("\nEnter number to be inserted: "); //display message 
	scanf("%d", &data); //scans data 
	temp->data = data; //insert data into the node
	temp->prev = NULL; //make node's prev as null since 1st  node's previous points to null in a DLL

	
	temp->next = head; //new node-temp's next is assigned to head
	head = temp; //newnode is the head node 
}


void insertAtEnd()
{
	int data; //data to be inserted 
	struct node *temp, *trav;//external pointers declaration
	temp = (struct node*)malloc(sizeof(struct node)); //creating a new node called temp
	temp->prev = NULL; //temp's prev is made null
	temp->next = NULL; //temp node's next made null 
	printf("\nEnter number to be inserted: "); //displays message
	scanf("%d", &data); //scans data 
	temp->data = data; //data inserted into node 
	temp->next = NULL; //node's next is made NULL
	trav = head; //initializing trav pointer to head 

	// If head is NULL-->lis is empty 
	if (head == NULL) 
	{

		head = temp; //make head point to newly created node 
	}

	// Changes Links
	else {
		while (trav->next != NULL) //until the end of DLL
			trav = trav->next; //update trav pointer 
		temp->prev = trav; //make the newnode's(temp's) prev as last node
		trav->next = temp; //make the current last node's next as temp
	}
}

// function to insert at any specified position in the linked list
void insertAtPosition()
{
	int data, pos, i = 1; //declaring position variable and initialiazing it to 1 to specify position , declaring data variable to insert data
	struct node *temp, *newnode; // external pointer temp and node newnode 
	newnode = malloc(sizeof(struct node)); //allocating memory to newnode
	newnode->next = NULL; //initializing newnode's next to null
	newnode->prev = NULL;//initializing newnode's prev to null

	
	printf("\nEnter position : "); //displays message 
	scanf("%d", &pos); //to enter the position where node has to be inserted 
	

	
	if (head == NULL)//single element in DLL 
	{
		head = newnode; //head points to newnode 
		newnode->prev = NULL;//initializing newnode's next to null
		newnode->next = NULL;//initializing newnode's prev to null
	}

	
	else if (pos == 1) //for 1st position 
	{
	
	insertAtFront(); //calling inseratfront function 
	}

	
	else 
	{
		printf("\nEnter number to be inserted: "); //displays message 
		scanf("%d", &data); //scan data to be inserted
		newnode->data = data; //inserting the data into node
		temp = head; //temp initialized to head 
		while (i < pos - 1) //loop until desired position is found 
		{
			temp = temp->next; //update the temp pointer
			i++; //increment i
		}
		newnode->next = temp->next; //making located node's(node after which we want to insert new node) next as newnode's next 
		newnode->prev = temp; //newnode's prev is made as located node
		temp->next = newnode; //located node's next is made as newnode 
		temp->next->prev = newnode; // located node's next node's prev is made newnode 
	}
}


void deleteFirst() //function to delete from beginning 
{
	struct node* temp; //create a pointer called as temp
	if (head == NULL) //list is empty
		printf("\nList is empty\n"); //displays message
	else //if DLL is present
	{
		temp = head; //initialize temp to head
		head = head->next; //updating head to the next node
		if (head != NULL) // if the first node is not null
			head->prev = NULL; // make head's previous as null 
		free(temp); //free memory for the first node 
	}
}


void deleteEnd() //function to delete from end 
{
	struct node* temp; //create a temporary pointer
	if (head == NULL) //condition to check if lis is empty 
		printf("\nList is empty\n"); //displays message
	temp = head; //intializing temp to head 
	while (temp->next != NULL) //loop until the end of the list 
		temp = temp->next; //update the temp 
	if (head->next == NULL) //if there is only one element 
		head = NULL; //make it null
	else 
	{
		temp->prev->next = NULL; //making the node's(node to be deleted) previous element's next as null indicating that it is the last element of the DLL
		free(temp); //free memory for temp
	}
}


void deletePosition() //function to delete an element from a given position
{
	int pos, i = 1; //declaration of position varibale and iterative variable.
	struct node *temp, *position; //creating two pointers temp and position 
	temp = head; //making temp as head

	
	if (head == NULL) //condition to check if DLL is empty 
		printf("\nList is empty\n"); //prints DLL's empty 

	
	else 
	{
		
		printf("\nEnter position : "); //position to be deleted 
		scanf("%d", &pos); //taking input from user

		
		if (pos == 1)  //condition to check if position is 1st position
		{
			deleteFirst(); //calling delete first function
			if (head != NULL) //if the list is not empty 
			{
				head->prev = NULL; //making the prev of the node as NULL
			}
			free(position); //de allocating memory for position 1 
			return;
		}

		while (i < pos - 1) //loop till the desired pos is arrived 
		{
			temp = temp->next; //updating temp until the last 
			i++; //incrementing i 
		}
		
		position = temp->next; //temp's next is linked to the node we want to delete
		if (position->next != NULL) //condition to check if the node is at the end
			position->next->prev = temp; //connecting the the node's next element's previous link to temp
		temp->next = position->next;//linking the node's next to temp's next

		
		free(position);//free memory 
	}
}


int main() //main function 
{
	int choice; //variable to switch between menu options
	while (1) //loop until the condition is false 
	{

		printf("\n1.Traverse\n2.Insert at beginning\n3.Insert at end\n4.Insert at a possition\n5.Deleting at beginning\n6.Delete at end\n7.Delete at position\n8.Exit"); //menu options 
		printf("\n enter your choice:"); //displays message 
		scanf("%d", &choice); //scans user's choice 

		switch (choice) 
		{
			case 1:
				traverse(); //to traverse the list 
				break;
			case 2:
				insertAtFront(); //to insert node at the beginning
				break;
			case 3:
				insertAtEnd();//to insert node at the the end 
				break;
			case 4:
				insertAtPosition();//to insert a node at a particular postion
				break;
			case 5:
				deleteFirst(); //to delete at the beginning 
				break;
			case 6:
				deleteEnd();//to delete at the end
				break;
			case 7:
				deletePosition();//to delete at a given position 
				break;

			case 8:
				exit(0); //exit the menu 
				break;
			default:
				printf("invalid selection\n"); //displays message 
				continue;
		}
	}
	
}

