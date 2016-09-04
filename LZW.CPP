/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3
*/

#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<string.h>

struct dict
{
   int index;
   char *entry;
   struct dict *next;
};
int index=1;
char *str;

void main()
{
   int i=0,n,match,j,len,flag,match_len,match_index,k,sym;
   char *string,ch,*match_string;
   struct dict *start=NULL,*new_d=NULL,*temp=NULL;
   clrscr();
   printf("\nEnter the string : ");
   gets(str);
   printf("\nNo of symbols : ");
   scanf("%d",&sym);
   printf("Enter the symbol in which are in the string : \n");
   n = strlen(str);
   string = (char *)malloc(n);
   for(j=0;j<sym;j++)
   {
      printf("%d : ",j);
      flushall();
      scanf("%c",&ch);
      if(start==NULL)
      {
	 string[0] = ch;
	 string[1] = '\0';
	 start = (struct dict*)malloc(sizeof(struct dict));
	 start->index = index;
	 index++;
	 start->entry = (char *)malloc(2);
	 strcpy(start->entry,string);
	 start->next = NULL;
      }
      else
      {
	 temp = start;
	 while(temp->next!=NULL)
	 {
	    temp = temp->next;
	 }
	 string[0] = ch;
	 string[1] = '\0';
	 new_d = (struct dict*)malloc(sizeof(struct dict));
	 new_d->index = index;
	 index++;
	 new_d->entry = (char *)malloc(2);
	 strcpy(new_d->entry,string);
	 new_d->next = NULL;
	 temp->next = new_d;
      }
   }
   temp = start;
   printf("\n LZW encoding \n");
   printf("\nIndex\tEntry\n");
   for(i=0;i<sym;i++)
   {
      printf(" %d \t %s\n",temp->index,temp->entry);
      temp = temp->next;
   }
   i = 0;
   while(i<n)
   {
      j = 0;
      temp = start;
      flag = 0;
      while(temp!=NULL)
      {
	 len = strlen(temp->entry);
	 k = i;
	 for(j=0;j<len;j++)
	 {
	    string[j] = str[k];
	    k++;
	 }
	 string[j] = '\0';
	 if(strcmp(string,temp->entry))
	 {
	    temp = temp->next;
	 }
	 else
	 {
	    if(flag==0)
	    {
	       match_len = len;
	       match_index = temp->index;
	       match_string = (char *)malloc(len);
	       strcpy(match_string,temp->entry);
	       flag = 1;
	    }
	    else
	    {
	       if(len>match_len)
	       {
		  match_len = len;
		  match_index = temp->index;
		  match_string = (char *)malloc(len);
		  strcpy(match_string,temp->entry);
	       }
	    }
	    temp = temp->next;
	 }
      }
      temp = start;
      while(temp->next!=NULL)
      {
	 temp = temp->next;
      }
      i = i+match_len;
      ch = str[i];
      printf(" %d \t %s%c \n",index,match_string,ch);
      new_d = (struct dict*)malloc(sizeof(struct dict));
      new_d->index = index;
      index++;
      match_string[match_len] = ch;
      match_string[match_len+1] = '\0';
      new_d->entry = (char *)malloc(match_len+1);
      strcpy(new_d->entry,match_string);
      new_d->next = NULL;
      temp->next = new_d;
   }
   getch();
}


