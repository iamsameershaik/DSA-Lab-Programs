#include <stdio.h>
#include <string.h>

/*
char string[SIZE];
fgets(string, sizeof(string), stdin);
getline(string);
*/

char mainstr[20], patstr[20], repstr[20], tempstr[20];					//Initializing the global variables.

void read()										//Function to read the strings.
{
	printf("Enter the main string :");
	scanf("%s", mainstr);
	printf("Enter the pattern to be found :");
	scanf("%s", patstr);
	printf("Enter the replacing string :");
	scanf("%s", repstr);
}
void pattern_match()									//Function to check the pattern matching.
{
	int mi=0, pi=0, ri=0, ti=0, ci=0, flag=0;
	while(mainstr[mi]!='\0')
	{
		if(mainstr[ci]==patstr[pi])
		{
			ci++;
			pi++;
			if(patstr[pi]=='\0')
			{
				for(ri=0; repstr[ri]!='\0'; ri++)
				{
					tempstr[ti]=repstr[ri];
					ti++;
				}
			pi=0;
			mi=ci;
			flag=1;
			}
		}
		else
		{
			tempstr[ti]=mainstr[mi];
			ti++;
			mi++;
			pi=0;
			ci=mi;
		}
	}
	if(flag==1)									//If pattern is found.
	{
		tempstr[ti]='\0';
		printf("\nResulting string :");
		strcpy(mainstr, tempstr);						//Built-in function to copy one string into another.
		puts(mainstr);
	}
	else										//If pattern is not found.
		printf("Pattern not found!");
}

void main()										//Main function.
{
	read();										//Function call to read strings.
	pattern_match();								//Function call to check pattern matching.
}

