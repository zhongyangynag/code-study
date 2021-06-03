#include<stdio.h>
#include<string.h>

void sort(char *name[],int n);
void print(char *name[],int n);

int main()
{
	char a[31],b[31],c[31],d[31],e[31];
	char *str[5];
	
	printf("Please input 5 strings:");
	gets(a);
	gets(b);
	gets(c);
	gets(d);
	gets(e);
	
	str[0]=a;str[1]=b;str[2]=c;str[3]=d;str[4]=e;
		
	printf("Output:\n");
	printf("After the strings are sorted the result:\n");
	
	sort(str,5);
	print(str,5);
}

void sort(char *name[],int n)
{
	int i,j;
	char *temp=NULL;
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if( strcmp(name[i],name[j])>0 )
			{
				temp=name[i];
				name[i]=name[j];
				name[j]=temp;
			}
		}
	}
}

void print(char *name[],int n)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		printf("%s\n",name[i]);
	}
}
