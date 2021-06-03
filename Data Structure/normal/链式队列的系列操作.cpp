#include<stdio.h>
#include<stdlib.h>

//��ʽ���е�ϵ�в���

//���������� 
typedef int Datatype;
typedef struct node{
	Datatype data;
	struct node *next;
}QNode;

//����ṹ����
typedef struct{
	QNode *front;
	QNode *rear;
}LinkQueue;

//��ʼ��
void initQueue(LinkQueue *lq)
{
	lq->front = NULL;
	lq->rear = NULL;
} 

//��ն���
void clearQueue(LinkQueue *lq) 
{
	QNode *tmp;
	
	if( lq->front != lq->rear)
	{
		tmp = lq->front;
		lq->front = tmp->next;
		free(tmp);
	}
	
	free(lq->front);                    //���ͷ��βһ��
	lq->front = NULL;
	lq->rear = NULL; 
}

//��ȡ����ͷԪ��
void getTop(LinkQueue *lq) 
{	
	if(lq->front == NULL)
	{
		printf("����Ϊ��!\n");
		exit(1);
	} 
	
	printf("%d\n",lq->front->data);
}

//�������Ƿ�Ϊ��
int isEmpty(LinkQueue *lq)
{
	return (lq->front == NULL);
}

//���
void insQueue(LinkQueue *lq, Datatype elem)
{
	QNode *tmp;
	tmp = (QNode *)malloc(sizeof(QNode));
	
	if(lq->front == tmp)
	{
		printf("�ڴ�������1\n");
		exit(1);
	}
	
	tmp->data = elem;
	tmp->next = NULL;
	
	if(lq->rear == NULL)                         //���ԭ����Ϊ�գ����ͷ�Ͷ�βָ�붼ָ���½�� 
	{
		lq->rear = tmp;
		lq->front = tmp; 
	}
	else                                         //������в�Ϊ�գ����βָ��ָ���½�� 
	{
		lq->rear->next = tmp;
		lq->rear = tmp;
	}
}

//����
void delQueue(LinkQueue *lq) 
{
	QNode *tmp;
	Datatype out;
	
	if(lq->front == NULL)
	{
		printf("����Ϊ��!\n");
		exit(1);
	}
	
	out = lq->front->data;                   //ȡ����ͷԪ�� 
	tmp = lq->front;                      
	lq->front = tmp->next;                   //��ͷ������һ���ڵ��Ϊ�µĶ�ͷ��� 
	
	if(lq->front == NULL)
	{
		lq->rear = NULL;
	}
	
	free(tmp);
	
	printf("%d\n",out);
}

//���Դ��� 
int main() 
{
	LinkQueue lq;
	
	initQueue(&lq);
	insQueue(&lq, 5);
	insQueue(&lq, 10);
	getTop(&lq);
	delQueue(&lq);
	getTop(&lq);
	
}
