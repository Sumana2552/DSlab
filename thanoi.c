//tower of hanoi 
#include<stdio.h> //preprocessor directive

void towerhanoi(int n , char from_rod, char aux_rod, char to_rod) //function to implement tower of hanoi 
{
	if(n==1) //if noly one disk is present 
	{
		printf("\nMove disk 1 from rod %c to %c\n", from_rod,to_rod); // moving disk from one rod to another
		return;
	}
	towerhanoi(n-1, from_rod, to_rod, aux_rod); //recursively calling the function 
	
	
	printf("\n move disk %d, from rod %c to %c\n",n, from_rod, to_rod); //moving disk from one rod to another
	
	towerhanoi(n-1, aux_rod, from_rod, to_rod); //recursively calling the function 
}
int main() //main function
{
	int n; //variable initialization for num of disks
	printf("num of disks:");
	scanf("%d",&n); //scans the number of disks
	
	towerhanoi(n, 'A', 'C', 'B'); //invoking the function
}
