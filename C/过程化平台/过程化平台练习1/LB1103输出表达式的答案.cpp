#include<stdio.h>

int main()
{
	int z;
	double x,y;
	double a;
	printf("please input x,y,z:");
	scanf("%lf,%lf,%d",&x,&y,&z);
	a=x+z%3*(int)(x+y)%2/4;
	printf("Output:%lf\n",a);
}
