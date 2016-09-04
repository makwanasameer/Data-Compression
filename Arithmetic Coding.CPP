#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i=0,j=0,k=0;
static char symbol[26];
static int freq[26];
static int cum_count[26];
static int tot_count;
static int scale=0;
//static int part[10][10];
//static int code[10][10];
void main()
{
	FILE *fp;
	char ch;
	clrscr();

	void insert(char *,int *,char);
	void display(char *ptr1,int *ptr2);
	void sort(char *ptr1,int *ptr2);
	int sum(int,int,int *);
	void map(int ,int);
	void make_cum(void);
	void shift_left(int *ptr1,int * ptr2);
     //	void part(int ,int ,int *);

	for(int p=0;p<26;p++)
	{
		symbol[p]='\0';
		freq[p]=0;
	}
	fp=fopen("c:\\test.txt","r");
	while((ch=getc(fp))!=EOF)
	{
		insert(&symbol[0],&freq[0],ch);

	}
     //	printf("*****i= %d  ",i);
	display(&symbol[0],&freq[0]);
	make_cum();
	map(8,2);

}
void map(int l,int u)
{
	static int temp1=l,bin1[8],z=0;
	static int temp2=u,bin2[8],x=0;

	while(temp1>0)
	{
		bin1[z]=temp1%2;
		temp1=temp1/2;
		z++;
		printf("#");
	}

	while(temp2>0)
	{
		bin2[x]=temp2%2;
		temp2=temp2/2;
		x++;
	}

	for(i=0;i<8;i++)
		printf("\n%d   %d\n",bin1[i],bin2[i]);


	// for e0 mappings
	if(bin1[8]==0&&bin2[8]==0)
	{ //e1 mapping


	}else if(bin1[8]==1&&bin2[8]==1)
	{ //e2 mapping

	}else if((bin1[8]==0&&bin1[7]==1)&&(bin2[8]==1&&bin2[7]==0) || (bin1[7]==0&&bin1[8]==1)&&(bin2[7]==1&&bin2[8]==0))
	{             //e3 mapping

	}




}
void shift_left(int *ptr1,int * ptr2)
{
	for(int i=0;i<8;i++)
	{
		*(ptr1+i)=*(ptr1+i+1);
		*(ptr2+i)=*(ptr2+i+1);
	}

	*(ptr1+i)=0;
	*(ptr2+i)=1;


}


void make_cum(void)
{

	for(int l=0;l<=i;l++)
	{
		int sum=0;
		for(int m=0;m<l;m++)
		{
			sum=sum+freq[m];
		}
		cum_count[l]=sum;
	}
	printf("\n");
	for( l=0;l<=i;l++)
		printf("##%d\n",cum_count[l]);
}


void insert(char *ptr1,int *ptr2,char ch)
{       int l=0;
	if(i==0)
	{
		*ptr1=ch;
		i++;
		*ptr2=1;
	}
	else
	{       int flag=1;
		for(l=0;l<i;l++)
		{
			if(symbol[l]==ch)
			{
				  flag=0;
				  break;
			}

		}
		if(flag==0)
		{
			*(ptr2+l)=((*(ptr2+l))+1);
		}
		else
		{
			*(ptr1+i)=ch;

			*(ptr2+i)=1;
			i++;
		}
	}
}
void display(char *ptr1,int *ptr2)
{       int l=0;
	for(l=0;l<i;l++)
	{
		printf("symbol=%c    frequency=%d\n",*(ptr1+l),*(ptr2+l));
	}
}
