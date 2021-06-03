#include<stdio.h>
#include<math.h>

int main()
{
	int a,b,c;
	int max;
	printf("Input 3 numbers: ");
	scanf("%d,%d,%d",&a,&b,&c);
	printf("Output:\n");
	
	if(abs(a)>abs(b))
	{
		max=a;
	}
	else
	{
		max=b;
	}
	
	if(abs(max)<abs(c))
	{
		max=c;
	}

	printf("The number with maximum absolute value is %d.",max);
}
