#include<stdio.h>
int main()
{
	int a[10];
	int i,j,k;
	int temp;
	
	for(i=0;i<10;i++)
	{
		printf("�����%d����:",i);
		scanf("%d",&a[i]);
	}
	
	printf("\n�������Ϊ:\n");
	for(i=0;i<10;i++)
	{
		printf("%-4d",a[i]);
	}
	
	for(i=0;i<10;i++)
	{
		k=i;
		for(j=i+1;j<10;j++)
		{
			if(a[j]<a[k])
			{
			   k=j;
		    }
		}
		if(k!=i)                        //�Ż������Լ����Լ������� 
      	{  
		     temp=a[k];
		     a[k]=a[i];
		     a[i]=temp;
	    }
	}
	
	printf("\nѡ�������:\n");
	for(i=0;i<10;i++)
	{
		printf("%-4d",a[i]);
	}
	
}
