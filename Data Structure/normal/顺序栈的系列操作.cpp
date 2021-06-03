#include<stdio.h>
#include<stdlib.h>

//˳��ջ��ϵ�в���
#define MaxSize 200
typedef int Datatype;

//ջ�Ķ��� 
typedef struct{
	Datatype stack[MaxSize];                        
	int top;                                        //ջ��ָ�� 
}SeqStack;

//ջ�ĳ�ʼ��
void initStack(SeqStack *s)
{
	s->top = -1;	
} 

//���ջ 
void clearStack(SeqStack *s)
{
	s->top = -1;
}

//��ȡջ��Ԫ��
void getTop(SeqStack *s) 
{
	if(s->top == -1)
	{
		printf("ջ��!\n");
		exit(1);
	}
	else
	{
		printf("%d\n",s->stack[s->top]);
	}
}

//���ջ�Ƿ�Ϊ��
int isEmpty(SeqStack *s) 
{
	return (s->top == -1);
}

//��ջ
void push(SeqStack *s, Datatype elem)
{
	if(s->top == MaxSize-1)
	{
		printf("ջ�����!\n");
		exit(1);
	}
	s->top++;
	s->stack[s->top] = elem;
} 

//��ջ
void pop(SeqStack *s) 
{
	if(s->top == -1)
	{
		printf("ջ��!\n");
		exit(0);
	}
	printf("%d",s->stack[s->top]);
	s->top--;
}

//���Դ���
int main()
{
	SeqStack s;
	initStack(&s);
	
	push(&s, 3);
	pop(&s);
	push(&s, 5);
	
} 
