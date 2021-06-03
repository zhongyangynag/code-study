#include<stdio.h>

/******start******/
struct Student{
	int number;
	char name[20];
	float prize;
};

int main()
{
	struct Student em[100];
	int n;
	int i;
	
	printf("Input the number(<50):\n");
	scanf("%d",&n);
	printf("Input the info:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d%s%f",&em[i].number,em[i].name,&em[i].prize);
	}
/******end******/	

	printf("Output:\n");
	printf("number\tname\tprize\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", em[i].number);
		printf("%s\t", em[i].name);
		printf("%.2f\n", em[i].prize);
	}

	return 0;
}
