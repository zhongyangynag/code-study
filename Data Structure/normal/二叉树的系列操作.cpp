#include<stdio.h>
#include<stdlib.h>

//��������ϵ�в���

//�������Ĵ���ṹ
typedef int Datatype;
typedef struct node{
	struct node *LChild;                               //��ָ����
	Datatype data;
	struct node *RChile;                               //��ָ���� 
}BTNode;

//����������
BTNode *createBTree()
{
	BTNode *bt = NULL;
	int elem;
	scanf("%d",&elem);
	if(elem != -1)                      //����Ϊ�գ�����һ������� 
	{
		bt = (BTNode *)malloc(sizeof(BTNode));
		if(bt == NULL)
		{
			printf("�ڴ����ʧ��!\n");
			exit(1);
		}
		bt->data = elem;
		bt->LChild = createBTree()      //����������
		bt->RChile = createBTree()      //���������� 
	}
	
	return bt; 
}

//�������
void preOrder(BTNode *root)
{
	if(root != BULL)
	{
		printf("%d",root->data);
		preOrder(root->LChild);
		preOreder(root->RChile);	
	}	
} 

//�������
void midOrder(BTNode *root)
{
	if(root != BULL)
	{
		midOrder(root->LChild);
		printf("%d",root->data);
		midOreder(root->RChile);	
	}	
} 

//�������
void postOrder(BTNode *root)
{
	if(root != BULL)
	{
		postOrder(root->LChild);
		postOreder(root->RChile);	
		printf("%d",root->data);
	}	
} 

//��α���
void layerOrder(BTNode *root) 
{
	BTNode *t;
	SeqOueue btQueue;              //����˳�����
	initQueue(&btQueue);           //��ʼ��
	if(root != NULL)
	{
		InsQueue(&btQueue, *root);        //�������������ڵ㲻�գ�������� 
		while( !isEmpty(btQueue) )
		{
			t = outQueue(&btQueue);    //ȡ��ͷԪ��
			printf("%d",t->data);
			if(t->LChild != NULL)
			{
				InsQueue(&btQueue, t->LChild);           //�����ǰ�ڵ������������������ 
			}	
			if(t->RChild != NULL)
			{
				InsQueue(&btQueue, t->RChild);           //�����ǰ�ڵ������������������ 
			}	
		} 
	} 
}

//���ҽڵ�
BTNode *searchBTree(BTNode *root, Datatype elem)
{
	BTNode *t;
	if(root == NULL)                                  //����Ҹ��ڵ� 
	{
		return NULL;
	}
	if(root->data == elem)
	{
		return root;
	}
	else
	{
		t = searchBTree(root->LChild, elem);         //�������� 
		if(t != NULL)
		{
			return t;
		}
		else
		{
			return searchBTree(root->RChile, elem); //�������� 
		}
	}
}

//������������
//��������ȵ���������������������ȵ����ֵ��1 
int getDepth(BTNode *root)
{
	int LDep,RDep;
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		LDep = getDepth(root->LChild);
		RDep = getDepth(root->RChile); 
	}
}


 




















