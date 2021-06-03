#include<stdio.h>

int main()
{
	float profit,salary=0;
	
	printf("Input profit: ");
	scanf("%f",&profit);
	
	if(profit<=1000)
		salary=500;
		
	else if(profit>1000&&profit<=2000)
		salary=500+profit*0.1;
		
	else if(profit>2000&&profit<=5000)
		salary=500+profit*0.15;
		
	else if(profit>5000&&profit<=10000)
		salary=500+profit*0.2;
		
	else if(profit>1000)
		salary=500+profit*0.25;
		
	printf("Output:\n");
	printf("salary=%.2f\n",salary);
}
