#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int num,i,e;
    srand(time(NULL));
    
    for(i=1;;i++)
    {
	   printf("����һ��������������ʼ����") ;
	   scanf("%d",&e); 
	   if(e==0)
	   {
		  printf("�������");
		  break; 
	   } 
	   else
	   {
	   	  num=rand()%82+1;
	      printf("\n��ϲ%d������!\n\n�����Ҫ�˳�����������0\n\n**********************************\n\n",num);
	   }    
	}	
}
