#include<stdio.h>

int long f(int n)
{
	if(n==1)
		return 2;
	else
		return f(n-1)*3+2;           //ººÅµËşÊÇf(n)=2^n-1 
}

int main()
{	int n;
	printf("Please input n:");
	scanf("%d",&n);
	
	if(n<=35&&n>=1)
	{
		printf("Output:\n%ld\n",f(n));
		return 0;
	}
	else
		printf("Output:\nInput error!\n");
		return 0;
}
