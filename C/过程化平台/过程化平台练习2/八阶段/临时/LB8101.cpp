#include<stdio.h>

int main()
{
	int n;
	FILE *fp;
	int i;
	int a[50];
	int sum=0;
	
	printf("Input n:");
	scanf("%d",&n);
	printf("Output:\n");
	
	fp=fopen("lb8101.txt","r");
	for(i=0;i<50;i++)
	{
		fscanf(fp,"%d",&a[i]);
	}
	fclose(fp);
	
	for(i=49;i>49-n;i--)
	{
		sum+=a[i];
	}
	
	printf("%d\n",sum);
}
