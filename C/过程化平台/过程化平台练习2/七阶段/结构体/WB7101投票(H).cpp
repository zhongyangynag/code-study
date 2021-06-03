/******start******/
#include<stdio.h>
#include <string.h>

struct person {
    char name[20];
    int count;
}leader[3] = {"Li", 0, "Zhang", 0, "Fun", 0};

int main()
{
	int n;
	int i,j;
	char vote[20];
	
	printf("Please input total number:\n");
	scanf("%d",&n);
	printf("Please input the candidate's name:\n");
	
	for(i=0;i<n;i++)
	{
		scanf("%s",vote);
		for (j = 0;j < 3;j++)                               //ÇÉÃîÖ®´¦ 
            if (strcmp(vote, leader[j].name) == 0)
        		leader[j].count++;

	}
	
	
/******end******/
	printf("Output:\nThe result is:\n");
	for (i = 0;i < 3;i++)
	{
		printf("%s:%d\n", leader[i].name, leader[i].count);
	}
	return 0;
}
