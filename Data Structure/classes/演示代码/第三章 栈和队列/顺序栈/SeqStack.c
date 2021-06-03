/*
 *  �ļ�����SeqStack.c
 *	˳��ջ��ʵ��
 *	�汾��1.0
 *	ʱ�䣺2016.09.26
 *	���ߣ�wangx
 *	�ٶ������� ����Ԫ�صĻ�������Ϊ�ṹ������Node���ں�3������int��Ա
 *			
*/


#include "stdio.h"   //��Ҫ��Ϊ���ܹ�ʹ��printf��scanf
#include "malloc.h"  //Ϊ����ʹ��malloc����

#define PARAM_ERROR -1
#define MALLOC_ERROR -2
#define STACK_INIT_SIZE 100 //˳��ջ��ʼ�����Ԫ�ظ�����������NodeΪ��λ��Ŷ��
#define STACKINCREMENT 20   //�洢�ռ��������(��������ʱ���ӷ����Ԫ�ظ���)

 typedef struct Node
 {
   int ii; 
   int jj; 
   int kk; 
 }Node; //ջ��ÿ��Ԫ�ص��������ͣ�ͬѧ�ǿ���˼��һ�£����֧�ֶ�ָ�����͵�ѹջ�ͳ�ջ

 //������һ�������͡�˳��ջ������ռ�ڴ�
 typedef struct SeqStack
 {
   Node *Base; // ջ��ָ�룬��־��һ��˳��ջ�Ƿ���ڡ���ջ����֮ǰ������֮��Base��ֵΪNULL
   Node *Top;  // ջ��ָ�룬ָ��ǰ��ջ��Ԫ�أ��洢��ǰջ��Ԫ�ص��׵�ַ��
   int stacksize; //��ǰ�ܴ洢�����Ԫ�ظ�����������NodeΪ��λ
 }SeqStack; 

 /* ����һ���յ�˳��ջ�ṹ������ʵ��ָ��ָ��ýṹ */
int InitStack(SeqStack **ppStack)
{ 
	*ppStack= (SeqStack *)malloc( sizeof(SeqStack) );
	if (*ppStack == NULL)
		return MALLOC_ERROR;
	(*ppStack)->Base=(Node *)malloc( STACK_INIT_SIZE * sizeof(Node) );
	if(!(*ppStack)->Base)
	{
		free(*ppStack);  //��ջ�ṹ�ͷ���
		return MALLOC_ERROR;
	}
	(*ppStack)->Top = (*ppStack)->Base;
	(*ppStack)->stacksize = STACK_INIT_SIZE;
	return 0;
}

/* ����˳��ջ��*ppStackָ���ջ�ṹ����������Լ�˳���ŵ��������򶼲��ٴ��� */
int DestroyStack(SeqStack **ppStack)
{
	//����У�飬Ҫ���٣���Ҫ��ջ��������
	if (*ppStack == NULL)
		return PARAM_ERROR;

	if ((*ppStack)->Base != NULL) //���if����һ����˵�Ƿϻ�����ջ�Ļ���Baseָ��һ�㲻���ܻ�ΪNULL��
								  //����û���дһ�£����׵㣬��׳�㡣һ�����free���ͷ��κοռ�֮ǰ��������ж�һ�¡�
		free((*ppStack)->Base);
	(*ppStack)->Base=NULL;
	(*ppStack)->Top=NULL;
	(*ppStack)->stacksize=0;
   return 0;
}

// ��pStackָ���ջ�ṹ����Ϊ��ջ��ֻ��Ҫ����Topָ�뼴�ɣ������������
int ClearStack(SeqStack *pStack)
{ 
	if (pStack == NULL)
		return PARAM_ERROR;

	pStack->Top = pStack->Base;
	return 0;
}

// ��ջSΪ��ջ���򷵻�1�����򷵻�0 
int IsStackEmpty(SeqStack *pStack)
{
	if (pStack == NULL)
		return PARAM_ERROR;

   if(pStack->Top==pStack->Base)
     return 1;
   else
     return 0;
 }

// ����S��Ԫ�ظ�������ջ�ĳ���
int StackLength(SeqStack *pStack)
{
	if (pStack == NULL)
		return PARAM_ERROR;

	return pStack->Top - pStack->Base;  //���ǵ�����ָ��������ʲô��˼ô�������Ƕ�ָ��ͬһ���ڴ������еĲ�ͬԪ��ʱ
}

//��Ԫ��ѹջ
 int Push(SeqStack *pStack, Node Value)
 { 
	if(pStack->Top - pStack->Base >= pStack->stacksize) //ջ����׷�Ӵ洢�ռ�
	{
		pStack->Base=(Node *)realloc( pStack->Base, (pStack->stacksize+STACKINCREMENT)*sizeof(Node) );
		if(pStack->Base == NULL)
			return MALLOC_ERROR; 
		pStack->Top = pStack->Base + pStack->stacksize;
		pStack->stacksize += STACKINCREMENT;
	}
	//�����Ǽٶ��ȴ洢��Ȼ��ָ����ǰ���������ں����ĳ�ջ�����оͱ���Ҫ�Ⱥ��ˣ��ٶ�ȡ
	pStack->Top->ii=Value.ii; 
	pStack->Top->jj=Value.jj;
	pStack->Top->kk=Value.kk;
	pStack->Top++;
	return 0;
}

//��ջ������ջ��Ԫ�ص�ֵ��ȡ��������������ʹ��
//��ջ���գ��򵯳����߼��϶��ԣ�ջ��ջ��Ԫ�أ���*pValue�洢��ֵ��������0�����򷵻�-1
int Pop(SeqStack *pStack, Node *pValue)
{ 
	if(pStack->Top==pStack->Base || pValue==NULL)
		return PARAM_ERROR;

	pStack->Top--; //Topָ�����һ��
	pValue->ii=pStack->Top->ii; 
	pValue->jj=pStack->Top->jj;
	pValue->kk=pStack->Top->kk;
	return 0;
}

int main()
{
	Node value;
	SeqStack *pStack;
	InitStack(&pStack);
	value.ii= 10;
	value.jj= 11;
	value.kk= 12;
	Push(pStack, value);
	value.ii= 20;
	value.jj= 21;
	value.kk= 22;
	Push(pStack, value);
	value.ii= 30;
	value.jj= 31;
	value.kk= 32;
	Push(pStack, value);
	value.ii= 40;
	value.jj= 41;
	value.kk= 42;
	Push(pStack, value);
//	DestroyStack(&pStack);

	while (!IsStackEmpty(pStack))
	{
		Pop(pStack, &value);
		printf("%d  %d   %d\n", value.ii, value.jj, value.kk);
	}
	DestroyStack(&pStack);
	return 0;
}