#include<stdio.h>

struct Student{
	int num;
	int score;
};

int main()
{
	int n;
	int i,j;
	struct Student st[100];
	struct Student temp;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&st[i].num,&st[i].score);
	}
	printf("Output:\n");
	
	for(j=n;j>1;j--)
	{
		for(i=1;i<j;i++)
		{
			if(st[i].score<st[i-1].score)
			{
				temp=st[i];
				st[i]=st[i-1];
				st[i-1]=temp;
			}
			if(st[i].score==st[i-1].score&&st[i].num<st[i-1].num)
			{
				temp=st[i];
				st[i]=st[i-1];
				st[i-1]=temp;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",st[i].num,st[i].score);
	}
	
	
	
	
	
	
	
}
