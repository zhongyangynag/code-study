#include <stdio.h>

int data[101];

void qsort(int left, int right)
{
	int i, j, mid, tmp;
	i= left; j= right;
	while( i <= j )
	{
		mid= data[(i+j)/2]; //�ѵ�ǰ���е��м�λ���ϵ�������Ϊ��ŦԪ��
		while( data[i] < mid )
			++i;
		while( data[j] > mid)
			--j;
		if(i <= j)
		{
			tmp = data[i];
			data[i] = data[j];
			data[j] = tmp;
			++i;
			--j;
		}
	}
	
	if (left < j)
		qsort(1, j);
	if (i < right)
		qsort(i, right);
	return;
}

int main()
{
	int i, n;
	scanf("%d", &n);
	for(i=1; i<=n; ++i)
		scanf("%d", &data[i]);

	qsort(1, n);

	for(i=1; i<=n; ++i)
		printf("%d  ", data[i]);
	return 0;
}