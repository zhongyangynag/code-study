#include <stdio.h>

typedef struct _singer
{
	int number;
	int score[6];
	float average;
}singer;

int main(void)
{
	int i, j, sum, min, max;
	singer temp;
	singer people[10];      //这里要定义局部变量，全局变量会给结构体赋初值0 

	for (i = 0; i < 10; i++)
	{
		people[i].number = i + 1;
	}

	printf("Please input singer's score: ");
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 6; j++)
		{
			scanf("%d", &people[i].score[j]);
			
			if(people[i].score[j] > 10 || people[i].score[j] < 0)
			{
				printf("output:\n成绩必须为10分制:\n");
				return 0;
			}
		}
	}

	//求平均成绩
	for (i = 0; i < 10; i++)
	{
		sum = 0;
		min = max = people[i].score[0];
		for (j = 0; j < 6; j++)
		{
			if (min > people[i].score[j])
			{
				min = people[i].score[j];
			}
			if (max < people[i].score[j])
			{
				max = people[i].score[j];
			}

			//计算总成绩
			sum = sum + people[i].score[j];
		}

		people[i].average = (float)((sum - min - max) / 4.0);
	}

	//排序,排序一定要按照答案的方式来排序，不然输出的结果虽然是正确的，但是相同分的顺序不一样 
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10 - i - 1; j++)
		{
			if (people[j].average < people[j + 1].average)
			{
				temp = people[j];
				people[j] = people[j + 1];
				people[j + 1] = temp;
			}
		}
	}
	
	/*
	for(i=0;i<10;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(people[i].average<people[j].average)
			{
				temp=people[i];
				people[i]=people[j];
				people[j]=temp;
			}
		}
	}
	*/


	//成绩输出
	printf("output:\nscores:\n");
	for (i = 0; i < 10; i++)
	{
		printf("No.%d:%.2f\n", people[i].number, people[i].average);
	}

	return 0;
}

