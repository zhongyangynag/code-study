//ʹ�����������㷨���������ƴ˳���


#include <stdio.h>
#define N 10
void input(int a[], int n);
void output(int a[], int n);
void sort(int a[], int n);

int main(void)
{
	int a[N];
	input(a, N);
	sort(a, N);
	output(a, N);
	return 0; 
}

void input(int a[], int n)
{
	int i;
	printf("input:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
}

void output(int a[], int n)
{
	int i;
	printf("Output:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void sort(int a[], int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++)
	/*ע���������㷨�����ˣ���3��Ϊn��Ϊ��ȫ�����㷨*/
	{
		/******start******/
		for(j = 0; j < n-i; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
		/******end******/ 
	}
}





















