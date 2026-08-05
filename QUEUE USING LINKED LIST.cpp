#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    int x;
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter element: ");
    scanf("%d",&x);

    temp->data = x;
    temp->next = NULL;

    if(front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }

    printf("Element inserted successfully.\n");
}

void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        temp = front;
        printf("Deleted element = %d\n", front->data);

        front = front->next;

        if(front == NULL)
            rear = NULL;

        free(temp);
    }
}

void peek()
{
    if(front == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Front element = %d\n", front->data);
    }
}

void display()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements:\n");

        temp = front;

        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }
}

int main()
{
    int ch;

    do
    {
        printf("\n--- QUEUE USING LINKED LIST ---\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("Program Ended\n"); break;
            default: printf("Invalid Choice\n");
        }

    }while(ch != 5);

    return 0;
}
