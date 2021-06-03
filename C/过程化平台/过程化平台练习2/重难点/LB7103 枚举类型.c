//本题注意两点：一是输出是%-10s的长度,total是%5d的长度，题目没给出。而是，注意最里层循环的循环方式 
#include<stdio.h>

enum color{
	red,yellow,blue,white,black
};

int main()
{
	int i,j,k;
	int p,n;
	int count=1;
	
	printf("Output:\n");
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(j!=i)
			{
				for(k=0;k<5;k++)
				{
					if(k!=j&&k!=i)
					{
						printf("%-4d",count++);
						
						for(p=0;p<3;p++)
						{
							switch(p)
							{
								case 0:
									n=i;break;
								case 1:
									n=j;break;
								case 2:
									n=k;break;
							}
							
							switch(n)
							{
								case 0:
									printf("%-10s","red");break;
								case 1:
									printf("%-10s","yellow");break;
								case 2:
									printf("%-10s","blue");break;
								case 3:
									printf("%-10s","white");break;
								case 4:
									printf("%-10s","black");break;
									
							}
							
						}
						printf("\n");
					}
				}
			}
		}
	}
	
	printf("\ntotal:%5d\n",count-1);
}
