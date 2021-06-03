#include<stdio.h>

int main()
{
	FILE *fp;
	int start,end,i;
	int a[50];
	int sum=0;
	
	printf("Input start and end:");
	scanf("%d%d",&start,&end);
	
	fp = fopen("lb8104.dat","rb");
	for(i=0;i<50;i++)
	{
		fread(&a[i],sizeof(int),1,fp);
	}
	
	for(i=start-1;i<=end-1;i++)
	{
		sum+=a[i];
	}
	printf("Output:\n");
	printf("%d\n",sum);
}

