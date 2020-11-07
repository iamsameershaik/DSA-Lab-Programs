#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag=0;										//Initializing global variables.
char palindrome[15];

void addflag()
{
	flag=1;										//Changing the value of the reference variable.
}
void palcheck(int l)									//Function to check for a palindrome.
{
	int i, j;
	for(i=0, j=(l-1); i<=(l/2), j>(l/2); i++, j--)
	{
		if(palindrome[i]==palindrome[j])
			addflag();
		else
		{
			printf("It is not a palindrome.\n");
			exit(0);							//Built-in function to exit a program.
		}
	}
}

void main()										//Main function.
{
	int l, i, j;
	printf("Enter the string to check for palindrome : ");
	scanf("%s", palindrome);
	l=strlen(palindrome);								//Built-in function to get length of a string.
	palcheck(l);									//Function call to check for a palindrome.
	if(flag==1)									//Checking the value of reference variable.
		printf("It is a palindrome!\n");
}

