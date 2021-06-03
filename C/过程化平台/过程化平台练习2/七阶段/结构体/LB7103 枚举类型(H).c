#include<stdio.h>

enum Color{
	red=0,yellow=1,blue=2,white=3,black=4
};

int main()
{
	enum Color i,j,k,pri;
	int count=1;
	int loop;
	
	printf("Output:\n");
	
	for(i=red;i<=black;i++)
	{
		for(j=red;j<=black;j++)
		{
			if(j==i)
				continue;
			else
			{
				for(k=red;k<=black;k++)
				{
					if(k==i||k==j)
					{
						continue;
					}
					else
					{
						printf("%-4d",count);
						count++;
						
						for(loop=1;loop<=3;loop++)
						{
							switch(loop)
							{
								case 1:
									pri=i;
									break;
								case 2:
									pri=j;
									break;
								case 3:
									pri=k;
									break;
							}
						
							switch(pri)
							{
								case red:
									printf("%-10s","red"); 
									break;            
	                  			case yellow: 
								  	printf("%-10s","yellow"); 
									break;     
	                  			case blue: 
								  	printf("%-10s","blue"); 
									break;         
	                  			case white: 
								  	printf("%-10s","white"); 
									break;      
	                  			case black: 
								  	printf("%-10s","black"); 
									break;       
	                  			default:
								  	break;
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
