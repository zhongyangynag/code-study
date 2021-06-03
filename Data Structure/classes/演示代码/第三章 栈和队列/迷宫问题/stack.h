#include "stdio.h"   //��Ҫ��Ϊ���ܹ�ʹ��printf��scanf
#include "malloc.h"  //Ϊ����ʹ��malloc����

/*  ջ��˳��洢��ʾ */
 #define STACK_INIT_SIZE 100 /* �洢�ռ��ʼ������ */
 #define STACKINCREMENT 20 /* �洢�ռ�������� */
 typedef struct Node
 {
   int ii; 
   int jj; 
   int kk; 
 }Node; /*  */

 typedef struct SqStack
 {
   Node *base; /* ��ջ����֮ǰ������֮��base��ֵΪNULL */
   Node *top; /* ջ��ָ�� */
   int stacksize; /* ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ */
 }SqStack; /* ˳��ջ */

 /* ˳��ջ�Ļ����������Թ�����δʹ�õĺ�����ע�͵��� */
 int InitStack(SqStack *S)
 { /* ����һ����ջS */
   (*S).base=(Node *)malloc(STACK_INIT_SIZE*sizeof(Node));
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
/*
 int ClearStack(SqStack *S)
 { // ��S��Ϊ��ջ 
   (*S).top=(*S).base;
   return 0;
 }
*/
 int StackIsEmpty(SqStack S)
 { /* ��ջSΪ��ջ���򷵻�1�����򷵻�0 */
   if(S.top==S.base)
     return 1;
   else
     return 0;
 }
/*
 int StackLength(SqStack S)
 { // ����S��Ԫ�ظ�������ջ�ĳ���
   return S.top-S.base;
 }
*/

 int Push(SqStack *S,int i, int j, int k)
 { /* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
   if((*S).top-(*S).base>=(*S).stacksize) /* ջ����׷�Ӵ洢�ռ� */
   {
     (*S).base=(Node *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(Node));
     if(!(*S).base)
       return -1; /* �洢����ʧ�� */
     (*S).top=(*S).base+(*S).stacksize;
     (*S).stacksize+=STACKINCREMENT;
   }
   (*S).top->ii=i;
   (*S).top->jj=j;
   (*S).top->kk=k;
	(*S).top++;
   return 0;
 }

 int Pop(SqStack *S, int *i, int *j, int *k)
 { /* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������0�����򷵻�-1 */
   if((*S).top==(*S).base)
     return -1;
   --(*S).top;
   *i=(*S).top->ii;
   *j=(*S).top->jj;
   *k=(*S).top->kk;
   return 0;
 }

