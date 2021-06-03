#include<stdio.h>

int main()
{
	char str[128];
	int i,j;
	char strn[128];
	
	printf("Input:\nPlease input string:\n");
	gets(str);
	
	for(i=0,j=0;str[i]!='\0';i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			strn[j]=str[i];
			j++; 
		}
	}
	strn[j]='\0';
	
	printf("\nOutput:\nThe Digit Number is:%d\n",j);
	printf("\nThe Digit Number is following:");
	puts(strn);
}
