/*
    �����ж����ʵ���ļ�
*/
#include "BiTree.h"
#include "malloc.h" 
#include "stdio.h"

//�����еĴ洢������������������QNodeΪ���������ͣ�QueuePtrΪָ���������ָ������
typedef struct QNode   
{
	/*��������ķǵݹ鴴������Ҫ��������У���洢�Ļ���Ԫ������
	��ָ��ĳ�������������ָ�����ͣ���BiTNode *, ���Գ�ԱpData���¶���    */
	BiTNode *pData;      
	struct QNode *next;
}QNode,*QueuePtr;

//һ�������нṹ�壬����2����Ա����ͷָ��Ͷ�βָ�룬����QueuePtr����
typedef struct
{
	QueuePtr front, rear;
}LinkQueue;
 

int InitQueue(LinkQueue *Q)
{
	(*Q).front=(*Q).rear=(QueuePtr)malloc(sizeof(QNode));
	if(!(*Q).front)
		return -1;
	(*Q).front->next=NULL;
	return 0;
}

int DestroyQueue(LinkQueue *Q)
{
   while((*Q).front)
   {
     (*Q).rear=(*Q).front->next;
     free((*Q).front);
     (*Q).front=(*Q).rear;
   }
   return 0;
}

int ClearQueue(LinkQueue *Q)
{
   QueuePtr p,q;
   (*Q).rear=(*Q).front;
   p=(*Q).front->next;
   (*Q).front->next=NULL;
   while(p)
   {
     q=p;
     p=p->next;
     free(q);
   }
   return 0;
}

 int QueueIsEmpty(LinkQueue Q)
 { 
   if(Q.front==Q.rear)
     return 1;
   else
     return 0;
 }

 int GetHead_Q(LinkQueue Q, BiTNode **e)
 {
   QueuePtr p;
   if(Q.front==Q.rear)
     return -1;
   p=Q.front->next;
   *e=p->pData;
   return 0;
 }

 int EnQueue(LinkQueue *Q, BiTNode *e)
 {
   QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
   if(!p)
     return -1;
   p->pData=e;
   p->next=NULL;
   (*Q).rear->next=p;
   (*Q).rear=p;
   return 0;
 }

 int DeQueue(LinkQueue *Q, BiTNode **e)
 {
   QueuePtr p;
   if((*Q).front==(*Q).rear)
     return -1;
   p=(*Q).front->next;
   *e=p->pData;
   (*Q).front->next=p->next;
   if((*Q).rear==p)
     (*Q).rear=(*Q).front;
   free(p);
   return 0;
 }

