#include <stdio.h>
#include <math.h>

/******start******/
void resolve(double a,double b,double c);
/******end******/

int main()
{
	double a, b, c=0;
	printf("input a b c: ");
	scanf("%lf%lf%lf", &a, &b, &c);

	printf("output:\n");
	resolve(a, b, c);

	return 0;
}

/******start******/
void resolve(double a,double b,double c)
{
	double p;
	double x1,x2;
	p=b*b-4*a*c;
	if(p>0)
	{
		x1=((-b)+sqrt(p))/(2*a);
		x2=((-b)-sqrt(p))/(2*a);
		printf("%.2lf %.2lf\n",x1,x2);
	}
	else if(p==0)
	{
		x1=((-b)+sqrt(p))/(2*a);
		printf("%.2lf\n",x1);
	}
	else
	{
		printf("无实数根\n");
	}
}
/******end******/


