 /*  ջ��˳��洢��ʾ */
#include "stdio.h"

 #define STACK_INIT_SIZE 100 /* �洢�ռ��ʼ������ */
 #define STACKINCREMENT 20 /* �洢�ռ�������� */
 typedef struct SqStack
 {
   int *base; /* ��ջ����֮ǰ������֮��base��ֵΪNULL */
   int *top; /* ջ��ָ�� */
   int stacksize; /* ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ */
 }SqStack; /* ˳��ջ */
 
/*  ˳��ջ�Ļ���������8���� */
 int InitStack(SqStack *S)
 { /* ����һ����ջS */
   (*S).base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
   if(!(*S).base)
     return -1; /* �洢����ʧ�� */
   (*S).top=(*S).base;
   (*S).stacksize=STACK_INIT_SIZE;
   return 0;
 }

 int DestroyStack(SqStack *S)
 { /* ����ջS��S���ٴ��� */
   free((*S).base);
   (*S).base=NULL;
   (*S).top=NULL;
   (*S).stacksize=0;
   return 0;
 }

 int ClearStack(SqStack *S)
 { /* ��S��Ϊ��ջ */
   (*S).top=(*S).base;
   return 0;
 }

 int StackIsEmpty(SqStack *S)
 { /* ��ջSΪ��ջ���򷵻�1�����򷵻�0 */
   if(S->top==S->base)
     return 1;
   else
     return 0;
 }

 int StackLength(SqStack S)
 { /* ����S��Ԫ�ظ�������ջ�ĳ��� */
   return S.top-S.base;
 }

 int GetTop(SqStack S,int *e)
 { /* ��ջ���գ�����e����S��ջ��Ԫ�أ�������0�����򷵻�-1 */
   if(S.top>S.base)
   {
     *e=*(S.top-1);
     return 0;
   }
   else
     return -1;
 }

 int Push(SqStack *S,int e)
 { /* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
   if((*S).top-(*S).base>=(*S).stacksize) /* ջ����׷�Ӵ洢�ռ� */
   {
     (*S).base=(int *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(int));
     if(!(*S).base)
       return -1; /* �洢����ʧ�� */
     (*S).top=(*S).base+(*S).stacksize;
     (*S).stacksize+=STACKINCREMENT;
   }
   *((*S).top)++=e;
   return 0;
 }

 int Pop(SqStack *S,int *e)
 { /* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������0�����򷵻�-1 */
   if((*S).top==(*S).base)
     return -1;
   *e=*--(*S).top;
   return 0;
 }

