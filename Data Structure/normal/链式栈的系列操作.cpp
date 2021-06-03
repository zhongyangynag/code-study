#include<stdio.h>
#include<stdlib.h>

//��ʽջ��ϵ�в���
typedef int DataType;

//��ջ�Ľ������ 
typedef struct node{
	DataType data;
	struct node *next;
}SNode;

//��ջ�Ľṹ����
typedef struct{
	SNode *top;
}LinkStack;

//��ʼ��
void initStack(LinkStack *LS)
{
	LS->top = NULL;	
} 

//���ջ
void clearStack(LinkStack *LS) 
{
	SNode *p = NULL;
	SNode *q = NULL;
	
	q = LS->top;
	while(q != NULL)
	{
		p = q;                         //�������� 
		q = q->next;
		free(p); 
	}
	LS->top = NULL;
}

//��ȡջ��Ԫ��
void getTop(LinkStack *LS) 
{
	if(LS->top == NULL)
	{
		printf("��ջ!\n");
		exit(1);
	}
	else
	{
		printf("%d",LS->top->data);
	}
}

//���ջ�Ƿ�Ϊ��
int isEmpty(LinkStack *LS)
{
	return (LS->top == NULL);
}

//��ջ
void push(LinkStack *LS, DataType elem)
{
	SNode *t = NULL;
	t = (SNode *)malloc(sizeof(SNode));
	if( t== NULL )
	{
		printf("�ڴ�������!\n");
		exit(1);
	}
	t->data = elem;
	t->next = LS->top;
	LS->top = t;
} 

//��ջ
void pop(LinkStack *LS) 
{
	SNode *t;
	if(LS->top == NULL)
	{
		printf("ջ��!\n");
		exit(1);
	}
	t = LS->top;
	printf("%d\n",t->data);
	LS->top = LS->top->next;
	free(t);
}

//���Դ��� 
int main()
{
	LinkStack LS;
	
	initStack(&LS);
	push(&LS, 5);
	pop(&LS); 
	push(&LS, 3);
	getTop(&LS);
}
 
