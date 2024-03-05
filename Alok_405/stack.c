#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum number of elements that can be stored

int top = -1;
int stack[MAX];

void push();
void pop();
void display();

int main()
{
    int ch;
    while (1) // Infinite loop, will end when choice is 4
    {
        printf("\n*** Stack Menu ***\n");
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong Choice!!\n");
        }
    }
    return 0;
}

void push()
{
    int val;
    if (top == MAX - 1)
    {
        printf("\nStack is full!!\n");
    }
    else
    {
        printf("\nEnter element to push: ");
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack is empty!!\n");
    }
    else
    {
        printf("\nDeleted element is %d\n", stack[top]);
        top--;
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("\nStack is empty!!\n");
    }
    else
    {
        printf("\nStack is...\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
