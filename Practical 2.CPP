#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i=0,j=0;
static char symbol[26];
static int freq[26];
static int part[10][10];
static char code[20];
static char char1[20];
static int o;

	void take_last_two(void);
	void insert(char *,int *,char);
	void display(char *ptr1,int *ptr2,int);
	void sort(char *ptr1,int *ptr2,int);
	int sum(int,int,int *);
	void bubble(char *ptr1,int *ptr2,int t);
void main()
{
	FILE *fp;
	char ch;
	clrscr();

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
	printf("*****i= %d  \n",i);
	display(&symbol[0],&freq[0],i);
	sort(&symbol[0],&freq[0],i);
	printf("\nSorted:: \n");
	display(&symbol[0],&freq[0],i);
	o=i;

	printf("\ntemp =%d",sum(0,4,freq));
	take_last_two();
}
void take_last_two(void)
{       int l=o;
	int row=0,column=0;



	while(l>2)
	{
		part[row][column]=0;
		code[row]=symbol[l-2];
		row++;
		part[row][column]=1;
		code[row]=symbol[l-1];
		row++;
		freq[l-2]=freq[l-1]+freq[l-2];
		l--;

		bubble(&symbol[0],&freq[0],l);
		printf("\n");
		display(&symbol[0],&freq[0],l);
		getch();
	}

	printf("\n");
	for(int i=0;i<7;i++)
	{
		printf("code :%c value:%d\n",code[i],part[i][0]);
	}

}

void insert(char *ptr1,int *ptr2,char ch)
{
	int l=0;
	if(i==0)
	{
		*ptr1=ch;
		i++;
		*ptr2=1;
	}
	else
	{
		int flag=1;
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
void display(char *ptr1,int *ptr2,int t)
{       int l=0;
	for(l=0;l<t;l++)
	{
		printf(" Symbol=%c  and  Frequency=%d\n",*(ptr1+l),*(ptr2+l));
	}
}

void sort(char *ptr1,int *ptr2,int t)
{       int l=0,m=0;
	char temp_sym;
	int temp_int;
	for(l=0;l<t;l++)
	{
		for(m=l+1;m<t;m++)
		{

			if(*(ptr2+l) < *(ptr2+m))       //minimum variance
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

//selecton sort does not work

void bubble(char *ptr1,int *ptr2,int t)
{       int l=0,m=0;
	char temp_sym;
	int temp_int;
	for(l=0;l<t;l++)
	{
		for(m=0;m<t-l;m++)
		{

			if(*(ptr2+m) < *(ptr2+m+1))       //minimum variance
			{
				temp_int=*(ptr2+m);
				*(ptr2+m)=*(ptr2+m+1);
				*(ptr2+m+1)=temp_int;
				temp_sym=*(ptr1+m);
				*(ptr1+m)=*(ptr1+m+1);
				*(ptr1+m+1)=temp_sym;

			}

		}


	}
}










