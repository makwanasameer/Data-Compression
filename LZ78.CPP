/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct word
{
	char *w;
	struct word *l;
}*st=NULL;
void fr()
{
	struct word *t=st,*t1;
	while(t!=NULL)
	{
		t1=t->l;
		free(t);
		t=t1;
	}
}
void ins_end(struct word *t)
{
	if(st==NULL)
	{
		st=t;
		st->l=NULL;
	}
	else
	{
		struct word *t1=st;
		while(t1->l!=NULL)
		t1=t1->l;
		t1->l=t;
		t->l=NULL;
	}
}
int main()
{
	char buf[1000],temp[50],c;
	int i,j,k,l,l1,count,ind;
	struct word *t,*t2;

	clrscr();
	printf("Enter text:\n");
	gets(buf);
//	scanf("%s",buf);

	k=strlen(buf);
	for(i=0;i<k;i++)
	{
		t=st;
		l1=0;
		count=0;
		ind=0;
		while(t!=NULL)
		{
			count++;
			l=strlen(t->w);
			for(j=0;(j<l)&&((i+j+1)<k);j++)
			{
				if(t->w[j]!=buf[i+j])
				break;
			}
			if(j==l)
			{
				if(j>l1)
				{
					l1=j;
					ind=count;
				}
			}
			t=t->l;
		}
		printf("< %d , %c >\n",ind,buf[i+l1]);

		t2=(struct word *)malloc(sizeof(struct word));
		t2->w=(char *)malloc((l1+2)*sizeof(char));

		c=buf[i+l1+1];
		buf[i+l1+1]='\0';
		strcpy(t2->w,&buf[i]);
		buf[i+l1+1]=c;

		ins_end(t2);
		i+=l1;
	}
	printf("\n\nDictionary:\n");
	t=st;
	i=1;
	while(t!=NULL)
	{
		printf("%d : %s\n",i,t->w);
		i++;
		t=t->l;
	}
	getch();
	fr();
	return 0;
}