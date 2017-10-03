/* Merging contents of two sorted Linked List */

#include<stdio.h>
#include<stdlib.h>

typedef struct myNode
{
	int data;
	struct myNode* next;
}node;

node *p,*q;

void Display(node** head)
{
	node* p;
	
	for(p=*head;p!=NULL;p=p->next)
		printf("%d ",p->data);
	
}

void CreateList(node** head, int num)
{
	p = (node*)malloc(sizeof(node));
	
	if(*head==NULL)
	{
		*head=p;
		p->data=num;
		p->next=NULL;
		
		q=p;
	}
	else
	{
		p->data=num;
		p->next=NULL;
		q->next=p;
		
		q=p;
	}
}

void MergeList(node** head1,node** head2,node** head3)
{
	node *a,*b;
	
	a=*head1;
	b=*head2;
	
	while(a!=NULL&&b!=NULL)
	{
		if(a->data <= b->data)
			{
				CreateList(head3,a->data);
				a=a->next;
			}
		else
			{
				CreateList(head3,b->data);
				b=b->next;
			}
	}
	
	if(a!=NULL)
	{
		while(a!=NULL)
		{
			CreateList(head3,a->data);
			a=a->next;
		}
	}
	
	if(b!=NULL)
	{
		while(b!=NULL)
		{
			CreateList(head3,b->data);
			b=b->next;
		}
	}
}
int main()
{
	int N1,N2,num,i;
	node *head1=NULL,*head2=NULL,*head3=NULL;
	
	printf("Enter number of elements in list 1 -> ");
	scanf("%d",&N1);
	
	printf("Enter the values in increasing order\n");
	
	p=q=NULL;
	
	for(i=1;i<=N1;i++)
	{
		scanf("%d",&num);
		
		CreateList(&head1,num);
	}
	
	printf("List 1 is ->\n");
	Display(&head1);
	
	printf("Enter number of elements in list 2 -> ");
	scanf("%d",&N2);
	
	printf("Enter the values in increasing order\n");
	
	p=q=NULL;
	
	for(i=0;i<N2;i++)
	{
		scanf("%d",&num);
		
		CreateList(&head2,num);
	}
	
	printf("List 2 is ->\n");
	Display(&head2);
	
	p=q=NULL;
	
	MergeList(&head1,&head2,&head3);
	
	printf("\n\n--Merged list is--\n\n");
	Display(&head3);	
}
