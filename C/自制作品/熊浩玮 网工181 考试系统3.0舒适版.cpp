#include<stdio.h>
#include<windows.h>
int meum(int choice);
int fun1(int n);
long fun2(long a,long b);
int fun3(int a,int b,int c);
int choose(int choice);

int main()
{
	int start;
	int choice;
	int answer;
	
	printf("��ӭ�������ò���ϵͳ!\n(���س�����)\n");
	getchar();
	printf("��׼��������׼�������밴1,δ׼����������0\n");
	printf("������:");
	scanf("%d",&start);
	
	if(start==0)
	    printf("\n��ӭ�´�ʹ��!\n");
	else
	{
		
    printf("\n�鿴���밴1,�˳��밴0:");
    scanf("%d",&answer);
    
    if(answer==0)
        printf("\n��ӭ�´�ʹ��!\n");   
	else
	{
	choose(choice);
    }
    }       	
} 

int meum(int result)
{
	system("CLS");
	printf("\n���Ǳ����Ե���Ŀ,��������Ҫ��ѯ�Ĵ�:\n"); 
	printf("\n************************************************\n\n");
	printf("1�����*��ͼ��\n");
	printf("2��������������ڵ�����\n");
	printf("3��������������ˮ�ɻ���\n");
	printf("4���˳�\n"); 
	printf("\n************************************************\n\n");
	
    printf("\n������ѡ�����ѡ��:"); 
	scanf("%d",&result);  
	
	if(result!=1&&result!=2&&result!=3&&result!=4)
	{ 
	    printf("�������������룺");
	    scanf("%d",&result);  
    }
	return result;
}

int choose(int choice)
{
	int i;
	int result;
	for(i=1;;i++)
	{
		
	choice=meum(result);
	
	if(choice==1)
	{
		int x;
		int d;
		int n;
		
		system("CLS");
		printf("��һ��𰸹���:\n");
		printf("Input n:");
	    scanf("%d",&n);
	    
		fun1(n);
	
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
		int f;
		long a,b;
		
		system("CLS");
		printf("�ڶ���𰸹���:\n");
		printf("��С������������������Ϊ����Ҫ�����䣺");
	    scanf("%ld%*c%ld",&a,&b);
	    printf("�����������Ϊ[%ld,%ld]\n",a,b);

		fun2(a,b);
		
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
		int g;
		int a,b,c;
		
		system("CLS");
		printf("������𰸹���:\n");
		printf("Input a,b,c:");
	    scanf("%d%*c%d%*c%d",&a,&b,&c);
	    
		fun3(a,b,c);
		
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

int fun1(int n)
{
	int i,j;
	
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
	return 1;
}

long fun2(long a,long b)
{
	long n,i;
	long count=0;
	long flag=0;
	
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
    return 1;
}

int fun3(int a,int b,int c)
{
	int result;

	if(a>9||b>9||c>9)
	  printf("error!because the number will be the 0~9\n");
	else 
	  printf("result=%d=%d*%d*%d+%d*%d*%d+%d*%d*%d",result=a*a*a+b*b*b+c*c*c,a,a,a,b,b,b,c,c,c);
	  
	return 1;
} 
