#include <stdio.h>

int main()
{
	int a[5];
	int *p; 
	int i;
	
	printf("please enter 5 integer numbers:");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("Output:\n");
	
	for(p=a;p<a+5;p++)
	{
		printf("%d ",*p);
	}
	
	printf("\n");
	return 0;
}
