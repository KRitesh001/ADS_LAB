#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue()
{
    int x;

    if(rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter element: ");
        scanf("%d",&x);

        if(front == -1)
            front = 0;

        rear++;
        queue[rear] = x;

        printf("Element inserted successfully.\n");
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleted element = %d\n", queue[front]);
        front++;

        if(front > rear)
        {
            front = rear = -1;
        }
    }
}

void peek()
{
    if(front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Front element = %d\n", queue[front]);
    }
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements:\n");

        for(i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int ch;

    do
    {
        printf("\n--- QUEUE USING ARRAY ---\n");
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
