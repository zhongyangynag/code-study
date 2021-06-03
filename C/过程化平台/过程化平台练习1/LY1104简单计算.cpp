#include<stdio.h>

int main()
{
	int a,b;
	float x,y;
	float ans;
	
	printf("Input: ");
	scanf("%d %d %f %f",&a,&b,&x,&y);
	ans=(double)(a+b)/2+(int)x%(int)y;
	
	printf("Output:\n");
	printf("The ans is %f\n",ans);
} 
