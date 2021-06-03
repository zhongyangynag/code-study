#include <stdio.h>

int main(void)
{
	int i, j, sum = 0;
	int array[3][3];

	printf("Please input the 3x3 Matrix:\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &array[i][j]);
			sum += array[i][j];
		}
	}
	printf("Output:\nsum=%d\n", sum);
	return 0;
}

