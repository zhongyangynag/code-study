#include <stdio.h>
void inv(int *x,int n);

int main()
{
 	int i,arr[5],*p=arr; 
 	printf("The original array:\n");
 	
 	for(i=0;i<5;i++,p++)
   		scanf("%d",p);
   		
 	printf("Output:\n");
	/******start******/
	p=arr;                              //����Ҫ���½�ָ��ָ�����鿪ͷ����Ȼpָ������������һ��Ԫ�� 
	/******end******/
 	inv(p,5); 
 	printf("The array has been inverted:\n");
 	
 	for(p=arr;p<arr+5;p++)
   		printf("%d ",*p);
   		
 	printf("\n");
 	return 0;
}

void inv(int *x,int n)
{
	/******start******/
	int i, tmp;
	for (i = 0; i < n/2; i++)
	{
		tmp = *(x+i);
		*(x+i) = *(x+n-i-1);
		*(x+n-i-1) = tmp;
	}

	/******end******/
}
