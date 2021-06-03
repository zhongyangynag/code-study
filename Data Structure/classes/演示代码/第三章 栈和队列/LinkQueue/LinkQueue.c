/*
 *  �ļ�����LinkQueue.c
 *	�����е�ʵ��
 *	�汾��1.0
 *	ʱ�䣺2016.06.26
 *	���ߣ�wangx
 *	�ٶ������� ����Ԫ�صĻ�������Ϊint����
 *			
*/

//������
#include "stdio.h"
#include "malloc.h"
 
typedef int QElemType;         //�������Ԫ������Ϊint�����߿ɸ���Ϊ��������

typedef struct QNode          //���嵥������Ľ��������ΪQNode��������ָ��
{                             //�������͵�ָ�����������ΪQueuePtr
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;
/*����ͷָ��Ͷ�βָ������װ��������µĽṹ�����ͣ�
  �������е��������ͣ�ȡ��ΪLinkQueue
*/
typedef struct                
{
    QueuePtr front;           // ��ͷָ��
    QueuePtr rear;            // ��βָ��
}LinkQueue;

//����3. ---------�����еĴ����ͳ�ʼ������---------//
//�ļ�����LinkQueue.c
//��ָ��LinkQueue�ṹ��Ķ���ָ��ppQΪ�������ں����ڹ���B��C���֣�ʵ�ֹ���
int InitQueue(LinkQueue **ppQ)
{ 
    (*ppQ)=(LinkQueue *)malloc(sizeof(LinkQueue));
    if(!(*ppQ))  return -1;
    (*ppQ)->front=(*ppQ)->rear=(QueuePtr)malloc(sizeof(QNode));
    if(!(*ppQ)->front)  return -2;
    (*ppQ)->front->next=NULL;
    return 0;
}

//����3. ---------�����еġ��ж��Ƿ�Ϊ�ա�����---------//
//�ļ�����LinkQueue.c
//��ָ��LinkQueue�ṹ���һ��ָ��pQΪ����
// ����������󣬷���-1; ��QΪ�ն���,�򷵻�1,���򷵻�0 
int QueueIsEmpty(LinkQueue *pQ)
{ 
    if (pQ==NULL) return -1;
    if(pQ->front==pQ->rear)
        return 1;
    else
        return 0;
}

//����3. ---------�����еġ���ȡ��ͷԪ�ء�����---------//
//�ļ�����LinkQueue.c
//��ָ��LinkQueue�ṹ���һ��ָ��pQΪ����
// ������д����ҷǿգ���ȡ��ͷԪ�ص�ֵ���Ե�ַ���ݵķ�ʽͨ��e����������������󣬷���-1;  
int GetQueueHead(LinkQueue *pQ,QElemType *e)
{
    if(QueueIsEmpty(pQ)!=0)
        return -1;
    *e=pQ->front->next->data;
    return 0;
}

//����3. ---------�����еġ�����С�����---------//
//�ļ�����LinkQueue.c
//��ָ��LinkQueue�ṹ���һ��ָ��pQΪ����
// ������в����ڻ�����쳣�����ظ���; ��֮���ɹ���������0  
int EnQueue(LinkQueue *pQ,QElemType e)
{ 
    QueuePtr R;
    if (pQ==NULL) return -1;
    // Ϊ�½�Ԫ��e������ռ䣬����ָ��Rָ�� 
    R=(QueuePtr)malloc(sizeof(QNode));
    if(!R) return -2;          //�ڴ�����ʧ�ܣ�����-2
    R->data=e;
    R->next=NULL;
    //������ӵ�ָ�����
    pQ->rear->next=R;
    pQ->rear=R;
    return 0;
}

//����3. ---------�����еġ������С�����---------//
//�ļ�����LinkQueue.c
//��ָ��LinkQueue�ṹ���һ��ָ��pQΪ����������peΪ��ַ������ʽ
//����ͷԪ����ָ��e���أ�����ΨһԪ�أ������rearָ��
//������в����ڻ����Ϊ�գ�����-1; ��֮���ɹ���������0  
int DeQueue(LinkQueue *pQ,QElemType *pe)
{
    QueuePtr R;
    if (pQ==NULL) return -1;            //���в����ڣ�����-1
    if(pQ->front==pQ->rear) return -2;  //����Ϊ�գ�����-2
        
    R=pQ->front->next;			        //��Rָ���ͷ��ĵ�һ�����
    *pe=R->data;
    pQ->front->next=R->next;
    if(pQ->rear==R)                     //�����һ�����Ҳ�����һ�����
        pQ->rear=pQ->front;
    free(R);
    return 0;
}

//����3. ---------�����еġ�����г��ȡ�����---------//
//�ļ�����LinkQueue.c
//��ָ��LinkQueue�ṹ���һ��ָ��pQΪ����
int GetQueueLength(LinkQueue *pQ)
{
    QueuePtr p;
    int count=0;
    p=pQ->front;
    while(p!=pQ->rear)
    {
        count++;
        p=p->next;
    }
    return count;
}

//����3. ---------�����еġ���ն��С�����---------//
//�ļ�����LinkQueue.c
//��ָ��LinkQueue�ṹ���һ��ָ��pQΪ����
//��պ�front��rearָ���ָ���ͷ���
int ClearQueue(LinkQueue *pQ)
{ /* ��Q��Ϊ�ն��� */
    QueuePtr p,q;
	if (pQ==NULL) return -1;
    pQ->rear=pQ->front;    //rearָ���λ
    p=pQ->front->next;     //pָ��ָ����е�һ�����ݽ��
    pQ->front->next=NULL;  //��ͷ����next���λ
    while(p!=NULL)         //ѭ���ͷ�ÿ�����ݽ��Ŀռ�
    {
        q=p;
        p=p->next;
        free(q);
    }
    return 0;
}


//����3. ---------�����е����ٲ���---------//
//�ļ�����LinkQueue.c
//��ָ��LinkQueue�ṹ��Ķ���ָ��ppQΪ����
//�ں���������ն������ݣ�Ȼ�����ٿն��е�B��C���֣�����λ����ָ��
int DestroyQueue(LinkQueue **ppQ)
{ 
    if (ClearQueue(*ppQ)==-1) return -1;
    free((*ppQ)->front);
    free(*ppQ);
    ppQ= NULL;
    return 0;
}


int main()
{
	LinkQueue *pQ= NULL;
	InitQueue(&pQ);
	return 0;
}



