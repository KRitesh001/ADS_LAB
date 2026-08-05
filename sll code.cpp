#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *head=NULL;
void ins_beg(int x)
{
  struct node *temp;
  temp=(struct node *)malloc(sizeof(struct node*));
  temp->data=x;
  temp->next=NULL;
  if(head==NULL)
  {
	head=temp;
  }	
  else
  {
  	temp->next=head;
	head=temp;	
  }
}
void ins_end(int x)
{
  struct node *temp,*t;
  temp=(struct node *)malloc(sizeof(struct node*));
  temp->data=x;
  temp->next=NULL;
  if(head==NULL)
  {
	head=temp;
  }	
  else
  {
  	t=head;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=temp;
 }
}
void ins_pos(int x,int pos)
{
  struct node *temp,*t;
  int c=1;
  temp=(struct node *)malloc(sizeof(struct node*));
  temp->data=x;
  temp->next=NULL;
  if(head==NULL)
  {
	head=temp;
  }	
  else
  {
  	t=head;
	while(c<pos-1)
	{
		t=t->next;
		c++;
	}

	t->next=temp;
 }
}
void del_beg()
{
	struct node *t;
	if(head==NULL)
		printf("List is empty");
	else
		{
			t=head;
			head=head->next;
			printf("\n deleted node info is %d",t->data);
			free(t);
			}	
}	
void del_end()
{
	struct node *t=head;
	if(head==NULL)
		printf("List is empty");
	else
	{
		while(t->next->next!=NULL)
			t=t->next;
		printf("\n Deleted node info is %d",t->next->data);
		free(t->next);
		t->next=NULL;	
	}	
}
void del_pos(int pos)
{
	struct node *t1,*t=head;
	int c=0;
	if(head==NULL)
		printf("List is empty");
	else
		{
			while(c<pos-1)
			
				t=t->next;
				c++;
			}
		t1=t->next;
		printf("\n Deleted node info is %d",t1->data);
		t->next=t1->next;
		free(t1);	
		}	
}
void display()
{
	struct node *t=head;
	if(head==NULL)
		printf("List is empty");
	else
	{	
	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->next;
	}
	}
}
int search(int k)
{
	struct node *t=head;
	int c=0;
	while(t!=NULL)
	{
	  if(t->data==k)
	  {
	   c++;00000000
	   return(c); 	
	  }
	  else
	    t=t->next;
    }
    return (-1);
}
main()
{
int ch,c,x,pos;
do
{	
printf("\n Enter ur choice: 1.Insbeg,2.insend,3.inspos,4.delbeg,5.delend,6.delpos,7.search :");
scanf("%d",&ch);
switch(ch)
{
	case 1:printf("\n enter element to be inserted:");
		   scanf("%d",&x);
		   ins_beg(x);
		   display();
		   break;
	case 2:printf("\n enter element to be inserted:");
		   scanf("%d",&x);
		   ins_end(x);
		   display();
		   break;
	case 3:printf("\n enter element and position to be inserted:");
		   scanf("%d%d",&x,&pos);
		   ins_pos(x,pos);
		   display();
		   break;
	case 4:del_beg();
		   display();
		   break;
	case 5:del_end();
		   display();
		   break;	   	   	   	   
	case 6:printf("\n enter position to be deleted :");
		   scanf("%d",&pos);
		   del_pos(pos);
		   display();
		   break;
	case 7:printf("enter element to be searched");
		   scanf("%d",&x);
		   if(search(x)!=-1)
		   	printf("%d is found at %d position",x,search(x));
		   else
		   	printf("%d is not found",x);
			break;	   	   	   	
}
printf("\n Do you want to continue 1-yes,0-no");
scanf("%d",&c);
}while(c);
}

