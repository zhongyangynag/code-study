//������������ڵ���������// 
#include<stdio.h>
int main()
{
	long a,b;
	long n,i;
	long count=0;
	long flag=0;
	
	printf("��С������������������Ϊ����Ҫ�����䣺");
	scanf("%ld%*c%ld",&a,&b);
	printf("�����������Ϊ[%ld,%ld]\n",a,b);

	for(n=a;n<=b;n++)  
	{
	   for(i=2;i<n;i++)
	   {
		  if(n%i==0)
		    break;
		  else if(i==n-1)
		    flag=1;    
	   }
	     
		  if(flag==1)
		  {
		     printf("%7ld",n);
		     count++;
		     flag=0;
		  if(count%10==0)
	         printf("\n"); 	
		  }
	         
    }
} 
