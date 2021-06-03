#include<stdio.h>
#include<string.h>

void clearspace(char str[128],char strnew[128]);
void prencode(char strnew[128],int jiange);

int main()
{
	char str[128];
	char strnew[128];
	int jiange;
	
	printf("Input a string:");
	gets(str);
	printf("Input jiange:");
	scanf("%d",&jiange);
	clearspace(str,strnew);
	printf("Output:\n");
	printf("The string of deleted space:");
	puts(strnew);
	prencode(strnew,jiange);
} 

void clearspace(char str[128],char strnew[128])
{
	int i,j;
	
	for(i=0,j=0;str[i]!='\0';i++)
	{
		if(str[i]!=' ')
		{
			strnew[j]=str[i];
			j++;
		}
	}
	strnew[j]='\0';
}
void prencode(char strnew[128],int jiange)
{
	int i,j;
	int length;
	
	length=strlen(strnew);
	printf("The result is:");
	for(i=0;i<jiange;i++)
	{
		for(j=i;j<length;j+=jiange)
		{
			printf("%c",strnew[j]);
		}
		printf(" ");
	}
	printf("\n");	
}
