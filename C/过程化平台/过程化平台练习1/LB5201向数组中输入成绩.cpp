#include<stdio.h>

#define NOT_FIND -1
#define TOTAL_STU 8

float aver(int pStu[TOTAL_STU][7], int stuNo);

int main(void)
{
	int student[TOTAL_STU][7]; /* the first column save student's number */
	float averScore;
	int i,j,stuNumber;
	
	printf("Input the %d student's number and score: \n", TOTAL_STU);
	for(i=0;i<TOTAL_STU;i++)
	{
		for(j=0;j<7;j++)
		{
			scanf("%d",&student[i][j]);
		}
	}
	printf("Input a student's number to compute: ");
	scanf("%d",&stuNumber);
	printf("Output:\n");
	averScore=aver(student,stuNumber);
	if(averScore==NOT_FIND)
	{
		printf("\nstudent of No.%d not Find!\n", stuNumber);
	}
	else
    {
		printf("The No.%d student's average is %.2lf",stuNumber,averScore);
    }
} 

/******start******/
float aver(int pStu[TOTAL_STU][7], int stuNo)
{
	int i,j;
	double sum=0;
	for(i=0;i<TOTAL_STU;i++)
	{
		if(stuNo==pStu[i][0])
			{
				for(j=1;j<7;j++)
				{
					sum+=pStu[i][j];
				}
				return (float)(sum/6);
			}
	}
	return NOT_FIND;
}
/******end******/

