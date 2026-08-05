#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push()
{
    int x;
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter element: ");
    scanf("%d",&x);

    temp->data = x;
    temp->next = top;
    top = temp;

    printf("Element inserted successfully.\n");
}

void pop()
{
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        temp = top;
        printf("Deleted element = %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void peek()
{
    if(top == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top element = %d\n", top->data);
    }
}

void display()
{
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements:\n");
        temp = top;
        while(temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int ch;

    do
    {
        printf("\n--- STACK USING LINKED LIST ---\n");
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
