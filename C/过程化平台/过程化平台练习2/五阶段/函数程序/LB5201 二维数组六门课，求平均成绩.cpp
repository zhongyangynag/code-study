#include<stdio.h>

#define NOT_FIND -1
#define TOTAL_STU 8

/* 函数aver的功能为：求学号为stuNo的学生的6门课课程之平均成绩，并通过函数值返回
		若未找到学生stuNo，则返回NOT_FIND */	
float aver(int (*pStu)[7], int stuNo);

int main(void)
{
	int student[TOTAL_STU][7]; /* the first column save student's number */
	float averScore;
	int i, j, stuNumber;

	printf("Input the %d student's number and score: \n", TOTAL_STU);
	/* 本部分代码功能建议：从键盘读入的8个学生的6门课成绩存放在二维数组student中 */	
	/******start******/
	for(i=0;i<8;i++)
	{
		for(j=0;j<7;j++)
		{
			scanf("%d",&student[i][j]);
		}
	}
	/******end******/

	printf("Input a student's number to compute: ");
	scanf("%d", &stuNumber);

	averScore = aver(student, stuNumber);
	printf("Output:");
	if (NOT_FIND == averScore)
	{
		printf("\nstudent of No.%d not Find!\n", stuNumber);
	}
	else
	{
		printf("\nThe No.%d student's average is %.2f\n", stuNumber, averScore);
	}

	return 0;
}

/******start******/
float aver(int (*pStu)[7], int stuNo)
{
	int i,j;
	int flag=0;
	float avg=0;
	float sum=0;
	
	for(i=0;i<8;i++)
	{
		if(stuNo==pStu[i][0])
		{
			for(j=1;j<7;j++)
			{
				sum+=pStu[i][j];
			}
			avg=sum/6;
			flag=1;
		}
	}
	
	if(flag==1)
	{
		return avg;
	}
	if(flag==0)
	{
		return -1;
	}
}
/******end******/
