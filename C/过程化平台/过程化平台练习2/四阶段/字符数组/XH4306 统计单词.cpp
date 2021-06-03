#include<stdio.h>

int main()
{
	int count=0;
	int i;
	char str[128];
	char ch;
	
	printf("please input str:");
	gets(str);
	printf("Output:\n");
	
	for(i=0;str[i]!='\0';i++)
	{	
		ch=str[i];
		count++;
		if( (str[i]==' '||str[i]=='.')&&count!=0 )
		{
			printf("%d ",count-1);
			count=0;
		}
	}
	
	printf("\n");
	
}
