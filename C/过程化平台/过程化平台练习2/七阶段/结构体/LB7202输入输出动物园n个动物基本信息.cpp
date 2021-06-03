#include<stdio.h>

struct animal
{
/******start******/
	int No;
	char name[10];
	int count;
};

int main()
{
	struct animal ani[20];
	int n;
	int i;
	
	printf("Input the number(<50):\n");
	scanf("%d",&n);
	printf("Input the info:\n");
	
	for(i=0;i<n;i++)
	{
		scanf("%d%s%d",&ani[i].No,ani[i].name,&ani[i].count);
	}
/******end******/	
	printf("Output:\n");
	printf("No\tname\tnumber\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", ani[i].No);
		printf("%s\t", ani[i].name);
		printf("%d\n", ani[i].count);
	}

	return 0;
}
