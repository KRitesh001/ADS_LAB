#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    int x;
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter element: ");
        scanf("%d",&x);
        top++;
        stack[top] = x;
        printf("Element inserted successfully.\n");
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Deleted element = %d\n", stack[top]);
        top--;
    }
}

void peek()
{
    if(top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top element = %d\n", stack[top]);
    }
}

void display()
{
    int i;
    if(top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements:\n");
        for(i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int ch;

    do
    {
        printf("\n--- STACK USING ARRAY ---\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("Program Ended\n"); break;
            default: printf("Invalid Choice\n");
        }

    }while(ch != 5);

    return 0;
}
