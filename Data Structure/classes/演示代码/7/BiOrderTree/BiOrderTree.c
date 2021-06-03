//����7.2--------- �����������Ķ���������ṹ���� ---------//
//�ļ�����BiOrderTree.c����1���֣���7���֣�
// ��typedef����һ���µĽṹ�����ͣ�ȡ��ΪBiTNode����ָ��ýṹ�����͵�ָ������ͣ�ȡ��BiTree����
#include "stdio.h"
#include "malloc.h"
#define  ENDKey  -1         //����������������ר�ñ���������-1��ʾ�������

typedef struct  BSTNode
{
    int  Key ; 
    struct BSTNode  *Lch,*Rch;
}BSTNode, *BSTree;

//����7.3--------- �ݹ�Ķ��������������㷨 ---------//
//�ļ�����BiOrderTree.c����2���֣���7���֣�
// ��bstָ����ָ��Ķ���������������ֵΪKey�Ľ�㣬������ҳɹ����������ظý��ĵ�ַ��
// �������ʧ�ܣ���������NULL������preָ�뷵�ز��Ҹ�Ԫ��ʱ�ڶ����������о��������һ����㡣
BSTNode *SearchBST(BSTree bst, int Key, BSTNode **pre)
{
	if (!bst){
		return NULL;
	}
	else if (Key == bst->Key) 
			return bst;
	else if (Key <  bst->Key) {
			if (pre!= NULL)	*pre= bst;
			return SearchBST(bst->Lch, Key, pre);
			}
	else {	
			if (pre!= NULL)	*pre= bst;
	    	return SearchBST(bst->Rch, Key, pre);
	}
}

//����7.4--------- �ǵݹ�Ķ��������������㷨 ---------//
//�ļ�����BiOrderTree.c����3���֣���7���֣�
// ��bstָ����ָ��Ķ���������������ֵΪKey�Ľ�㣬������ҳɹ����������ظý��ĵ�ַ��
// �������ʧ�ܣ���������NULL������preָ�뷵�ز��Ҹ�Ԫ��ʱ�ڶ����������о��������һ����㡣
BSTNode *N_SearchBST(BSTree bst, int K, BSTNode **pre)
{
	BSTree p;

	if (bst== NULL)
		return NULL;

	p=bst;
	while(p)
	{   
		if(K==p->Key)     //�������ҵ�ֵ��ͬ��Ԫ��
		{
			return p;
		}
        else 
			if(K<p->Key)
		{
			if (pre!=NULL) *pre=p;
			p=p->Lch;
		}
        else 
		{
			if (pre!=NULL) *pre=p;
			p=p->Rch;
		}
	}
	return NULL;
}

//����7.5 --------- �����������Ĳ����㷨 --------- //
//�ļ�����BiOrderTree.c����4���֣���7���֣�
//bstΪָ����������������Ķ���ָ�룻kΪҪ����Ľ���ֵ
//����ɹ�����������0,������ʧ�ܣ���������-1���������Ѵ��ڽ��kʱ�����ʧ�ܣ�
int InsertBST(BSTree *bst, int k)
{ 
	BSTree r,pre;	
	
	r=(BSTree)malloc(sizeof(BSTNode));
	r->Key=k;
	r->Lch=NULL; 
	r->Rch=NULL;
	if (*bst == NULL)
	{
		*bst=r;
		return 1;
	}
	pre= NULL;
    if (!SearchBST(*bst, k, &pre)){
		//û���ҵ�ֵ��ͬ��Ԫ�أ�������ҵ������һ��Ԫ�������������
		if(k<pre->Key)
			pre->Lch=r;
		else 
			pre->Rch=r;
		return 0;	
	}
	else
		return -1;
}

//����7.6 --------- �����������Ĵ����㷨 --------- //
//�ļ�����BiOrderTree.c����5���֣���7���֣�
//bstΪָ����������������Ķ���ָ��
void  CreateBST(BSTree  *bst)
{ 
	int Key;
	*bst=NULL;
	scanf("%d", &Key);
	while (Key!=ENDKey)   
	{
		InsertBST(bst, Key);
		scanf("%d", &Key);
	}
	getchar();
}

void  InOrder(BSTree root) 
{
	if (root!=NULL)
	{
		  
		InOrder(root->Lch);
		printf("%d ",root->Key);  
		InOrder(root->Rch);  
	}
}

//����7.7 --------- ������������ɾ����������㷨 --------- //
//�ļ�����BiOrderTree.c����6���֣���7���֣�
//��֪����ַp���ڶ�����������ɾ���ý��
int DeleteByVexAddr(BSTNode **p)
{
	BSTNode *q, *s;
	if ((*p)->Rch==NULL){
		q= *p;
		*p= (*p)->Lch;
		free(q);
	}
	else if ((*p)->Lch==NULL){
		q= *p;
		*p= (*p)->Rch;
		free(q);
	}
	else{
		q=*p;
		s=(*p)->Lch;
		while(s->Rch){
			q=s; s=s->Rch;
		}
		(*p)->Key= s->Key;
		if (q!= *p)
			q->Rch= s->Lch;
		else
			q->Lch= s->Lch;
		free(s);
	}
	return 0;
}

//����7.8---------�ݹ�ʵ�ֵĶ�����������ɾ����������---------//
//�ļ�����BiOrderTree.c����7���֣���7���֣�
//��֪����ֵk���ڶ������������ҵ���ɾ���ý��
int DeleteByVexValue(BSTree *bst, int k)
{
	if (!*bst)
		return -1;
	else{
		if (k==(*bst)->Key)
			return DeleteByVexAddr(bst);
		else if ( k < (*bst)->Key )
			return DeleteByVexValue(&(*bst)->Lch, k);
		else 
			return DeleteByVexValue(&(*bst)->Rch, k);
	}
}

int main()
{
	BSTree T, pAnswer;
	int K;
	printf("�������������������������У���-1������\n");
    CreateBST(&T);
	printf("�����������������,�������Ϊ:\n");
	InOrder(T);
    printf("\n");
	printf("��������Ҫ���ҵ�Ԫ��:\n");
    scanf("%d",&K);
	pAnswer= SearchBST(T,K, NULL);
    if(pAnswer==NULL)
		printf("����ʧ��!#o#\n");
    else 
		printf("���ҳɹ�!�ɷ��ص�ַ������%d\n",pAnswer->Key);
	printf("��������Ҫɾ����Ԫ��:\n");
    scanf("%d",&K);
	DeleteByVexValue(&T, K);
	printf("ɾ��%d��������������������Ϊ:\n",K);
	InOrder(T);
	printf("\n��������Ҫ�����Ԫ��:\n");
    scanf("%d",&K);
	if (InsertBST(&T, K)==0)
		printf("����ɹ���\n");
	else
		printf("����ʧ�ܣ����������Ѵ��ڸ�Ԫ�أ�\n");
	printf("����%d��������������������Ϊ:\n",K);
	InOrder(T);
	return 0;
}

/*
����Ĳ�����������
50 40 60 70 30 20 90 84 65 32 37 98 57 -1
37
37
*/