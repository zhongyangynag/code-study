#include<stdio.h>
int main()
{
	long int a,b,c;
	printf("Please enter a optional fraction (a/b):");
	scanf("%ld/%ld",&a,&b);
	printf("Output:\n");
	if(a<=0 || a>=100 || b<=0 ||b>=100)
	{
		printf("Input error!\n");
		return 0;
	}
	printf("It can be decomposed to :");
	while(1)
	{
		if(b%a)
			c=b/a+1;
		else
		{
			c=b/a;
			a=1; 
		}
		if(a==1)
		{
			printf("1/%ld\n",c);
			break;
		}
		else
			printf("1/%ld + ",c);
			
		a=a*c-b;
		b=b*c;
		/*if(a==3)
		{
			printf("1/%ld + 1/%ld\n",b/2,b);
			break;
		}*/
	}
	return 0;
}







