#include <stdio.h>
#include <stdlib.h>

//����ͳ��Ҷ�ӽڵ����Ŀ 
void leaf(BiTree *T)
{
	int count = 0;
	
    if(T)
	{
    	if(T->lchild==NULL&&T->rchild==NULL) 
		 	count++;
     	leaf(T->lchild);
     	leaf(T->rchild); 
	}
	else
		return count;
}

//��������洢�Ķ����������(�߶�)
struct BTreeNode
{ 
	elemtype data; 
	struct BTreeNode *lchild; 
	struct BTreeNode *rchild;
};

int hight(BTreeNode *T)
{ 
	int h1 = 0, h2 = 0, h = 0;
	if (T==null) 
		return(0); 
	else
	{ 
		h1=hight(T->lchild); 
		h2=hight(T->rchild); 
		if(h1>=h2) 
			h=h1+1;
		else 
			h=h2+1;
			 
		return h;
	}
}

// ��������ǰ����� 
void visit(char c)
{
	printf("%c",c);
}
 
void PreOrderTraverse(BiTree *T)
{
	if(T)
	{
		visit(T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

// ��������������� 
void InOrderTraverse(BiTree *T)
{
	if(T)
	{
		InOrderTraverse(T->lchild);
		visit(T->data);
		InOrderTraverse(T->rchild); 	
	}
}

// �������ĺ������ 
void PostOrderTraverse(BiTree *T)
{
	if(T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		visit(T->data);
	}
}

//��һ�ö������н���������㷨��
int count(btNode *T)
{
	int num = 0;
	int m = 0, n = 0;
	if(T)
	{
		m=count(T->lchild);
		n=count(T->rchild);
		num=m+n+1;
	}
	    
	return num;
}


