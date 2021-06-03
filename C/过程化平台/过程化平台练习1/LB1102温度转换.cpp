#include<stdio.h>

int main()
{
	double F,C;
	printf("Input the degree:");
	scanf("%lf",&F);
	C=5*(F-32)/9;
	printf("Output:\n");
	printf("F(%.2lf)=C(%.2lf)\n",F,C);
} 
