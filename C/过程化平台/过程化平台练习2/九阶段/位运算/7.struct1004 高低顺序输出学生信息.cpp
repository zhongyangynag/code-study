//长度没说明，应该为 %6d %8s %6.2f 
#include<stdio.h>

typedef struct Student{
	int num;
	char name[10];
	float score;
}STUDENT;

int main()
{
	STUDENT student[5]={{10110,"Fun",100.00},
	{10103,"Wang",98.50},{10106,"Li",86.00},
	{10101,"Zhang",78.00},{10108,"Ling",73.50}};
	
	int i,j;
	STUDENT temp; 
	
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(student[i].score<student[j].score)
			{
				temp=student[i];
				student[i]=student[j];
				student[j]=temp;
			}
		}
	}
	
	printf("The order is:\n");
	printf("output\n");
	for(i=0;i<5;i++)
	{
		printf("%6d %8s %6.2f\n",student[i].num,student[i].name,student[i].score);
	}
} 
