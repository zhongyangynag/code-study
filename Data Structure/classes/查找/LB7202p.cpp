//����һ������������20������������۰���ң���������Ҹ��������ѵıȽϴ���
//��1��3��5��7��Ϊ��ʾ��Ϣ����2��������Ԫ�ظ�������4�������Ԫ�ص�ֵ����6��������Ҫ���ҵ����ݣ���8��Ϊ��������ʹ�ð�Ƕ��ţ���
#include <stdio.h>
#define max 20

int binary(int x, int list[], int n)/*��list[]�в���x*/
{
	int low, high, mid, time;
	time = 0;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;/*�۰�*/
		if (x < list[mid])/*��ǰ�벿�ֲ���*/
		{
			high = mid - 1;
			time = time + 1;
		}
		else if (x > list[mid])/*�ں�벿�ֲ���*/
		{
			low = mid + 1;
			time = time + 1;
		}
		else
		{
			time = time + 1;
			printf("Output:\n");
			printf("�ҵ���,��data[%d]��,�Ƚ���%d��\n", mid, time);
			return (0);
		}
	}
	return (time);
}

int main()
{
	int list[max], index, x, num, i;
	printf("Input Number:\n");
	scanf("%d", &num);
	printf("Input Values:\n");
	for (i = 0; i < num; i++)
	{
		//printf("data[%d]=", i);
		scanf("%d", &list[i]);
	}
	printf("Search Value:\n");
	/*�������������*/
	scanf("%d", &x);
	index = binary(x, list, num);
	if (index != 0)
	{ 
		printf("Output:\n");
		printf("û�ҵ�,�Ƚ���%d��\n", index);
	}
	return 0;
}
