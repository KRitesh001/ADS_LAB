#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create Node
struct node* createNode(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

// Insert at End
void insert()
{
    int x;
    printf("Enter element: ");
    scanf("%d",&x);

    struct node *temp = createNode(x);

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *p = head;
        while(p->next != NULL)
            p = p->next;

        p->next = temp;
    }

    printf("Element inserted successfully.\n");
}

// Reverse Linked List
void reverse()
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    if(head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    printf("Linked List reversed successfully.\n");
}

// Display
void display()
{
    struct node *p = head;

    if(head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    printf("Linked List: ");

    while(p != NULL)
    {
        printf("%d -> ",p->data);
        p = p->next;
    }

    printf("NULL\n");
}

int main()
{
    int ch;

    while(1)
    {
        printf("\n===== REVERSE SINGLY LINKED LIST =====");
        printf("\n1. Insert");
        printf("\n2. Reverse");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                insert();
                break;

            case 2:
                reverse();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program terminated successfully.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
