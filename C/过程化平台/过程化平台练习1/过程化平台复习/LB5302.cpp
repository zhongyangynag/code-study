#include<stdio.h>
#include<string.h>
void prencode(char strnew[128], int jiange);

int main()
{
	char str[128];
	char strnew[128];
	int i,j;
	int jiange;
	
	printf("Input a string:");
	gets(str);
	printf("Input jiange:");
	scanf("%d",&jiange);
	
	for(i=0,j=0;str[i]!='\0';i++)
	{
		if(str[i]!=' ')
		{
			strnew[j]=str[i];
			j++;
		}
	}
	strnew[j]='\0';
	
	printf("Output:\nThe string of deleted space:%s",strnew);
	printf("\nThe result is:");
	prencode(strnew,jiange);
} 

void prencode(char strnew[128], int jiange)
{
	int len;
	len=strlen(strnew);
	int i,j;
	
	for(i=0;i<jiange;i++)
	{
		for(j=i;j<len;j+=jiange)
		{
			printf("%c",strnew[j]);
		}
		printf(" ");
	}
	printf("\n");
}
