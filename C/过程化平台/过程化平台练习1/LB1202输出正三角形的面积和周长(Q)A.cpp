#include<stdio.h>
#include<math.h>

int main()
{
	int a;
	double area,circle;
	printf("Input a side of triangle: ");
	scanf("%d",&a);
	
	area=sqrt((1.5*a)*(0.5*a)*(0.5*a)*(0.5*a));
	circle=3*a;
	
	printf("Output:\n"); 
	printf("The area of triangle is %.2lf, the circle of triangle is %.0lf.\n",area,circle);
	
}
