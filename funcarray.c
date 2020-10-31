#include <stdio.h>
#include <stdlib.h>

//Initializing global variables.
int a[7];
int final=7;
int n=0;
int count=0;
 
//Defining the functions.
void chnglb()
{
	count++;
}
void delglb()										//Function to reduce size of the array after deleting.
{
	n--;
}
void size()										//Function to enter the size of the array.
{
	printf("Enter size of array: ");
	scanf("%d",&n);
	if(n>final)
	{
		printf("Size maxed out! Maximum size : %d \n", final);
		exit(0);
	}
}
void read(int *a, int n)								//Function to read the values in the array.
{ 
	int i;
	for(i=0;i<n;i++)
	{	
		scanf("%d", &a[i]);
		chnglb();								//Function call.
	}
}     
void display(int *a, int n)								//Function to display elements in the array.
{ 
	int i;
	if(count==0)
	{
		printf("No elements detected! Try entering elements.\n");
		return;
	}
	for(i=0;i<n;i++)
		printf("%d   ", a[i]);
	printf("\n");
}
void insert(int *a, int n)								//Function to insert extra elements in the array.
{											//What if element is to be inserted at 6th pos but 
	int i, temp, ele, pos;								//array has only 2 elements
	printf("Enter the element to be inserted: ");
	scanf("%d", &ele);
	printf("Enter the position where the element is to be inserted:");
	scanf("%d", &temp);
	pos=temp-1;
	for(i=n-1; i>=pos; i--)
		a[i+1]=a[i];
	a[pos]=ele;
}
void delete(int *a, int n)								//Function to delete elements from the array.
{
	int del=0;
	if(count==0)
	{
		printf("No elements detected! Try entering elements.\n");
		return;
	}
	int i, ele;
	printf("Enter the element to be deleted: ");
	scanf("%d", &ele);
	for(i=0; i<n; i++)
	{
		if(ele==a[i])
		{
			del=1;
			int top;
			top=i;
			for(int j=top; j<n; j++)
				a[j]=a[j+1];
			delglb();							//Function call to reduce size.	
		}
	}
	if(del==0)
		printf("No element detected!");
}

void main()										//Main function.
{
	int i, ch, del, ele;
	char wish='y';
	size();										//Function call to enter size.
	do
	{
		printf("\nMAIN MENU\nCurrent array size: %d \n1. Enter elements.\n2. Print elements.\n3. Insert elements.\n4. Delete elements.\n5. Exit.\nEnter your choice:", n);
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
			{
				if(n==0)
				{
					printf("Size too short!\n");
					exit(0);
				}
				else
				{
					printf("Enter the array elements: \n");
					read(a, n);					//Function call to enter elements.
					break;
				}
			}
			case 2:
			{
				if(n==0)
				{
					printf("Size too short, nothing to be displayed!\n");
					exit(0);
				}
				else
				{
					printf("Elements in the array are: ");
					display(a, n);					//Function call to display elements.
					break;
				}
			}
			case 3:
			{
				if(n==0)
				{
					printf("Enter the element to be inserted: ");
					scanf("%d", &ele);
					a[0]=ele;
					n++;
					break;
				}

				else
				{
					insert(a, n);					//Function call to insert elements.
					n++;
					break;
				}
			}
			case 4:
			{
				if(n==0)
				{
					printf("There aren't any elements present!\n");
					exit(0);
				}
				else
				{
					delete(a, n);					//Function call to delete elements.
					break;
				}
			}
			case 5: exit(0);
				break;
			default:
				printf("INVALID CHOICE!");
		}
		printf("\nWish to continue? (y/n):");
		scanf(" %c", &wish);
	}while(wish=='y');
}

