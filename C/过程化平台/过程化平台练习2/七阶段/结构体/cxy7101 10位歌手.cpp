#include<stdio.h>

struct Singer{
	int num;
	int score[6];
	double average;
};

int main(void)
{
	int i,j;
	int min,max;
	double sum;
	struct Singer temp;
	struct Singer person[10];
	
	for(i=0;i<10;i++)
	{
		person[i].num=i+1;
	}
	
	printf("Please input singer's score: ");
	for(i=0;i<10;i++)
	{
		for(j=0;j<6;j++)
		{
			scanf("%d",&person[i].score[j]);
			
			if(person[i].score[j] > 10 || person[i].score[j] < 0 )
			{
				printf("output:\n");
				printf("成绩必须为10分制:\n");
				return 0;
			}
		
		}
	}
	
	for(i=0;i<10;i++)
	{
		sum=0;
		min=person[i].score[0];
		max=person[i].score[0];
		for(j=0;j<6;j++)
		{
			if(min>person[i].score[j])
			{
				min=person[i].score[j];
			}
			if(max<person[i].score[j])
			{
				max=person[i].score[j];
			}
			sum=sum+person[i].score[j];
		}
		person[i].average=((sum-min-max)/4.0);
	}
	
	for(j=10;j>1;j--)
	{
		for(i=1;i<j;i++)
		{
			if (person[i].average>person[i-1].average)
			{
				temp=person[i];
				person[i]=person[i-1];
				person[i-1]=temp;
			}
		}
	}
	
	printf("output:\nscores:\n");
	for(i=0;i<10;i++)
	{
		printf("No.%d:%.2lf\n",person[i].num,person[i].average);
	}
	
	return 0;	
}

