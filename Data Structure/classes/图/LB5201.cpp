/*
�շ������룺
����n����Ȩֵ�Ľ�㣬����շ�������
���������n������Ȩֵ����������볤��(���ý����������ĺ������е����)�ĳ˻����ܺ͡�����

�������룺
��һ����һ��������n����ʾһ����n����㡣
�ڶ���Ϊn���������ֱ��ʾ��n������Ȩֵ������

���������
���������n������Ȩֵ����������볤�ȵĳ˻����ܺ͡�����
*/
#include <stdio.h>

void sort(int arr[], int low, int high);

int main(void)
{
	int i, j, n, sum = 0;
	int arr[101];
	printf("Input:");
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	for (i = 0; i < n - 1; i++)
	{
		sort(arr, i, n);
		/*
		for (j = 0; j < n; j++)
		{
			printf("%d ", arr[j]);
		}
		printf("sum=%d\n", sum);
		*/
		arr[i + 1] = arr[i] + arr[i + 1];
		sum = sum + arr[i + 1];
	}
	printf("Output: %d\n", sum);
	return 0;
}

void sort(int arr[], int low, int high)
{
	int i, j, te;
	
	for (i = low; i < high; i++)
	{
		for (j = low; j < high + low - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				te = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = te;
			}
		}
	}
}
