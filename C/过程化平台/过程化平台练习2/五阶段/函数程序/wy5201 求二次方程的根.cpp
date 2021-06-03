#include <stdio.h>
#include <math.h>

/******start******/
void resolve(int a,int b,int c);
/******end******/

int main()
{
	double a, b, c=0;
	printf("input a b c: ");
	scanf("%lf%lf%lf", &a, &b, &c);

	resolve(a, b, c);

	return 0;
}

/******start******/
void resolve(int a,int b,int c)
{
	double deta;
	double res1,res2;
	
	deta=b*b-4*a*c;
	
	printf("output:\n");
	if(deta<0)
	{
		printf("无实数根\n");
	}
	else if(deta==0)
	{
		res1=res2=( (-b)/(2*a) );
		printf("%.2lf\n",res1);
	}
	else
	{
		res1=( (-b)+sqrt(deta) )/(2*a);
		res2=( (-b)-sqrt(deta) )/(2*a);
		printf("%.2lf %.2lf",res1,res2);
	}
}
/******end******/

