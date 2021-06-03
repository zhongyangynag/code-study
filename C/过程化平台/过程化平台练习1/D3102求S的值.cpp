#include<stdio.h>

int main()
{
	int n;
	double s,g;
	int i;
	
	s=0;
	g=1;
	printf("Input:\n");
	printf("Please input n:");
	scanf("%d",&n);
	printf("Output:\n");
	
    for(i=1;i<=n;i++)
    {
    		g=1*i*g;
    		s=1/g+s;
	}
	printf("S=1/1!+1/2!+...+1/%d!=%.16lf",n,s);
} 
