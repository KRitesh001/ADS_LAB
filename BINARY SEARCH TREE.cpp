#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node *root=NULL;
int found=0;

// Create Node
struct node* createNode(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

// Insert
void insert(int x)
{
    struct node *temp=createNode(x);

    if(root==NULL)
    {
        root=temp;
        printf("\n%d inserted as the root node.\n",x);
        return;
    }

    struct node *p=root,*parent=NULL;

    while(p!=NULL)
    {
        parent=p;

        if(x<p->data)
            p=p->left;

        else if(x>p->data)
            p=p->right;

        else
        {
            printf("\nDuplicate element. Insertion not allowed.\n");
            free(temp);
            return;
        }
    }

    if(x<parent->data)
        parent->left=temp;
    else
        parent->right=temp;

    printf("\n%d inserted successfully.\n",x);
}

// Search
void search(int x)
{
    struct node *p=root;

    while(p!=NULL)
    {
        if(x==p->data)
        {
            printf("\n%d found in the tree.\n",x);
            return;
        }

        else if(x<p->data)
            p=p->left;

        else
            p=p->right;
    }

    printf("\n%d not found in the tree.\n",x);
}

// Minimum Value Node
struct node* minValue(struct node *p)
{
    while(p->left!=NULL)
        p=p->left;

    return p;
}

// Delete
struct node* deleteNode(struct node *p,int x)
{
    if(p==NULL)
        return NULL;

    if(x<p->data)
        p->left=deleteNode(p->left,x);

    else if(x>p->data)
        p->right=deleteNode(p->right,x);

    else
    {
        found=1;

        // Case 1: No Left Child
        if(p->left==NULL)
        {
            struct node *temp=p->right;
            free(p);
            return temp;
        }

        // Case 2: No Right Child
        else if(p->right==NULL)
        {
            struct node *temp=p->left;
            free(p);
            return temp;
        }

        // Case 3: Two Children
        else
        {
            struct node *temp=minValue(p->right);

            p->data=temp->data;

            p->right=deleteNode(p->right,temp->data);
        }
    }

    return p;
}

// Inorder
void inorder(struct node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}

// Preorder
void preorder(struct node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

// Postorder
void postorder(struct node *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }
}

int main()
{
    int ch,x;

    while(1)
    {
        printf("\n====================================");
        printf("\n      BINARY SEARCH TREE");
        printf("\n====================================");
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Delete");
        printf("\n4. Inorder Traversal");
        printf("\n5. Preorder Traversal");
        printf("\n6. Postorder Traversal");
        printf("\n7. Exit");
        printf("\n====================================");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter value to insert: ");
                scanf("%d",&x);
                insert(x);
                break;

            case 2:

                if(root==NULL)
                {
                    printf("\nTree is empty.\n");
                    break;
                }

                printf("\nEnter value to search: ");
                scanf("%d",&x);
                search(x);
                break;

            case 3:

                if(root==NULL)
                {
                    printf("\nTree is empty.\n");
                    break;
                }

                printf("\nEnter value to delete: ");
                scanf("%d",&x);

                found=0;

                root=deleteNode(root,x);

                if(found)
                {
                    printf("\n%d deleted successfully.\n",x);

                    if(root==NULL)
                        printf("Tree is now empty.\n");
                }
                else
                {
                    printf("\n%d not found in the tree.\n",x);
                }

                break;

            case 4:

                if(root==NULL)
                {
                    printf("\nTree is empty.\n");
                }
                else
                {
                    printf("\nInorder Traversal : ");
                    inorder(root);
                    printf("\n");
                }

                break;

            case 5:

                if(root==NULL)
                {
                    printf("\nTree is empty.\n");
                }
                else
                {
                    printf("\nPreorder Traversal : ");
                    preorder(root);
                    printf("\n");
                }

                break;

            case 6:

                if(root==NULL)
                {
                    printf("\nTree is empty.\n");
                }
                else
                {
                    printf("\nPostorder Traversal : ");
                    postorder(root);
                    printf("\n");
                }

                break;

            case 7:
                printf("\nProgram terminated successfully.\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please enter between 1 and 7.\n");
        }
    }

    return 0;
}
