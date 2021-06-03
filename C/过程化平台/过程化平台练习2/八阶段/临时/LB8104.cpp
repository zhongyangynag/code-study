#include<stdio.h>

int main()
{
	FILE *fp;
	int start,end;
	int a[50];
	int i;
	int sum=0;
	
	fp=fopen("lb8104.dat","rb");
	for(i=0;i<50;i++)
	{
		fread(&a[i],sizeof(int),1,fp);
	}
	fclose(fp);
	
	printf("Input start and end:");
	scanf("%d%d",&start,&end);
	printf("Output:\n");
	
	for(i=start-1;i<=end-1;i++)
	{
		sum+=a[i];
	}
	
	printf("%d\n",sum);
}
