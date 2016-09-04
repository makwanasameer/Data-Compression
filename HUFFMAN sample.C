#include<stdio.h>
#include<string.h>
#include<conio.h>

struct Tree
{      int freq;
       char c;
       struct Tree *left;
       struct Tree *right;
};

struct Tree ware[256];
int noof=0,d=1;

char *ans[128];
char buf[1024];

typedef struct Tree *node;
node mk[255],*q=mk-1;

node getnew(int freq,char c,node a,node b)
{
node n=ware + noof++;

if(freq)
{
  n->c=c;
  n->freq=freq;
}
else
{
  n->left=a;
  n->right=b;
  n->freq=a->freq + b->freq;
}
  return n;
}

void in(node n)
{
  int j;
  int i=d++;

  while((j=i/2))
  {
    if(q[j]->freq<=n->freq)
    {
      break;
    }
      q[i]=q[j];
      i=j;
    }
      q[i]=n;
}

node rm()
{
    int i=1,l;
    node n=q[1];
    if(q<2)
    {
	return 0;
    }
	d--;
    while ((l=i*2)<d)
    {
       if(l+1<d && q[l+1]->freq<q[l]->freq)
       {
	  l++;
       }
	  q[i]=q[l];
	  i=l;
	}
	q[i]=q[d];
	return n;
}

void makecode(node n,char *s,int len)
{
	static char *out = buf;
	if(n->c)
	{
	  s[len] = 0;
	  strcpy(out, s);
	  ans[n->c] = out;
	  out=out+len+1;
	  return;
	}

	s[len] = '0';
	makecode(n->left,s,len+1);
	s[len] = '1';
	makecode(n->right,s,len+1);
}

void calculate(char *s)
{
	int i,freq[128]={0};
	char c[16];

	while(*s!=NULL)
	{
	  freq[(int)*s++]++;
	}

	for(i=0;i<128;i++)
	{
	  if(freq[i] !=0)
	  {
	    in(getnew(freq[i],i,0,0));
	  }
	}
	while(d>2)
	{
	    in(getnew(0,0,rm(),rm()));
	}
	makecode(q[1],c,0);
}

void main()
{
	int i;
	char *str,buf[1024];
       // FILE *fp;
	clrscr();
     /*	fp=fopen("D:\\Borlandc\\BIN\\tmp.txt",'rb');
	  while(!feof(fp))
	{
	  str[f]=fgetc(fp);
	  f++;
	}*/
	printf("Enter String For Find Huffman Code of it : ");
	gets(str);

	calculate(str);
	printf("\nHuffman Code of the String");
	for (i=0;i<128;i++)
	{
		if(ans[i]!=0)
		{
			printf("\n%c : %s",i,ans[i]);
		}
	}
	getch();
}