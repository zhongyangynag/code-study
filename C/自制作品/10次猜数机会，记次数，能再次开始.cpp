#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int imagic,guess,counter=0,q;
    srand(time(NULL));
	imagic=rand()%100+1;
	int i;
	int p=1;
	
	printf("������ʾ��������ϵͳֻ��ʮ�λ���\n"); 
	
	for(i=1;;i++)
	{
	do{ 
		printf("\nInput an imagic number:");
		scanf("%d",&guess);
		counter++;
		q=0;
		int e;
		
	  if(guess>imagic)
	  {
	    printf("\nwrong!too high!\n");
	    printf("counter=%d\n\n",counter);
	    
	    printf("����ֹ���β����밴2������������1���������Ĳ²⣺");
	    scanf("%d",&e);
	    if(e==2)
	        break;
	 
      }     
	  else if(guess<imagic)
   	  {
	    printf("\nwrong!too small!\n");
	    printf("counter=%d\n\n",counter);
	    
	    printf("����ֹ���β����밴2������������1���������Ĳ²⣺");
	    scanf("%d",&e);
	    if(e==2)
	        break;
	
      }  
	  else if(guess=imagic)
	  {
	    printf("\nyou are right!good!\n");
	    printf("counter=%d\n\n",counter);
      }
      else 
      {
      	q=1;
	  }
      
    }while(guess!=imagic&&counter<10);
    
    if(q==1)
        printf("Sorry,game out.\n")	;
    
    printf("\n������������������1���˳�����������2\n\n");
    scanf("%d",&p);
    
    if(p==2)
       break;
    else
       printf("\n��Ϸ�ٴο�ʼ!\n");
    }
        
    printf("\n��ӭ�´�ʹ�ã�");
}
