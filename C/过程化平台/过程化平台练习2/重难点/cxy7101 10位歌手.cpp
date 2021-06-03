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
	singer people[10];      //����Ҫ����ֲ�������ȫ�ֱ�������ṹ�帳��ֵ0 

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
				printf("output:\n�ɼ�����Ϊ10����:\n");
				return 0;
			}
		}
	}

	//��ƽ���ɼ�
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

			//�����ܳɼ�
			sum = sum + people[i].score[j];
		}

		people[i].average = (float)((sum - min - max) / 4.0);
	}

	//����,����һ��Ҫ���մ𰸵ķ�ʽ�����򣬲�Ȼ����Ľ����Ȼ����ȷ�ģ�������ͬ�ֵ�˳��һ�� 
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


	//�ɼ����
	printf("output:\nscores:\n");
	for (i = 0; i < 10; i++)
	{
		printf("No.%d:%.2f\n", people[i].number, people[i].average);
	}

	return 0;
}

