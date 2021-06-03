#include<stdio.h>

int main()
{
	char str[100];
	int i;
	
	printf("please input str:");
	gets(str);
	
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==' '||str[i]=='\t')
		{
			str[i+1]-=32;
		}
	}
	str[0]-=32;
	
	printf("Output:\n");
	puts(str);
	printf("\n");
}
