#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<string.h>
char in[100];
int n=0,l=0,j,m=0,d=0;
struct field
{
	int index;
	char entry[10];
}initial[6],output[50];
void main()
{
	clrscr();
	cout<<"enter string:\n";
	fflush(stdin);
	scanf("%s",in);
	cout<<"\nenter no. of entries in initial dictionary";
	cin>>n;
	cout<<"\n enter \nindex    entry\n";
	for(int i=0;i<n;i++)
	{
	      cin>>initial[i].index>>initial[i].entry;
	}
	l=strlen(in);
	for(i=0;i<n;i++)
	{
		output[i]=initial[i];
	}
	for(i=0;i<n;i++)
	{
		cout<<output[i].index<<output[i].entry<<"\n";
	}
	for(i=0;i<l;i++)
	{
	       for(j=0;j<n;j++)
	       {
			if(output[j].entry[m]==in[i])
			{
				d++;
				cout<<output[j].index;
				m++;
				i++;
			}
			else
			{
				if(d==1)
				{
					output[n].index=n+1;
					strcpy(output[n].entry,in[i-1]);
					strcat(output[n].entry,in[i]);
				}
			}

	       }
	}
	getch();
}
