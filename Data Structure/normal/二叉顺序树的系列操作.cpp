#include<stdio.h>
#include<stdlib.h>

//����������ϵ�в���

//�����������Ľ�����Ͷ���
typedef int Datatype;
typedef struct node{
	struct node *LChild;
	Datatype data;
	struct node *RChild;
}BSTNode;

//�������Ĳ���
BSTNode *insertBSTree(BSTNode *root, Datatype elem)
{
	BSTNode *t;
	if(root == NULL)
	{
		t = (BSTNode *)malloc(sizeof(BSTNode));
		t->data = elem;
		t->LChild = NULL;
		t->RChild = NULL;
	}
	else if(elem < root->data)
	{
		if(root->LChild == NULL)
		{
			t = (BSTNode *)malloc(sizeof(BSTNode));
			t->data = elem;
			t->LChild = NULL;
			t->RChild = NULL;
			root->LChild = t;
		}
		else
		{
			t = insertBSTree(root->LChild, elem);
		}
	}
	else if(elem > root->data)
	{
		if(root->RChild == NULL)
		{
			t = (BSTNode *)malloc(sizeof(BSTNode));
			t->data = elem;
			t->LChild = NULL;
			t->RChild = NULL;
			root->RChild = t;
		}
		else
		{
			t = insertBSTree(root->RChild, elem);
		}
	}
	
	return t;
}

//�����������Ľ���
BSTNode *createBSTree()
{
	int elem;
	BSTNode *root = NULL;
	scanf("%d", &elem);
	
	while(elem != -1)
	{
		if(root == NULL)
		{
			root == insertBSTree(root, elem);
		}
		else
		{
			insertBSTree(root, elem);
		}
		scanf("%d", elem);
	}	
	
	return root;
} 

//�������Ĳ���
BSTNode *searchBSTree(BSTNode *root, Datatype elem) 
{
	if(root == NULL)
	{
		return NULL;
	}
	else if(elem == root->data)
	{
		return root->data;
	}
	else if(elem < root->data)
	{
		return searchBSTree(root->LChild, elem);
	}
	else if(elem > root->data)
	{
		return searchBSTree(root->RChild, elem);
	}
}

//��������ɾ�� 
BSTNode *delBSTree(BSTNode *root, Datatype elem) 
{
	BSTNode *f = NULL, *c = root, *fp, *p;
	while( c->data != elem )                        //���Ҵ�ɾ���Ľ��c, fΪ�丸���
	{
		if( elem < c->data )
		{
			f = c;
			c = c->LChild; 
		}
		else
		{
			f = c;
			c = c->RChild;
		}
	}
	if( NULL == c->RChild )                        //���cû���Һ���
	{
		if( NULL == f)                             //���c�Ǹ����	
		{
			c = c->LChild;
			free( root );
			return C;

		}	
		else                                      //���c���Ǹ����
		{
			if( c->data < f->data )
				f->LchiId = c->LChild;
			else
				f->RChila = c->LChild;
			free( c );
		}
	}
	else if( NULL == c->LChild )                  //���cû������
	{
		if( NULL = f)                            //���c�Ǹ����
		{
			c = c->RChild;
			free( root );
			return c;
		}
		else                                     //���c���Ǹ����
		{
			if( c->data < f->data )
				f->LchiId = c->RChild;
			else
				f->RChila = c->RChild;
			free( c );
		}
	}
	else
	{
		fp = c;
		p = c->LChild;
		
		while(p->RChild != NULL)              //���ҽ��c��ǰ��p��fp��p��˫�׽�� 
		{
			fp = p;
			p = p->RChild; 
		}
		if(fp == c)                           //c������ǰ���������� 
		{
			fp->data = p->data;
			fp->LChild = p->LChild;
			free(p);
		}
		else                                  //c������ǰ�������Һ���
		{
			c->data = p->data;
			fp->RChild = p->LChild;
			free(p);
		}
	}
	
	return root;
}
























 

