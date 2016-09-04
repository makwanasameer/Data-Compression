/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3
*/

#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<alloc.h>

struct temp
{
unsigned char c;
unsigned long long int freq;
unsigned int codeword[8];
int codelength;
}symbol[256];

int sort[256];
int noofsymbol=0;
void init(void);
void sorting(void);
void table(int,int);
void print_table(void);
void compressed(void);

char data[1024];

int length=0;

void main()
{
clrscr();
init();
FILE *fp,*fp1;
char t[1];




fp1=fopen("D:\\input.txt","rb");

 if(fp1==NULL)
 {
 printf("there is a error in opening a file\n");
 }
    printf("string which is read from the file\n");


while(!feof(fp1))
{
fread(t,1,1,fp1);
//strcpy(data,t);
data[length]=t[0];
printf("%c",data[length]);
length++;
}
getch();


fclose(fp1);


fp=fopen("D:\\input.txt","rb");

	if(fp==	NULL)
		{
			printf("there is a error in opening a file\n");


			}






while(!feof(fp))
{
     //	printf("\nin loop..\n");

	int k=fgetc(fp);

	symbol[k].freq++;
	if(symbol[k].freq==1)
		{
			noofsymbol++;
			symbol[k].codelength=0;

		}
}

for(int i=0;i<256;i++)
{

	if(symbol[i].freq!=0)
	{
	    //	printf("\n%c",symbol[i].c);
	      //	printf("\n\n");

	       //	printf("\t%d",symbol[i].freq);


	}
}

		printf("\n no of symbol:%d",noofsymbol);
   getch();


sorting();
table(0,noofsymbol-1);
print_table();
compressed();


getch();

}


void compressed(void)
{




FILE *fp;
fp=fopen("D:\\input.txt","w");
char *c;
itoa(noofsymbol,c,10);
fwrite(c,1,1,fp);
int temp;
for(int i=0;i<noofsymbol;i++)
{
	fwrite(&symbol[sort[i]].c,1,1,fp);
	itoa(symbol[sort[i]].codelength,c,10);
	fwrite(c,1,1,fp);
	temp=0;
	while(temp<symbol[sort[i]].codelength)
	{
		itoa(symbol[sort[i]].codeword[temp],c,10);
		fwrite(c,1,1,fp);
			temp++;

	}
}

unsigned char c1=0;
unsigned char c2=1;
//printf("startig %c",c1);
//printf("\nascii:%c and %i",c2,c2);
getch();
int j=0;
int ascii;
for(i=0;i<(length-1);i++)
{
temp=0;
	  ascii=data[i];
	  //printf("i=%d\tlength:%d",i,symbol[ascii].codelength);
		getch();
	while(temp<symbol[ascii].codelength)
	{
		j++;
		//printf("\n%d",j);
	       c1=c1<<1;
	       //	printf("\nbefore oring %c",c1);
		if(symbol[ascii].codeword[temp]==1)
		{
		 c1=c1|c2 ;

		}



		//printf("\n codeword..%d",symbol[ascii].codeword[temp]);
		temp++;
		if(j==8)
		{

			fwrite(&c1,1,1,fp);


		     //	printf("ascii:%d",c1);
		   //	printf("\nfile is wriiten %c \n",c1);

			j=0;
			c1=0;

		}

	}

}
	char *t1;

	t1=(char *)malloc(1);
	itoa(j,t1,10);

	fwrite(t1,1,1,fp);
       //	printf("\nfile is wriiten %d,%c \n",j,*t1);

	c1=c1<<(8-j);
	//}
	fwrite(&c1,1,1,fp);
       //	printf("\nfile is wriiten %c \n",c1);
}

void init(void)
{
	for(int i=0;i<256;i++)
	{

	symbol[i].c=i;
	//printf("%c",symbol[i].c);
	 symbol[i].freq=0;
	}


}

		void sorting(void)
	{

int temp=0;

int s1,s2,n;
for(int i=0;i<256;i++)
{

	if(symbol[i].freq!=0)

	{

	     sort[temp]=i;
	 //    printf("\nsort:%d",sort[temp]);
	     temp++;

	}
}

for(i=0;i<noofsymbol;i++)
{
      // printf("\nIN SORTING");

       s1=symbol[sort[i]].freq;

	for(int j=i+1;j<noofsymbol;j++)
	{

	  s2=symbol[sort[j]].freq;

		  if(s2>=s1)

		  {
			n=sort[i];
			sort[i]=sort[j];
			sort[j]=n;
			s1=symbol[sort[i]].freq;

		  }

	}

}
for(i=0;i<noofsymbol;i++)
{

      //	printf("\n%d\t%c\t%d",i,symbol[sort[i]].c,symbol[sort[i]].freq);

}


}




	void table(int start,int end)
{

int diff=0,index=0,a=0,b=0,total=0;
		      //	printf("start:%d",start);

	if(start>=end)
	{


	}
	else
	{


		for(int i=start;i<=end;i++)
		{

		    //	printf("\nfreq:%d",symbol[sort[i]].freq);

		   total+=symbol[sort[i]].freq;
		}
	      // printf("\ntotal:%d",total);
		diff=total;
		index=start;

		for(i=start;i<=end;i++)
		{
		 a+=symbol[sort[i]].freq;
		 b=total-a;
	       //	printf("\na=%d,b=%d,b-1=%d",a,b,b-a);
			if(diff>abs(b-a))
			{
				diff=b-a;
				index=i;
			   //	printf("in loop:differnece:%d",diff);
			}

		}

	 //      printf("\nindex:%d",index);
	//printf("\ndifference:%d",diff);
	       for(i=start;i<=index;i++)
	       {

		   symbol[sort[i]].codeword[symbol[sort[i]].codelength]=0;
		   symbol[sort[i]].codelength++;
	     //	   printf("\nfirst length:%d\t%d\n",symbol[sort[i]].codeword[symbol[sort[i]].codelength-1],symbol[sort[i]].codelength);

	       }
	       for(i=index+1;i<=end;i++)
	       {

		   symbol[sort[i]].codeword[symbol[sort[i]].codelength]=1;
		   symbol[sort[i]].codelength++;
	       //	    printf("\nlength:%d\t%d\n",symbol[sort[i]].codeword[symbol[sort[i]].codelength-1],symbol[sort[i]].codelength);

	       }
	      table(start,index);
	       table(index+1,end);

	}



}

void print_table()
{
	 int temp=0;
	for(int i=0;i<noofsymbol;i++)
	{
		printf("\n %c\t %d\t",symbol[sort[i]].c,symbol[sort[i]].freq);

		 temp=0;
		while(temp<symbol[sort[i]].codelength)
		{

	     printf("%d\t",symbol[sort[i]].codeword[temp]);
		temp++;
		}
	}



}