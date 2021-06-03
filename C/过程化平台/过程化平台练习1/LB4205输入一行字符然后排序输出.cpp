#include<stdio.h>
#include<string.h>

int main()
{
	char str[128];
	int i,j;
	char temp;
	int len;
	
	printf("input the string: \n");
	gets(str);
	len=strlen(str);
	
	for(i=len;i>1;i--)
	{
		for(j=1;j<i;j++)
		{
			if(str[j]<str[j-1])
			{
				temp=str[j-1];
				str[j-1]=str[j];
				str[j]=temp;
			}
		}
	}
	printf("Output:%s\n",str);	
	
}
