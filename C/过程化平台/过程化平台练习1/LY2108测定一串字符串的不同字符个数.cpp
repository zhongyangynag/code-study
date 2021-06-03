#include<stdio.h>
#include<math.h> 

int main()
{
	int a,b,c,d;
	char str;
	printf("Input: ");
	
	a=0;
	b=0;
	c=0;
	d=0;
	while((str=getchar())!='\n')
	{
		if((str>='A'&&str<='Z')||(str>='a'&&str<='z'))
			a++;
		else if(str==' ')
		    b++;
		else if(str>='0'&&str<='9')
			c++;
		else
		    d++;
	}
	
	printf("Output:\n");
	printf("%d %d %d %d\n",a,b,c,d);
} 
