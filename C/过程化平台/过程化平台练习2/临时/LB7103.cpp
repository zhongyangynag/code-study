#include<stdio.h>

enum color{
	red,yellow,blue,white,black
}; 

int main()
{
	int i,j,k;
	int count=0;
	int loop,p;
	
	printf("Output:\n");
	for(i=red;i<=black;i++)
	{
		for(j=red;j<=black;j++)
		{
			if(j!=i)
			{
				for(k=red;k<=black;k++)
				{
					if(k!=j&&k!=i)
					{
						count++;
						printf("%-4d",count);
						for(loop=0;loop<3;loop++)
						{
							switch(loop)
							{
								case 0:
									p=i;break;
								case 1:
									p=j;break;
								case 2:
									p=k;break;
							}
							
							switch(p)
							{
								case 0:
									printf("%-10s","red");
									break;
								case 1:
									printf("%-10s","yellow");
									break;
								case 2:
									printf("%-10s","blue");
									break;	
								case 3:
									printf("%-10s","white");
									break;
								case 4:
									printf("%-10s","black");
									break;
							}		
						}
						printf("\n");
					}
				}
			}
		}
	}
	printf("\ntotal:%5d\n",count);
}
