/* NAME : G SRI PRABHA SUMANA 
USN: 1NT21IS058 SEM: III
SEC: A BRANCH: ISE
*/



// Tree traversal in C

#include <stdio.h>
#include <stdlib.h>

struct node //tree node 
{
	  int data; // data part of the node 
	  struct node* left;  //link to node's left child 
	  struct node* right; // link to node's right child 
};

// function for Inorder traversal
void inorderTraversal(struct node* root) //(left->root->right)
{
	  if (root == NULL)  //condition to check if the tree is not present 
	  	return;
	  inorderTraversal(root->left); // visiting the left child of the root node 
	  printf("%d ->", root->data); //printing data present in it 
	  inorderTraversal(root->right); //visiting the right child of the root node 
}


void preorderTraversal(struct node* root) // function definition for preorder traversal (root->left->right)
{
	  if (root == NULL) //condition to check if the tree is not present
	  	return;
	  printf("%d ->", root->data); // printing the data present in root node 
	  preorderTraversal(root->left); //printing data present in left child 
	  preorderTraversal(root->right); //printing data present in right child 
}

// postorder traversal (left->right->root)
void postorderTraversal(struct node* root) 
{
	  if (root == NULL) //condition to check if tree is present 
	  	return;
	  postorderTraversal(root->left); //prints data in left child 
	  postorderTraversal(root->right);//prints data in right child 
	  printf("%d ->", root->data); //prints data in root node 
}

// function to create a new node
struct node* createnode(int value) 
{
	  struct node* newnode = malloc(sizeof(struct node)); //allocating memory 
	  newnode->data = value; //insert value into the node
	  newnode->left = NULL; //left child sassigned to null
	  newnode->right = NULL; //right child assigned to null 

  	return newnode; //return the node when the function is called 
}

// function to insert on the left of the node
struct node* insertLeft(struct node* root, int value) 
{
	  root->left = createnode(value); //assigning the new node create to left child of root
	  return root->left; //returns  the left child 
}

// function to insert on the right of the node
struct node* insertRight(struct node* root, int value) 
{
	  root->right = createnode(value);//assigning the new node create to right child of root
	  return root->right; //returns  the right child 
}

int main() 
{
		  struct node* root = createnode(1); // creating a root node with value 1 
		  
		  insertLeft(root, 12); //inserting its left node to 12 
		  insertRight(root, 9);//inserting its right node to 9 

		  insertLeft(root->left, 5);//inserting its left node to 5
		  insertRight(root->left, 6);//inserting its right node to 6

		  printf("Inorder traversal \n");
		  inorderTraversal(root); // calling inordertraversal function 

		  printf("\nPreorder traversal \n");
		  preorderTraversal(root);// calling preordertraversal function 

		  printf("\nPostorder traversal \n");
		  postorderTraversal(root);// calling postordertraversal function 
}
