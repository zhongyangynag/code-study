#include<stdio.h>
#include<math.h>

int main()
{
	double a,b,c;
	double area;
	double p;
	printf("please input triange sides:");
	scanf("%lf,%lf,%lf",&a,&b,&c);
	printf("Output:\n");
	if((a+b<=c)||(a+c<=b)||(b+c<=a))
	{
		printf("data error\n");
	}
	else
	{
		p=(a+b+c)/2;
		area=sqrt(p*(p-a)*(p-b)*(p-c));
		printf("area=%.2lf\n",area);
	}
}
