#include<stdio.h>

int main()
{
	int n;
	int a[30];
	int i;
	
	printf("input a data(3--20):");
	scanf("%d",&n);
	a[0]=0;
	a[1]=1;
	a[2]=1;
	for(i=3;i<=n;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	printf("Output:\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t",a[i]);
	}
	
}
