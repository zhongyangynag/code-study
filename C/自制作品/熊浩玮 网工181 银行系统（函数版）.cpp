#include<stdio.h>
int bank(int o);

int main()
{
    int key,i,j;
	int q;
	int o;
	
	printf("��ӭ��ʹ��XHW����ATMϵͳ��\n���ű�ϵͳ��������������飡\n\n\n") ; 
	
	printf("�������λ�����������\n");
	printf("������6λ��������:");
	scanf("%d",&key);
	
    
    for(i=1;i<3;i++)
    {
	    j=key;
		if(j==123456)
		{
		   q=1; 
		   printf("\n������ȷ���ɹ����룡\n");
		   break;
 	    }
 	    else
		{    
		    q=0;
		    printf("\n����������ٴ�����:");
		    scanf("%d",&key);
	    }
    }
    
    if(j==123456)
	    bank(o);
	else
	{
	    printf("\n���Ŀ��Ѿ������ᣡ\n");
        printf("\n�뵽XHW���нⶳ��");
    }
    
	return 0;
}
	  
	  
	  
int bank(int o)
{
	int key,i,j;
	int q;
	
	if(q=1)
	{ 
    int a,m,x,y;
    printf("\n\n��������ѡ��\n");
    printf("1����ѯ���\n2�����\n3��ȡ��\n4�������˹�\n5���˿�\n");
    printf("\n��������ѡ���ѡ�");
	scanf("%d",&a);
	printf("\n");
	
	if(a==5)
	{
		printf("��ȡ���������п�����ӭ�´�ʹ�ã�"); 
	}
	
	else 
	{
	for(y=1;;y++)
	{
	  switch(a)
      {
		case 1:
			{
				printf("\n���������9999999999999999��\n");
				break; 
			}
		case 2:
			{
				printf("\n���������");
				scanf("%d",&m);
			
			    if(m>2000)
				    {
				    	printf("\nһ���Դ��ܴ���2000��\n");
						printf("\n����һ���������") ; 
						scanf("%d",&m);
					}
				
				printf("\n���Եȣ�����Ϊ������\n");
				printf("\n�����ɣ�\n");
				break; 
			}
		case 3:
			{
				printf("\n������ȡ���");
				scanf("%d",&m);
				
				if(m>2000)
				    {
				    	printf("\nһ����ȡ��ܴ���2000��\n");
						printf("\n����һ������ȡ���") ; 
						scanf("%d",&m);
					}
	
				printf("\n���Եȣ�����Ϊ������\n");
				printf("\n��ȡ�������ֽ�!\n");
				break;
			}
		case 4:
			{
				printf("���Եȣ�����Ϊ�����ţ�\n"); 
				break; 
			}
       }
	    printf("\n��������ѡ��\n");
	    printf("1����ѯ���\n2�����\n3��ȡ��\n4�������˹�\n5���˿�\n");
        printf("\n��������ѡ���ѡ�");
	    scanf("%d",&a);
	    printf("\n");  
	    
	    if(a==5)
      	{
		      printf("��ȡ���������п�����ӭ�´�ʹ�ã�"); 
		      break;
	    }
    }
    }
    }   
    return 1;
}
