#include<stdio.h>
#include<string.h>

int main()
{
	char str1[128];
	char str2[128];
	char str3[128];
	int count=0;
	int i,j;
	int flag=0;
	
	printf("please input str:");
	gets(str1);
	printf("Output:\n");
	
	for(i=0,j=0;str1[i]!='\0';i++)
	{
		if(str1[i]!=' '||str1[i]!='.')
		{
			str2[j]=str1[i];
			j++;
			flag=1;
			count++;
		}
		if((str1[i]!=' '||str1[i]!='.')&&flag==1)
		{
			strcpy(str3,str2);
			flag=0;
		}
		if((str1[i]==' '||str1[i]=='.')&&flag==0)
		{
			strcat(str3,"\0");
			printf("%d ",count-1);
			strcpy(str2,"");
			count=0;
		}
	}
	
	
}
