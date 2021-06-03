#include<stdio.h>
#include<string.h>

int main()
{
	char str1[128];
	char str2[128];
	int i,j;
	int len;
	
	printf("Input a string: ");
	gets(str1);
	len=strlen(str1);
	
	for(i=len-1,j=0;i>=0;i--,j++)
	{
		str2[j]=str1[i];
	}
	str2[j]='\0';
	
	printf("Output: %s\n",str2);
} 
