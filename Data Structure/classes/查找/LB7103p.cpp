#include <stdio.h>
#include <malloc.h>
//��֪��ͷ��������head��ɾ������ֵΪn�Ľ�㡣��һ���������ڽ�����������ݣ�0��ʾ����������������������
//�ڶ���Ϊԭʼ���������������Ϊ������Ҫɾ����nֵ����nֵ������������ɾ����������������ʾ����
typedef struct _node
{
	int data;
	struct _node *next;
} node;

node *create(); //������ͷ��������
void out(node *head); //�������
int erase(node *head, int value); //ɾ������head��ֵΪvalue�Ľ��

int main(void)
{
	int result, value;
	node *head;
	printf("Input:");
	head = create();
	printf("Original:");
	out(head); //���ԭʼ����
	printf("Input Erase Value:");
	scanf("%d", &value); //������Ҫɾ����Ԫ��ֵ
	printf("Output:\n");
	result = erase(head, value);
	if (result == 0)
	{
		printf("Erase error!\n");
	}
	else
	{
		out(head);
	}
	return 0;
}

node *create()
{
	int n, i;
	node *head, *p, *q;
	head = (node*)malloc(sizeof(node));
	head->next = NULL;
	q = head;
	i = 0;
	scanf("%d", &n);
	while (n != 0)
	{
		p = (node*)malloc(sizeof(node));
		p->data = n;
		if (i % 2)
		{
			p->next = head->next;
			head->next = p;
		}
		else
		{
			p->next = q->next;
			q->next = p;
			q = q->next;
		}
		i++;
		scanf("%d", &n);
	}
	return head;
}

void out(node *head)
{
	node *p = head->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

/******start******/
int erase(node *head, int value) //ɾ������head��ֵΪvalue�Ľ��
{
	node *temp1, *temp2;
	int flag;
	
	if(head == NULL)
	{
		flag = 0;
	} 
	
	temp1 = head;
	
	while(temp1->next != NULL)
	{
		if(temp1->next->data == value)
		{
			temp2 = temp1->next;
			temp1->next = temp1->next->next;
			free(temp2);
			flag = 1;
			break;
		}
		temp1 = temp1->next;
	}

	if(flag == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
} 

/******end******/
