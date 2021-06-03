#include<stdio.h>

int main()
{
	double x;
	int year;
	int i;
	float chanzhi;
	
	chanzhi=5000;
	year=2006;
	printf("Please input x:");	
	scanf("%lf",&x);
	
	while(chanzhi<10000)
	{
		i++;
		chanzhi=chanzhi*(100+x)/100;
	}
	
	printf("Output:\n");
	printf("year = %d nian, chanzhi = %.2lf\n",year+i,chanzhi);
	
} 
