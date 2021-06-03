#include<stdio.h>

int main()
{
	double score;
	char grade;
	int a;
	int i; 
	
	printf("please input the score(0-100):");
	scanf("%lf",&score);
	printf("Output:\n");
	while(score<0||score>100)
	{
		printf("please input the score(0-100):");
		scanf("%lf",&score);
	}
	a=(int)score/10;
	switch(a)
	{
		case 10:
		case 9:
			grade='A';
			break;
		case 8:
			grade='B';
			break;
		case 7:
			grade='C';
			break;
		case 6:
			grade='D';
			break;
		default:
			grade='E';
			break;
	}
	printf("score=%.1lf,grade=%c\n",score,grade);
	
}
