#include<stdio.h>
#include<string.h>

void revert(char str3[]);

int main()
{
	char str1[128];
	char str2[128];
	char str3[128];
	int i,j;
	int flag=0;
	
	printf("please input str:");
	gets(str1);
	printf("Output:\n");
	
	for(i=0,j=0;str1[i]!='\0';i++)
	{
		if(str1[i]!=' ')
		{
			str2[j]=str1[i];
			j++;
			flag=1;
		}
		if((str1[i]!=' ')&&flag==1)
		{
			strcpy(str3,str2);
			flag=0;
		}
		if((str1[i]==' ')&&flag==0)
		{
			revert(str3);
			puts(str3);
	
			
		}
	}
	
	

}

void revert(char str3[])
{
	int i;
	int n;

	n = strlen(str3);
	str3[n]='\0';
	for (i = 0;str3[i] != '\0'; i++)
	{
		str3[n - 1 - i]=str3[i];
	}
	
}
