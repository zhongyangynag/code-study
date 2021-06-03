#include<stdio.h>
#include<string.h>

int main()
{
	char str[128];
	int i,j,len;
	int jiange;
    char strnew[128];
    
    printf("Input a string:");
    gets(str);
    for(i=0,j=0;str[i]!='\0';i++)
    {
    	if(str[i]!=' ')
    	{
    		strnew[j]=str[i];
    		j++;
		}
	}
	strnew[j]='\0';        //这句话不能漏 
	
	printf("Input jiange:");
	scanf("%d",&jiange);
	printf("Output:\nThe string of deleted space:");
	printf("%s",strnew);
	
	len=strlen(strnew);
	printf("\nThe result is:");
	for(i=0;i<jiange;i++)          //次数 
	{
		for(j=i;j<len;j+=jiange)
		{
			printf("%c",strnew[j]);
		}
		printf(" ");
	}
	printf("\n");
} 
