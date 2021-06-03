#include <stdio.h>
void inv(int *x,int n);
int main()
{    
	int i,a[5];
	printf("The original array:\n");
	 
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
		
	printf("Output:\n");
	inv(a,5);
	printf("The array has been inverted:\n");
	
	for(i=0;i<5;i++)
		printf("%d ",a[i]);
		
	printf("\n");
	return 0;
}

void inv(int *x,int n)                   //形参x是指针变量       
{
	/******start******/
	int temp;
	int i;
	
	for(i=0;i<n/2;i++)
	{
		temp=x[i];
		x[i]=x[n-i-1];
		x[n-i-1]=temp;
	}
	/******end******/
}
