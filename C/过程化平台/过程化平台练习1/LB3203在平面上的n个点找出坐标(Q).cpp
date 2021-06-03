#include<stdio.h>

int main()
{
	int n;
	int i;
	int x,y;
	int minx,miny;
	
	printf("Input:\n");
	scanf("%d",&n);
	
	scanf("%d%d",&minx,&miny);
	
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		if(minx>x)
		{
			minx=x;
			miny=y;
		}
		else if(minx==x&&miny>y)
		{
			minx=x;
			miny=y;
		}
	}
	printf("Output: %d %d\n", minx, miny);
	return 0;
	
}
