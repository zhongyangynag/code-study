#include<stdio.h>
int main()
{
	int a[5];
	int temp;
	int i,j;
	
	for(i=0;i<5;i++)
	{
		printf("Input a[%d]:",i);
		scanf("%d",&a[i]);
	}
	
	for(j=5;j>1;j--)                                     //ȷ���Լ������������ֵ 
	{
	    for(i=1;i<j;i++)                                //���⼸��������,�����ֵ�ƶ����Ҷ� 
	    {
		    if(a[i]<a[i-1])
	     	{
		        temp=a[i];
		        a[i]=a[i-1];
		        a[i-1]=temp;
     	    }
	    }
    }
	
	printf("\nresult is:\n");
	for(i=0;i<5;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
