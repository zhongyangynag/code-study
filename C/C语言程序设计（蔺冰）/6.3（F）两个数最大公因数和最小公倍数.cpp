#include<stdio.h>
int  main()
{
	int m,n,a,b;
	printf("Input m,n:");
	scanf("%d%*c%d",&m,&n);
	
	   
   for(b=1;;b++) 
       {
       	   if(b%m==0&&b%n==0)
       	   {                                       //����һ������ʡ�� 
			  printf("��С�������ǣ�%d",b); 
			  printf("\n���Լ���ǣ�%d",a=(m*n)/b);   //�ǵ��������������*��С������=������֮�� 
       	      break; 
           }   
	   }	   
}	 
