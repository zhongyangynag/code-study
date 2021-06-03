#include<stdio.h>

int main()
{
	double a[10];
	int i;
	double sum=0;
	
	printf("Input:\n");
	for(i=0;i<10;i++)
	{
		scanf("%lf",&a[i]);
	}
	printf("Output:\n");
	for(i=0;i<10;i++)
	{
		sum+=a[i];
	}
	printf("average=%.2lf",sum/10);
}
