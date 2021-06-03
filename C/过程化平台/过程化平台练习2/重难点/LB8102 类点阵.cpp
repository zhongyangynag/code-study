//此题关键在于char str[12] 
#include<stdio.h>

int main()
{
	int n;
	FILE *fp;
	char str[12];
	int i;
	
	printf("Input n:");
	scanf("%d",&n);
	
	fp=fopen("lb8102.txt","r+");
	
	for(i=0;i<8*n;i++)
	{
		fgets(str,11,fp);
	}
	
	printf("Output:\n");
	for(i=0;i<8;i++)
	{
		fgets(str,11,fp);
		printf("%s",str);
	}
	printf("\n");
}
