#include <stdlib.h>
#include <stdio.h>

int top=-1, stack[20];									//Initializing global variables.

void addtop()										//Function to increase top value.
{
    top++;
}
void subtop()										//Function to decrease top value.
{
    top--;
}
int overflow(int MAX)									//Function to check stack in overflow condition.
{
    if(top==(MAX-1))
        return 1;
    else
        return 0;
}
int underflow()										//Function to check stack in underflow condition.
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void push(int ele)									//Function to push an element in stack.
{
    addtop();										//Function call to increase top value.
    stack[top]=ele;
}
void pop()										//Function to pop an element in stack.
{
    printf("Popping element : %d \n", stack[top]);
    stack[top]='\0';
    subtop();										//Function call to decrease top value.
}
void display(int MAX)									//Function to diaplay the elements in stack
{
    if(underflow())									//Function call to check stack underflow condition.
    {
        printf("\nStack Underflow!\nTry pushing an element.\n");
        return;
    }
    else
    {
        for(int i=(MAX-1); i>=0; i--)
        {
            if(stack[i]==0)
                continue;
            else
                printf("%d \t", stack[i]);
        }
        printf("\n");
    }
}

void main()										//Main function.
{
    int ele, opt, MAX=0;
    char wish='y';
    printf("Enter the maximum stack size : ");
    scanf("%d", &MAX);
    do
    {
        printf("\nCurrent stack size : %d \n1. Push element.\n2. Pop element.\n3. Display stack.\n4. Exit.\nEnter your choice : ", (top+1));
        scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                 if(overflow(MAX))							//Function call to check oveflow condition.
                    printf("\nStack Overflow!\nTry popping an element.\n");
                else
                {
                    printf("Enter the element to be pushed : ");
                    scanf("%d", &ele);
                    push(ele);								//Function call to push an element.
                }
            break;
            case 2:
                if(underflow())								//Function call to check underflow condition.
                    printf("\nStack Underflow!\nTry pushing an element.\n");
                else
                    pop();								//Function call to pop an element.
            break;
            case 3:
                display(MAX);								//Function call to display the elements in stack.
            break;
            case 4: exit(0);
            default:
                printf("Invalid choice!\n");
        }
    printf("Wish to continue? (y/n) : ");
    scanf(" %c", &wish);
    }while(wish=='y'||wish=='Y');
}

