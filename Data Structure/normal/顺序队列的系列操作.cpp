#include<stdio.h>
#include<stdlib.h>

//˳����е�ϵ�в���
typedef int Datatype;
#define MaxSize 200
typedef struct{
	Datatype stack[MaxSize];
	int front;                              //ͷ,�ڵ�һ��Ԫ��֮ǰ��λ�� 
	int rear;	                            //β�������һ��Ԫ�ص�λ�� 
}SeqQueue;


//��ʼ��
void initQueue(SeqQueue *q)
{
	q->front = -1;
	q->rear = -1;
}

//��ն���
void clearQueue(SeqQueue *q)
{
	q->front = -1;
	q->rear = -1;
}

//��ȡ����ͷԪ��
void getTop(SeqQueue *q)
{
	if(q->front == q->rear)
	{
		printf("����Ϊ��!\n");
		exit(1);
	}

	printf("%d\n",q->stack[q->front + 1]);
}

//�������Ƿ�Ϊ��
int isEmpty(SeqQueue *q)
{
	return (q->front == q->rear);	
} 

//���
void InsQueue(SeqQueue *q, Datatype elem)
{
	if(q->rear == MaxSize - 1)
	{
		printf("��������!\n");
		exit(1);
	}
	
	q->rear++;
	q->stack[q->rear] = elem;
}

//����
void delQueue(SeqQueue *q) 
{
	if(q->front == q->rear)
	{
		printf("����Ϊ��!\n");
		exit(1);
	}
	
	q->front++;
	printf("%d\n",q->stack[q->front]);
}

//���Դ��� 
int main()
{
	SeqQueue q;
	
	InsQueue(&q, 5);
	InsQueue(&q, 10);
	getTop(&q);
	delQueue(&q);
	getTop(&q);	
}












 












