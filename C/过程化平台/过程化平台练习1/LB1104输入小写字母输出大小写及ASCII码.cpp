#include<stdio.h>

int main()
{
	char a;
	printf("Input a lowercase letter:");
	scanf("%c",&a);
	printf("Output:\n");
	printf("%c(%d)\n",a,a);
	printf("%c(%d)\n",a-32,a-32);
}
