#include<stdio.h>
#include<stdlib.h>

typedef struct myNode
{
	int data;
	struct myNode* next;
}node;

void FindCommon(node* head1, node* head2, node** head3)
{
	int flag;
	
	node *p,*q,*y,*z;
	
	for(p=head1;p!=NULL;p=p->next)
	{
		flag=0;
		
		for(q=head2;q!=NULL;q=q->next)
		{
			if(p->data==q->data)
			{
				flag=1;
				break;
			}	
		}
		
		if(flag==0)
		{
			y=(node*)malloc(sizeof(node));
			
			if(*head3==NULL)
			{
				y->data = p->data;
				y->next=NULL;
				*head3 = y;
				z=y;
			}
			else
			{
				y->data = p->data;
				z->next = y;
				y->next=NULL;
				z=y;
			}	
		}
	}
	
}

int main()
{
	int i,N1,N2;
	
	node *p,*q,*head1=NULL,*head2=NULL,*head3=NULL;
	lab :
		
	printf("Enter the number of elements in list 1 and list 2 -> ");
	scanf("%d %d",&N1,&N2);
	
	if( N1 <=0 || N2 <=0 )
	{
		printf("Enter positive numbers only");
		goto lab;
	}
	
	printf("Enter elements of list 1\n");
	
	for(i=0;i<N1;i++)
	{
		p = (node*)malloc(sizeof(node));
		
		if(i==0)
		{
			scanf("%d",&p->data);
			p->next=NULL;
			head1 = p;
			q=p;
		}
		else
		{
			scanf("%d",&p->data);
			q->next=p;
			p->next=NULL;
			q=p;
		}
	}
	
	printf("Enter elements of list 2\n");
	
	for(i=0;i<N2;i++)
	{
		p = (node*)malloc(sizeof(node));
		
		if(i==0)
		{
			scanf("%d",&p->data);
			p->next=NULL;
			head2 = p;
			q=p;
		}
		else
		{
			scanf("%d",&p->data);
			q->next=p;
			p->next=NULL;
			q=p;
		}
	}
	
	FindCommon(head1,head2,&head3);
	FindCommon(head2,head1,&head3);
	
	printf("New List is -\n\n");
	
	N1=0;
	
	for(p=head3;p!=NULL;p=p->next)
	{
		N1=1;
		printf("%d ",p->data);
	}
	
	if(N1==0)
	printf("List is empty\n");
}
