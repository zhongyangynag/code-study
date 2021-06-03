#include<stdio.h>

int main()
{
	FILE *fp;
	int n,i;
	int a[50];
	int sum=0;
	
	printf("Input n:");
	scanf("%d",&n);
	
	fp = fopen ("lb8101.txt","r");
	for(i=0;i<50;i++)
	{
		fscanf(fp,"%d",&a[i]);
	}
	fclose(fp);
	
	for(i=49;i>49-n;i--)
	{
		sum+=a[i];
	}
	printf("Output:\n%d\n",sum);
}
