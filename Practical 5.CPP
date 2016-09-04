
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct node
{
	int no;
	int weight;
	char ch;
	struct node *left;
	struct node *right;
}*root;
// if symbol is nyt insert ch=null;

void check(struct node *ppp);
int char_convert(char ch);
char name[20];
int m=26;
int r=10;


void main()
{

	printf("Enter the string");
	scanf("%s",name);

	int i=0;
	while(i<10)
	{

		struct node *ptr=(struct node *)malloc(sizeof(struct node));
		printf("Enter the value of the n::\n");
		int n;
		scanf("%d",&n);

		ptr->no=n;
		ptr->left=NULL;
		ptr->right=NULL;

		if(i==0)
		{       i++;
			root=ptr;
			root->left=NULL;
			root->right=NULL;
		}
		else
		{       i++;
			struct node *temp=root;

			char ch=' ';
			while(ch!='q')
			{
			check(temp);
			printf("Enter l for left traversal and r for right and i for insertion ::\n");
			flushall();
			scanf("%c",&ch);
			if(ch=='l')
			{

				temp=temp->left;
				ch=' ';
			}
			else if(ch=='r')
			{
				temp=temp->right;
				ch=' ';
			}
			else{
				printf("Enter at what position::");
				flushall();
				scanf("%c",&ch);
				if(ch=='l'){
						temp->left=ptr;
				}else if(ch=='r'){
						temp->right=ptr;
				}
				ch='q';
			}
			} //end of while
		}
	}
}



void check(struct node *ppp)
{
	if(ppp->left==NULL)
	{
		printf("\nLeft node NULL\n");
	}else
	{
		printf("\nLeft node can be traversed\n");
	}
	if(ppp->right==NULL)
	{
		printf("\nRight node NULL\n");
	}else
	{
		printf("\nRight node can be traversed\n");
	}
}

int char_convert(char ch)
{
	int c=ch-25;
	return(c);
}

void traversal(void)
{
	struct node *temp=root;
	while(temp->left!=NULL)
	{
		temp=temp->left;
		temp=temp->right;
	}
}
