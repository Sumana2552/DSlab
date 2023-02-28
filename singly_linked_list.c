



//program to implement a  singly linked list 
#include<stdio.h> //pre processor directives 
#include<stdlib.h> //pre processor directives 
#include<stdbool.h>//pre processor directives

struct node //defining a node with dat anad link part 
{
	int data; //data present in the node 
	struct node * next; //link that stores the address of the next node 
}*head = NULL; //head ppointer that points to the first node of the list 

void insert_beg(int item)
{
	struct node * newnode = (struct node*)malloc(sizeof(struct node)); //allocating memory to create and store a newnode 
	
	
	newnode->data = item;
	newnode->next = head; 
	
	head = newnode; 
	
}
void insert_last(int item)
{
	struct node * newnode = (struct node*)malloc(sizeof(struct node)); //allocating memory to create and store a newnode 
	
	struct node * temp; //temporary pointer to iterate till the last node 
	
	
	
	newnode->data = item; //inserting data into node
	
	temp = head;  //assigning temp to head
	
	if(head == NULL) //if  head node is null
	{
		head = newnode; //newnode will be the only node therefore, it is the head node
		return; 
	}
	else 
	{
		while(temp!= NULL && temp->next!=NULL) //until the temp points to null and the list ends
		{
			temp = temp->next; //update temp 
		}
		temp->next = newnode; //if the condition is false insert new node in place of temp->next 
	}
}
		
void randominsert(int item)  //to insert a node randomly
    {  
        struct node *ptr = (struct node *) malloc (sizeof(struct node));  //allocate memory to the node
        struct node *temp;  //temp pointer declaration 
        int i,loc;  //declaration of variables i and loc of int type
        if(ptr == NULL)  //if the node is null 
        {  
            printf("\ncan't insert");  //print overflow
        }  
        else  
        {  
              
            printf("Enter the location");  //displays message 
            scanf("%d",&loc);      //scans the input    
            ptr->data = item;  // insert item to node 
            temp=head;  // assigning temp to head 
            for(i=0;i<loc;i++)  //loop until loc is found to insert node 
            {  
                temp = temp->next;  //update temp pointer
                if(temp == NULL)  //if temp is null
                {  
                    printf("\ncan't insert\n");  //displays message 
                    return;  
                }  
              
            }  
            ptr ->next = temp ->next;   // making the located node's next as newnode's next as 
            temp ->next = ptr;   //making the new node as the located node's next 
           
            printf("\nNode inserted");  //displays message 
        }  
          
    }  


void delete_beg() //function to delete at the beginning 
{
    if(head == NULL) //condition to check if the list exists 
    {	
        printf("\n nothing to delete.");
    }
    else
    {
        struct node* temp = head; //creating an external temp pointer that points to head 
        int val = temp->data; //storing the value of the node to be deleted for displaying 
        head = temp->next; //making the next element (2nd) as head
        free(temp) ; //removing the data from temp thus deleting 
    }
}

void delete_end()
{
    struct node *last = head; //last pointer created and assigned to head
    struct node *second_last = NULL; //second last pointer created assigned to null 
    
    if(last == NULL) //if head is null
    {
        printf("\n list is empty!!"); //display message 
    }
    else
    {
        while(last->next != NULL) //loop until SLL's end is reached
        {
            second_last = last; //assigning last to second last 
            last = last->next; //last becomes last node's next element
        }
        
        if(second_last == NULL)// if the second last element is null
        {
            head = NULL; //making head null
        }
        else
        {
            second_last->next = NULL; // making secon last node's next as null
        }
        
        free(last);//free memory 
    }
}


void delete_pos(int pos) // function to delete an element from a particular position 
{	
    if(head == NULL) //if head is null 
    {
        printf("\n empty list");//display the message 
    }
    else
    {
        struct node *ptr = head; // create an external pointer ptr to access the node to be deleted
        struct node *ptr_prev = NULL; // create an external pointer ptr_prev to access the previous node
        
        for(int i=1; i<pos && ptr != NULL; i++)  //loops until position is fuound and ptr is not null 
        {
            ptr_prev = ptr; // located node is assigned to its previous node 
            ptr = ptr->next; //located node's next is assigned to located node 
        }
        
        if(ptr == NULL) // if located node is null
        {	
            printf("\n Position out of range."); //it cannot be deleted 
        }
        else if(ptr == head) //if located ndoe is head 
        {	
            head = ptr->next; // located node's next is assigned to head 
            free(ptr); //free memory 
        }
        else
        {	
            ptr_prev->next = ptr->next; //located node's next node is assigned to its previous node's next 
            free(ptr); //free memory 
        }
    }
}



void print_list()// function to print the list 
{	
    if(head == NULL) //if head is null
    {	
        printf("\n empty list!"); //list is empty 
    }
    else
    {
        struct node *ptr = head; // assigning ptr to head 
        while(ptr != NULL) //loop until  ptr pointer is not null 
        {	
            printf("\n %d",ptr->data); //print values
            ptr = ptr->next; //update the ptr 
        }
    }
}



void main() //main function 
{
	int choice; //choice variable to take user's choice 
	
	while(choice!=9) //loop until; choice is not 9 
	{
		printf("*************MENU************"); //menu 
		
		printf("\n1.insert at beg\n2.insert at end\n3.insert at mid\n4.delete at beg\n5.delete at end\n6.delete at mid\n7.print\n8.exit"); //menu options
		
		
		printf("\n enter your choice:"); //displays message 
		scanf("%d",&choice); //scans choice of the user 
		
		switch(choice) //switches between the options of menu  to match the choice of the user 
		{	
			case 1:
				int val1; //variable to insert item 
				printf("\n enter val:");
				scanf("%d",&val1); //scans item 
				
				insert_beg(val1); //calling insert at beginning function 
				break;
			case 2:
				int val2;//variable to insert item
				printf("\n enter val:");
				scanf("%d",&val2);
				
				insert_last(val2);//calling insert at end function 
				break;
			case 3:
				int val3;//variable to insert item
				printf("\n enter val:");
				scanf("%d",&val3);
				
				
				randominsert(val3);//calling insert at end function
				break;
			case 4:
				delete_beg(); //calling delete at beginning function
				break;
			case 5:
				delete_end();// calling delete at end function
				break;
			case 6:
				int pos4; //to store position 
				printf(" \n position to be deleted:");
				scanf("%d",&pos4);
				delete_pos(pos4); // calling delte at position function 
				break;
			
			case 7:
				print_list(); //calling print list function 
				break;
			case 8:
				exit(0); //terminating the program
				break;
		}
	}
}
			

	
		
			 
			
		
	
	
		

	
	
	
	
