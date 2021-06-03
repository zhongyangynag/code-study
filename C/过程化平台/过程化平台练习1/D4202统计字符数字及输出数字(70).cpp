#include<stdio.h>

int main()
{
	char str[128];
	char strnew[128];
	int i,j;
	int flag;
	
	printf("Input:\n");
	printf("Please input string:\n");
	gets(str);
	printf("\nOutput:\n");
	
	for(i=0,j=0;str[i]!='\0';i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			strnew[j]=str[i];
			j++;
			flag=1;
		}
	}
	
	printf("The Digit Number is:%d\n\n",j);
	printf("The Digit Number is following:");
	if(flag==1)
	{
		puts(strnew);
    }
    else
    {
    	printf("\n");
	}
}
