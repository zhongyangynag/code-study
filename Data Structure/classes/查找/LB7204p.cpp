#include <stdio.h>
#define N 51
//�Բ������һ���۰���ҵĳ�����Ҫ�����������Ƿ��������򣩽����жϣ��������������򣬴�����ʾ��
int main(void)
{
	int a[N];
	int i,n,num;
	int top,bottom,mid;
	int flag=1; //����ڱ������ҵ����֣���ֵΪ1������Ϊ0
	int loc=-1;//Ҫ���ҵ����ڱ����е�λ�ã����loca=-1��ʾ������û�������;����������,������ֵΪ���ڵ�λ��
	printf("���������Ԫ�ظ���(1-50): ");
	scanf("%d",&n);
	while(n<1 || n>50)
	{
		printf("��������ȷ,����������!/n");
		printf("���������Ԫ�ظ���(1-50): ");
		scanf("%d",&n);
	}
	printf("���������Ԫ��: ");
	/******start******/
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(i = 1; i < n; i++)
	{
		if(a[i+1] < a[i])
		{
			printf("������������!\n");
			return 0;
		}	
	}	
	/******end******/
	printf("��������Ҫ���ҵ���: ");
	scanf("%d",&num);
	flag=1; //������������ڱ�����
	top=n;
	bottom=1;
	mid= (top+bottom)/2;
	while(flag)
	{
		/******start******/
		mid = (top + bottom) / 2;
		if(top < bottom)
		{
			flag = 0;
			printf("û���ҵ�!\n");
			break;
		}
		
		if(num < a[mid] )
		{
			top = mid - 1;
		}
		else if(num > a[mid])
		{
			bottom = mid + 1;
		}
		else
		{
			flag = 0;
			loc = a[mid];
			printf("�ҵ���!   %d", loc);
			break;
		}
		/******end******/
	}
	return 0;
}
