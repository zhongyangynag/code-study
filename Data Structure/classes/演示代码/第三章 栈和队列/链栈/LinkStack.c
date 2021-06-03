/*
 *  �ļ�����LinkStack.c
 *	��ջ��ʵ��
 *	�汾��1.0
 *	ʱ�䣺2016.09.26
 *	���ߣ�wangx
 *	�ٶ������� ����Ԫ�صĻ�������Ϊint����ÿ��Ԫ��ֻ��һ��������Ϣ��Ҫѹջ
 *			
*/

#include "malloc.h" 
#include "stdio.h"

#define PARAM_ERROR -1
#define MALLOC_ERROR -2

typedef  int TElemType;
typedef struct SNode
{
	TElemType data;
   struct SNode *next;
}StackNode;

typedef struct 
{
	StackNode *Top; //һ��ָ�룬ָ��ջ�����
}LinkStack, *PLinkStack; //PLinkStack�Ƕ���ָ�룬��Ч��LinkStack *
//�˴�������һ����ջ���ͣ���LinkStack���ýṹֻ��һ�����ݳ�Ա����һ��ָ��ջ������ָ��Top
//��Ϊ��ջ�в����ñ�ͷ��㣬Ҳ����Ҫջ��ָ�룬����ֻ��һ��Topָ�������ָ��ջ��Ԫ�ؼ��ɡ�ͬѧ�ǿ����������ջ������������Ϣ������ṹ���棬����ջ�ĵ�ǰ���֮���

 //��ʼ����ջ��ֻ��Ҫ��Topָ���ÿռ���
 //�Ӻ����ڸı�Topָ���ֵ�����β�Ϊ����ָ��
int InitStack(LinkStack **ppStack)
{
   if (*ppStack== NULL) //����У�飬�ö���ָ�����Ҫָ�����������е�һ��LinkStack *���͵�ָ����������ö���ָ��ָ��Ķ���������ڣ�
		return PARAM_ERROR;

	*ppStack= (LinkStack*)malloc(sizeof(LinkStack));
	(*ppStack)->Top= NULL;
	return 0;
}

int ClearStack(LinkStack *pStack)
{
	StackNode *pTemp, *pNext;

	if (pStack== NULL)
		return PARAM_ERROR; //ջ��������ڣ����ش����롣ע�⣬��ջ��״̬������ģ�������pStack->Top==NULL

	pTemp= pStack->Top;
	while(pTemp!= NULL)
	{
		pNext= pTemp->next; 
		free(pTemp);
		pTemp= pNext;
	}
	return 0;
}

//��Ϊ��ջ�ޱ�ͷ��������պ����ٲ�����ͬ���Ĳ���
int DestroyStack(LinkStack **ppStack)
{
   if (*ppStack== NULL)
		return PARAM_ERROR; //ջ��������ڣ����ش����롣ע�⣬��ջ��״̬������ģ�������pStack->Top==NULL

	ClearStack(*ppStack);
	free(*ppStack);
	*ppStack= NULL;
	return 0;
}

int Push(LinkStack *pStack, TElemType Value)
 {
   StackNode *p;
   if (pStack== NULL)
		return PARAM_ERROR; //ջ��������ڣ����ش����롣ע�⣬��ջ��״̬������ģ�������pStack->Top==NULL
   p=(StackNode *)malloc(sizeof(StackNode));
   if(!p)
     return MALLOC_ERROR;
   p->data=Value;
   //ͷ�巨��ջ
   p->next=pStack->Top;  
   pStack->Top=p;
   
   return 0;
 }

int Pop(LinkStack *pStack, TElemType *pValue)
{
	StackNode *p;
	if (pStack== NULL || pStack->Top == NULL || pValue==NULL) 
		return PARAM_ERROR; //��ջ�����ݿɷ��أ����ش�����
	p= pStack->Top;  //��ʱָ��ָ��ջ�����
	pStack->Top= pStack->Top->next;  //����ջ��ָ�룬ָ����һ����㣨��ջ�����ջ����㣩

	*pValue= p->data;  //��ԭջ����������ֵȡ�������ظ���������ʹ��
	free(p);  //����ԭջ�����
	p=NULL;
	return 0;
}

//�ж�һ��ջ�Ƿ�Ϊ��ջ
int IsStackEmpty(LinkStack *pStack)
{
	if (pStack==NULL) //����У��
		return PARAM_ERROR;

	if (pStack->Top == NULL) //����ǿ�ջ
		return 1;  //��ջ����1
	else
		return 0;

}

int main()
{
	TElemType value;
	LinkStack *pStack;
	InitStack(&pStack);
	Push(pStack, 10);
	Push(pStack, 20);
	Push(pStack, 30);
	Push(pStack, 40);
//	DestroyStack(&pStack);

	while (!IsStackEmpty(pStack))
	{
		Pop(pStack, &value);
		printf("%d  ", value);
	}
	DestroyStack(&pStack);
	return 0;
}