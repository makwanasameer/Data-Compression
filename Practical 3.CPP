#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int weight;
	int node_no;
	struct node *left;
	struct node *right;
}*root,*tmp;
int m,e,r;
void main()
{
	typedef struct node duplicate;
	struct node *ptr=(struct node *)malloc( sizeof(duplicate) );
	printf("%d",sizeof(duplicate));

/*	FILE *fp;
	fp=fopen("c:\test.txt","r");
       //	fclose(fp);
	printf("Enter the value of the m:");
	scanf("%d",&m);
	printf("Enter the value of the e:");
	scanf("%d",&e);
	r=m-pow(2,e);

	while(1)
	{
		printf("Do you want to enter ?\n");
		printf("       ");
		scanf("%d",&choice);
	}
	*/



}