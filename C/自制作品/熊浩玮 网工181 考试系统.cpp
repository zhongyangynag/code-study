#include<stdio.h>
#include<windows.h>
void fun1();
void fun2();
void fun3(); 

int main()
{
	int start;
	int choice;
	int answer;
	int i;
	
	printf("��ӭ�������ò���ϵͳ!\n(���س�����)\n");
	getchar();
	printf("��׼��������׼�������밴1,δ׼����������0\n");
	printf("������:");
	scanf("%d",&start);
	
	if(start==0)
	    printf("\n��ӭ�´�ʹ��!\n");
	else
	{
	printf("\n���Ǳ����Ե���Ŀ,��˼�������:\n"); 
	printf("\n************************************************\n\n");
	printf("1�����*��ͼ��\n");
	printf("2��������������ڵ�����\n");
	printf("3��������������ˮ�ɻ���\n");
	printf("4���˳�\n"); 
	printf("\n************************************************\n\n");
	
    printf("�鿴���밴1,�˳��밴0:");
    scanf("%d",&answer);
    if(answer==0)
        printf("\n��ӭ�´�ʹ��!\n");
        
	else
	{
	for(i=1;;i++)
	{
	printf("\n������ѡ�����ѡ��:"); 
	scanf("%d",&choice);  
	
	if(choice==1)
	{
		int x;
		system("CLS");
		printf("��һ��𰸹���:\n");
		fun1();
		
		printf("\n\n�˳��밴0�����������밴1:"); 
		scanf("%d",&x);
		if(x==0)
		{
		    printf("��ӭ�´�ʹ��!\n");
		    break;
	    }
	}
	
	if(choice==2)
	{
		int x;
		system("CLS");
		printf("�ڶ���𰸹���:\n");
		fun2();
		
		printf("\n\n�˳��밴0�����������밴1:"); 
		scanf("%d",&x);
		if(x==0)
		{
		    printf("��ӭ�´�ʹ��!\n");
		    break;
	    }
	}
	
	if(choice==3)
	{
		int x;
		system("CLS");
		printf("������𰸹���:\n");
		fun3();
		
		printf("\n\n�˳��밴0�����������밴1:"); 
		scanf("%d",&x);
		if(x==0)
		{
		    printf("��ӭ�´�ʹ��!\n");
		    break;
	    }
	}
	
	if(choice==4) 
	{ 
	    printf("\n��ӭ�´�ʹ��!\n");
	    break;
	} 
    } 
    }
    }       	
} 

void fun1()
{
	int i,j;
	int n;
	
	printf("Input n:");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			printf(" ");
		}
		printf("%c",'A'+i-1);
		if(i==1)
		{
			printf("\n");
			continue;
		}
		
		for(j=1;j<=2*i-3;j++)
		{
			printf(" ");
		}
		printf("%c",'A'+i-1);
		printf("\n");
	}
	
	for(i=1;i<n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf(" ");
		}
		printf("%c",'A'+n-i-1);
	    if(i==n-1)
		{
			printf("\n");
			break;
		}
		
		for(j=1;j<=2*(n-i)-3;j++)
		{
			printf(" ");
		}
		
		printf("%c",'A'+n-i-1);
		printf("\n");
	}
}

void fun2()
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

void fun3()
{
	int a,b,c,result;
	printf("Input a,b,c:");
	scanf("%d%*c%d%*c%d",&a,&b,&c);
	if(a>9||b>9||c>9)
	  printf("error!because the number will be the 0~9\n");
	else 
	  printf("result=%d=%d*%d*%d+%d*%d*%d+%d*%d*%d",result=a*a*a+b*b*b+c*c*c,a,a,a,b,b,b,c,c,c);
} 
