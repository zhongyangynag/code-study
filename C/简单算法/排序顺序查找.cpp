#include<stdio.h>
void input(int a[10]);
void sort(int a[10]);
void output(int a[10]);
int search(int a[10]); 

int main()
{
	int a[10];
	int temp;
	int i,j;
	int res;
	
	input(a);
	sort(a);
	output(a);
	
	res=search(a);
	if(res==-1)
	    printf("û�в��ҵ���\n");
	else
	    printf("�ҵ��ˣ�"); 
} 

void input(int a[10])
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("Input a[%d]:",i);
		scanf("%d",&a[i]);
	}
}

void sort(int a[10])
{
	int i,j;
	int temp;
	
	for(j=10;j>1;j--)                                     
	{
	    for(i=1;i<j;i++)                               
	    {
		    if(a[i]<a[i-1])
	     	{
		        temp=a[i];
		        a[i]=a[i-1];
		        a[i-1]=temp;
     	    }
	    }
    }
}

void output(int a[10])
{
	int i;
	printf("\nresult is:\n");
	for(i=0;i<10;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}

int search(int a[10])
{
	int num;
	int i; 
	
	printf("\nInput a num:");
	scanf("%d",&num);
	
    for(i=0;i<10;i++)
    {
    	if(num==a[i])
        {
        	return 1;
        	break;
		}
	}
	return -1;
}

