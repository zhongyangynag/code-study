#include<stdio.h>
#define MAX 5
int main()
{
	int s[MAX];
	int i;
	int temp;
	
	for(i=0;i<MAX;i++)
	{
		printf("Input a number:");
		scanf("%d",&s[i]);
	}
	
	for(i=0;i<MAX;i++)
	{
		printf("�������Ϊ��%-4d\n",s[i]);
	}
	
    for(i=0;i<MAX/2;i++)
    {
		temp=s[i];
		s[i]=s[5-i-1];
		s[5-i-1]=temp;
    }
	
	for(i=0;i<MAX;i++)
	{
		printf("\n�����Ľ����%-4d",s[i]);
	}
}

