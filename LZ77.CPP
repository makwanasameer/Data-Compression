/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3
*/

#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<string.h>
void main()
{

int size,lb,sb;
char *s_b;
char *l_b;
char *o_p;
char *i_p;
char *temp;
clrscr();
printf("\nEnter the size of dictonary:");
scanf("%d",&size);

s_b=(char *)calloc(10,1);
l_b=(char *)calloc(10,1);
o_p=(char *)calloc(50,1);
i_p=(char *)calloc(50,1);
temp=(char *)malloc(1);
if(size%2==0)
{
	lb=sb=size/2;

}
else
{
	lb=size/2;
	sb=(size/2)+1;
	printf("size of buffer:%d",sb);


}

printf("\nEnter the  input: ");
scanf("%s",i_p);
char c,s,l=0,index;
char *c1;
int j;
c1=(char *)malloc(1);
*temp='\0';
*o_p='\0';
//while(*i_p!='\0')
//{
strncpy(l_b,i_p,lb);
l_b[lb]='\0';
strcpy(s_b,"\0");
printf("before lookahead:%s search:%s\n",l_b,s_b);
getch();
while(*i_p!='\0')
{
l=0;
c=l_b[l];
j=0;
index=0;
	while(j<strlen(s_b))
	{
		for(int i=j;i<strlen(s_b);i++)
		{

			s=s_b[i];
			//printf("match with %c %c",c,s);
			if(c==s)
			{
			     //	printf("match found\n");
				if(l==0)
					{index=j;}
				l++;
				c=l_b[l];

			}
			else
			{

				break;
			}

		}
		if(l>0)
		{
			break;
		}
	j++;
	}
if(l==0)
{
	//printf("no match\t");
	strcat(o_p,"<0,0,");
	c1[0]=c;
	c1[1]='\0';

	strcat(o_p,c1);
	strcat(o_p,">");
	//printf("%s\n",o_p);
       //	printf("before lookahead:%s search:%s\n",l_b,s_b);
//getch();

	getch();


}
else
{
       //	printf("match\t");

	c1[0]=index+1+48;
	c1[1]=l+48;
	c1[2]=l_b[l];
	c1[3]='\0';
	strcat(o_p,c1);
	//printf("%s\n",c1);
  //	printf("before lookahead:%s search:%s\n",l_b,s_b);
//getch();

	getch();

}
strncpy(temp,l_b,l+1);
temp[l+1]='\0';
//while(l>0)
//{
i_p+=l+1;
//l--;
//}
//i_p++;
//printf("\n l is %d now input %s",l,i_p);
strncpy(l_b,i_p,lb);
l_b[lb]='\0';
if(strlen(s_b)+l+1>sb)
{
	//printf("size more\n");
	//
getch();
	s_b=s_b+l+1;
}
strcat(s_b,temp);


printf("lookahed: %s \tsearch:%s\t output:%s\n",l_b,s_b,o_p);


getch();



}

getch();

*s_b='\0';
*l_b='\0';
printf("\n\n decoding..\n");



}