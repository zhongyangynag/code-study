#include<stdio.h>

/******start******/
struct student{
	int number;
	char name[10];
	int age;
	double score;
};
/******end******/

int main(void)
{
	struct student st1;
	
	printf("Input the info:\n");
	scanf("%d%s%d%lf", &st1.number, st1.name, &st1.age, &st1.score);
	
	printf("Output:\n");
	/******start******/
    printf("number:%d\n",st1.number);
    printf("name:%s\n",st1.name);
	printf("age:%d\n",st1.age);
	printf("score:%.2lf\n",st1.score);
	/******end******/
	return 0;
}
