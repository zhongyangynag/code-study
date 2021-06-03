#include<stdio.h>

int main()
{
	int a[101]; 
	int n;
	int i,j;
	int temp;
	
	printf("please input n:");
	scanf("%d",&n);
	printf("please input a[]:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Output:\n");
	
	for(j=n;j>1;j--)
	{
		for(i=1;i<j;i++)
		{
			if(a[i]<a[i-1])
	     	{
		       	temp=a[i];
		        a[i]=a[i-1];
		        a[i-1]=temp;
     	    }
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");	
}
