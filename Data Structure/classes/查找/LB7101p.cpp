#include <stdio.h>
//����һ������������11��������֯һ����ϣ����ϣ������H��K��=Kmod7
//��ϣ����Ϊ11����Ԫ����ʼ��ַΪ0��Ҫ��������̽�ⷽ�������ͻ��
int main()
{
	int i, j;
	int a[11] = {0};
	int num, value;
	
	printf("Input Number:\n");
	scanf("%d", &num);
	printf("Input Values:\n");
	for(i = 0; i < num; i++)
	{
		scanf("%d", &value);
		j = value % 7;
		while (a[j] != 0)
		{
		j = (j + 1) % 11;
		}
		a[j] = value;
	}
	printf("Output:\n");
	
	for(i = 0; i < 11; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
