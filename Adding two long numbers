#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct myNode
{
	int data;
	struct myNode* prev;
	struct myNode* next;
}node;

node* head3end;

node* FindEnd(node* head)
{
	node *p=NULL,*q=NULL;
	
	for(p=head;p!=NULL;p=p->next)
		q=p;
	
	return q;
}

void Displayreverse(node** head3)
{
	node* p = FindEnd(*head3);
	
	head3end = p;
	
	node* i;
	
	for(i=p;i!=NULL;i=i->prev)
	{
		printf("%d",i->data);
	}
}
void Add(node** head1, node** head2,node** head3)
{
	int num,carry=0,value;
	
	node* end1 = FindEnd(*head1);
	node* end2 = FindEnd(*head2);
	
	node *p,*q,*a,*b,*left,*z;
	
	for(p=end1,q=end2;;)
	{
		
		if((p==NULL)&&(q==NULL))
		break;
		
		if((p!=NULL)&&(q!=NULL))
		num = p->data + q->data + carry;
		else
		{
			if(p==NULL)
			num = q->data + carry;
			else
			if(q==NULL)
			num = p->data + carry;
		}
		
		if(num<10)
		{
			value = num;
			carry=0;
		}
		else
		{
			value = num%10;
			carry = 1;
		}
		
		a = (node*)malloc(sizeof(node));
		
			if(*head3==NULL)
			{
				a->data=value;
				*head3=a;
				a->prev=NULL;
				a->next=NULL;
				b=a;
			}
			else
			{
				a->data=value;
				a->prev=b;
				a->next=NULL;
				b->next=a;
			
				b=a;
			}
			
		if((p!=NULL)&&(q!=NULL))
		{
			p=p->prev;
			q=q->prev;
		}
		else
		{
			if(p==NULL)
			q=q->prev;
			else
			if(q==NULL)
			p=p->prev;
		}
		
		//printf("%p\n",p);
		//printf("%p\n",q);
	}
		
	if(p==NULL&&q==NULL)
	{
		if(carry==1)
		{
			a = (node*)malloc(sizeof(node));
			
			a->data=carry;
			a->prev=b;
			a->next=NULL;
			b->next=a;
			
			b=a;
		}
	}
	
}
void Display(node** head)
{
	node *p;
	
	for(p=*head;p!=NULL;p=p->next)
		printf("%d",p->data);
}

void Createlist(char str[], node** head)
{
	int num,i;
	node *p,*q;
	
	for(i=0;i<strlen(str);i++)
	{
		num = str[i] - 48;
		
		p=(node*)malloc(sizeof(node));
		
		if(*head==NULL)
		{
			p->data=num;
			*head=p;
			p->prev=NULL;
			p->next=NULL;
			q=p;
		}
		else
		{
			p->data=num;
			p->prev=q;
			p->next=NULL;
			q->next=p;
			
			q=p;
		}
	}
}
int main()
{
	char str1[100],str2[100];
	
	node *head1=NULL, *head2=NULL, *head3=NULL;
	
	printf("Enter first number\n");
	scanf("%s",str1);
	
	printf("Enter second number\n");
	scanf("%s",str2);
	
	Createlist(str1,&head1);
	Createlist(str2,&head2);
	
	printf("Entered numbers are\n");
	Display(&head1);
	printf("\n\n");
	Display(&head2);
	
	Add(&head1,&head2,&head3);
	
	printf("\n\nResult of Addition is\n");
	Displayreverse(&head3);
}
