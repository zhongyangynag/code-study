#include<stdio.h>

int main()
{
	int n;
	int i;
	FILE *fp;
	char str[12];
	
	printf("Input n:");
	scanf("%d",&n);
	printf("Output:\n");
	
	fp=fopen("lb8102.txt","r");
	for(i=0;i<n*8;i++)
	{
		fgets(str,11,fp);
	}
	
	for(i=0;i<8;i++)
	{
		fgets(str,11,fp);
		printf("%s",str);
	}
	printf("\n");
	fclose(fp);
}
