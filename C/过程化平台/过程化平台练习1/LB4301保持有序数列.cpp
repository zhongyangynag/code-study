#include<stdio.h>

int main()
{
	int a[100];
	int n;
	int x;
	int i,j;
	int temp;
	
	printf("Input:\n");
	scanf("%d %d",&n,&x);
	while(n!=0&&x!=0)
	{
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);	
	}
	a[n]=x;
	for(j=n+1;j>1;j--)
	{
		for(i=1;i<j;i++)
		{
			if(a[i]<a[i-1])
			{
				temp=a[i-1];
				a[i-1]=a[i];
				a[i]=temp;
			}
		}
	}
	printf("Output:");
	for(i=0;i<=n;i++)
	{
		printf(" %d",a[i]);	
	}
	printf("\n");
	scanf("%d %d",&n,&x);
    }
	
}
