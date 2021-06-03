#include<stdio.h>

/******start******/
int fun(int n);
/******end******/

int main()
{
	int i,n;
	printf("Please input n: ");
	scanf("%d",&n);
	printf("Output:\n");
	for(i=1;i<=n;i++)
	{
		printf("%d!=%d\n",i,fun(i));
	}
	return 0;
}

/******start******/
int fun(int n)
{
	static int res=1;
	
	res=res*n;
	
	
	return res;  
}
/******end******/
