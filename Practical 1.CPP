#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i=0,j=0;
static char symbol[26];
static int freq[26];
static int part[10][10];
static int code[10][10];
void main()
{
	FILE *fp;
	char ch;
	clrscr();

	void insert(char *,int *,char);
	void display(char *ptr1,int *ptr2);
	void sort(char *ptr1,int *ptr2);
	int sum(int,int,int *);
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
	sort(&symbol[0],&freq[0]);
	printf("\n");
	display(&symbol[0],&freq[0]);
    //	printf("\ntemp =%d",sum(0,4,freq));

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

void sort(char *ptr1,int *ptr2)
{       int l=0,m=0;
	char temp_sym;
	int temp_int;
	for(l=0;l<i-1;l++)
	{
		for(m=l+1;m<i;m++)
		{

			if(*(ptr2+l) < *(ptr2+m))
			{
				temp_int=*(ptr2+m);
				*(ptr2+m)=*(ptr2+l);
				*(ptr2+l)=temp_int;
				temp_sym=*(ptr1+m);
				*(ptr1+m)=*(ptr1+l);
				*(ptr1+l)=temp_sym;

			}

		}


	}
}

int sum(int l,int m,int *ptr)
{       int temp=0;
	while(l<m)
	{
		temp=temp+*(ptr+l);
		l++;
	}
	return temp;
}
	 // logic for making the partion and codes
/*void part(int l,int m,int *ptr)
{
		int temp1;
		int temp2;
		int prev_sum=0;
		int sums=0;
		int k=1,g=0,h=0,i=0;
		while(k>0)
		{
			temp1=sum(l,k-m-1,ptr);
			temp2=sum(m-k,m,ptr);
			prev_sum=sums;
			if(sums<=prev_sum&&sums>=0)
			{    //   int g,h,i;
				sums=temp1-temp2;
				g=l;
				h=m;
				i=k;
			}
			k++;
		}
		for(int i=0;i<m;i++)
		{
			if(i<m-k)
			{
				code[0][0]=0;
			}
			else
				code[0][0]=1;
		}

}
  */









