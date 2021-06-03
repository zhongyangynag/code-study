#include<stdio.h>

int main()
{
	double a[20];
	int n;
	int i;
	
	a[0]=0;
	a[1]=1;
	a[2]=2;
	printf("Input n (13>=n>=2):");
	scanf("%d",&n);
	for(i=3;i<=n;i++)
	{
		a[i]=2*a[i-1]+a[i-2]*a[i-3];
	}
	printf("Output:\n");
	printf("f(%d)=%.0lf\n",n,a[n]);
} 
