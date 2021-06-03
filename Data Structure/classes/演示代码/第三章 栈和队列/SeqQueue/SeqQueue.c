/*
 *  �ļ�����SeqQueue.c
 *	ѭ�����е�ʵ��
 *	�汾��1.0
 *	ʱ�䣺2016.06.26
 *	���ߣ�wangx
 *	�ٶ������� ����Ԫ�صĻ�������Ϊ����int
 *			
*/
//����3. ---------˳��ṹ�µ�ѭ�����л����ṹ�������---------//
//�ļ�����SeqQueue.c
#include "stdio.h"
#include "malloc.h"

#define MAXQSIZE 10        //�ٶ����鳤��Ϊ10
typedef int QElemType;     //�ٶ�����Ԫ��Ϊ�Ƚϼ򵥵�int��
typedef struct
{
    QElemType *base; //ע�⣬�����洢�ռ���Ҫ�ں����ж�̬���룬�˴�ֻ�Ƕ�����ָ��ÿռ��ָ��
    int front; //��ͷָ��,�����в���,ָ�����ͷԪ�ص��±�
    int rear;  //��βָ��,�����в���,ָ�����βԪ�ص���һ����λ�±�
}SeqQueue;

//����3. ---------˳��ṹ�µġ���������ʼ��һ�����С������㷨����---------//
//�ļ�����SeqQueue.c
//��Ϊ�漰�����ܸ���ָ����е�ָ��ֵ�����Բ��ö���ָ��ppQΪ�������Ա㷵��
int InitQueue(SeqQueue **ppQ)
{ 
    //����ѭ�����еĻ����ṹ������base��front��rear
    *ppQ= (SeqQueue *)malloc(sizeof(SeqQueue));
    if (!*ppQ) return -1;
    //����ѭ�����е���������ṹ������baseָ�������ռ�
    (*ppQ)->base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
    if(!(*ppQ)->base)
    {
        free(*ppQ);
        return -1;
    }
    //front��rear��ȣ���ʼ�����䶼Ϊ0��Ҳ���Բ���0��ʼ��
    (*ppQ)->front=(*ppQ)->rear=0;
    return 0;
}

//����3. ---------˳��ṹ�µġ��������١������㷨����---------//
//�ļ�����SeqQueue.c
//��Ϊ�漰�����ܸ���ָ����е�ָ��ֵ�����Բ��ö���ָ��ppQΪ�������Ա㷵��
int DestroyQueue(SeqQueue **ppQ)
{ /* ���ٶ���Q,Q���ٴ��� */
   if((*ppQ)->base)
     free((*ppQ)->base);
   if(*ppQ)
     free(*ppQ);
   *ppQ= NULL;
   return 0;
}

//����3. ---------˳��ṹ�µġ���ն��С������㷨����---------//
//�ļ�����SeqQueue.c
//����Ҫ����б������Ѵ��ڵ�
int ClearQueue(SeqQueue *pQ)
{
    if (pQ==NULL) return -1;
    pQ->front=pQ->rear=0;    //ע�⣬������Ҫ���������Ѵ��ڵ�Ԫ����Ϊ0���
    return 0;
}

//����3. ---------˳��ṹ�µġ��ж϶����Ƿ�Ϊ�ա������㷨����---------//
//�ļ�����SeqQueue.c
//����Ҫ����б������Ѵ��ڵģ����򷵻�-1
//������pQΪ�ն���,�򷵻�1,���򷵻�0
int QueueIsEmpty(SeqQueue *pQ)
{
    if (pQ== NULL) return -1;
    if(pQ->front==pQ->rear) /* ���пյı�־ */
        return 1;
    else
        return 0;
}

//����3. ---------˳��ṹ�µ�"��ȡ����Ԫ�ظ���"�����㷨����---------//
//�ļ�����SeqQueue.c
//����Ҫ����б������Ѵ��ڵģ����򷵻�-1
int GetQueueLength(SeqQueue *pQ)
{
    int length;
    if (pQ== NULL) return -1;
    //ѭ�������У�rear��ֵ�п��ܻ�С��front����Ҫ�Ӹ�MAXQSIZE����ȡ��
    length= (pQ->rear-pQ->front+MAXQSIZE)%MAXQSIZE;
    return length;
}

//����3. ---------˳��ṹ�µ�"��ȡ��ͷԪ�ص�ֵ"�����㷨����---------//
//�ļ�����SeqQueue.c
//����Ϊ�ջ��߶��в����ڣ�������-1�����򽫶�ͷԪ�ص�ֵ�洢����ַΪpe�Ŀռ��У�������0
int GetHead(SeqQueue *pQ,QElemType *pe)
{
    if (pQ== NULL) return -1;
    /* �����в���,����e����Q�Ķ�ͷԪ��,������0,���򷵻�-1 */
    if(pQ->front==pQ->rear) /* ���п� */
        return -1;
    *pe=pQ->base[pQ->front];
    return 0;
}

//����3. ---------˳��ṹ�µ�"������"�����㷨����---------//
//�ļ�����SeqQueue.c
//���в����ڣ�����-1��������������-2���������ӷ���0
//ע���ʱ����Ԫ������ͨ��ֵ���ݷ�ʽ	
int EnQueue(SeqQueue *pQ, QElemType e)
{
    if (pQ== NULL) return -1;
    if((pQ->rear+1)%MAXQSIZE==pQ->front) //��������������������磬��������
        return -2;
    pQ->base[pQ->rear]=e;                //����ֵ��ע�⣬����к�front�޹�
    pQ->rear=(pQ->rear+1)%MAXQSIZE;      //��ѭ����1
    return 0;
}

//����3. ---------˳��ṹ�µ�"������"�����㷨����---------//
//�ļ�����SeqQueue.c
//���в����ڣ�����-1�����пգ�����-2���������ӷ���0
//ע���ʱ����Ԫ��pe���õ��ǲ����ĵ�ַ���ݷ�ʽ	
int DeQueue(SeqQueue *pQ,QElemType *pe)
{
    if (pQ== NULL) return -1;
    if(pQ->front==pQ->rear)              //�������Ϊ�գ�ֱ�ӷ�������
        return -2;
    *pe=pQ->base[pQ->front];             //�ȶ�ֵ�������в�����rear�޹�
    pQ->front=(pQ->front+1)%MAXQSIZE;    //��ѭ����1
    return 0;
}

int main()
{
    SeqQueue *pQ;
    InitQueue(&pQ);
	DestroyQueue(&pQ);
	return 0;
}