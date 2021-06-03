#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	int n,i;
	int sum=0;
	int a[50];
	
	if((fp=fopen("lb8101.txt","r"))==NULL)
	{
		printf("Open Error!\n");
		exit(0);
	}
	
	printf("Input n:");
	scanf("%d",&n);
	
	for(i=0;i<50;i++)
	{
		fscanf(fp,"%d",&a[i]);
	}
	
	for(i=50-n;i<50;i++)
	{
		sum+=a[i];
	}
	
	fclose(fp);
	
	printf("Output:\n");
	printf("%d\n",sum);
}

