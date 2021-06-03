//����6.3 ---------ͼ���ڽӱ��ʾ�������ṹ�������---------//
//�ļ�����AdjList.c����1���֣���5���֣�
#include "stdio.h"
#include "malloc.h"
#define MAXVEX 100              //�ٶ�ͼ�����ֻ��100������
typedef char VertexType[20];         //�ٶ�����Ԫ�ص�����Ϊchar[20]
typedef float EdgeType;             //�ٶ�����Ȩֵ����Ϊfloat
typedef struct LinkListNode          //������
{
    int adjVex;        //�ڽӵ��򣬴洢�û���Ӧ�Ļ�ͷ������±�(�ڽӱ�)/��β������±�(���ڽӱ�)
    EdgeType weight;  //Ȩֵ�򣬴洢�û���Ӧ��Ȩֵ
    struct LinkListNode *next;
}LinkListNode;
typedef struct VertexNode        //�������
{
    int InDegree;              //�����������㷨��ר������������ûѧ�������򣬿ɺ��Դ˳�Ա
    VertexType data;           //�����򣬴洢ͼ�����ж���Ļ�����Ϣ
    LinkListNode *first;       //����ı�ͷָ�룬ָ���һ��������
}VertexNode;
typedef struct                 //��װ������ͼ��һЩ��ظ�����Ϣ
{
    VertexNode AdjList[MAXVEX];
    int iVertexCount;
    int iEdgeCount;
    int visited[MAXVEX];
}ADJLIST;                   //�ڽӱ������Ͳ�����ȡ��ADJLIST
#include "LinkStack.h"          //��ȱ�����Ҫʹ����ջ
#include "LinkQueue.h"         //��ȱ�����Ҫʹ��������

//����6.4 ---------ͼ���ڽӱ�"����"��������---------//
//�ļ�����AdjList.c����2���֣���5���֣�
//��ͼ�б߻���Ȩֵ����Ӧ���ñ���(*)�еĴ���
int CreateAdjList(ADJLIST **ppG)
{
    int i, j, k;
   // float weight;                           // (*)
    LinkListNode *p;
    //��������ʼ��ͼ���ڽӱ�ṹ
    *ppG= (ADJLIST *)malloc(sizeof(ADJLIST));
    if (*ppG==NULL) return -1;
    printf("�������붥�������ͻ���������\n");
    scanf("%d%d", &(*ppG)->iVertexCount, &(*ppG)->iEdgeCount);  //���붥�������ͻ�������
    printf("�����붥���ֵ���Կո���������\n");
    for (i=0; i < (*ppG)->iVertexCount; i++)
    {
        scanf("%s", (*ppG)->AdjList[i].data);    //������������붥���ֵ
        (*ppG)->AdjList[i].first= NULL;        //�������ʼ��Ϊ��
         (*ppG)->AdjList[i].InDegree= 0;       //���ûѧ�������򣬿ɲ������д���
        (*ppG)->visited[i]= 0;
    }
    printf("�������������л��Ķ�������ϡ�\n�����3�ŵ㵽5�ŵ���һ������������3,5\n");
    for(k= 0; k < (*ppG)->iEdgeCount; k++)
    {
        scanf("%d,%d", &i, &j);               //���뻡(vi, vj)�Ķ������
        //scanf("%d,%d,%f", &i, &j, &weight);   //�����ñ��У���ɾ����һ�д���    (*)
        p= (LinkListNode *)malloc(sizeof(LinkListNode));
        if (p==NULL)
            return -1;
        p->adjVex= j;
        p->next= (*ppG)->AdjList[i].first;
        //p->weight= weight;                 // (*)
        (*ppG)->AdjList[i].first = p;
        (*ppG)->AdjList[j].InDegree++;        //���ûѧ�������򣬿ɲ������д���
    }
    return 0;
}

//����6.6 ---------�ǵݹ��ͼ���ڽӱ�������ȱ�������������---------//
//�ļ�����AdjList.c����3���֣���5���֣�
//N_DFS����ֻ�����ڵ�����ͨͼ���������N_DFSTraverse���Ӻ�����
int N_DFS(ADJLIST *pG, int StartVex)
{
    int j, cur;
    LinkStack *pS;
    LinkListNode *p;        //����ָ���ڽӱ��еĵ�������
    if (pG==NULL) return -1;

    InitStack(&pS);
    cur= StartVex;
    p= pG->AdjList[cur].first;
    pG->visited[cur]= 1;
    printf("%s ", pG->AdjList[cur].data);
    Push(pS, cur, p);
    while( !StackIsEmpty(pS) )    //ÿ��Ԫ�ض�Ҫ��ջ��ջһ�Σ���ջ�������Ƴ������
    {
        //��p��λ���������е�һ��δ�����ʹ��Ľ��
        while (p!= NULL && pG->visited[p->adjVex]==1 )
        {
            p= p->next;
        }
        if (p==NULL)                //����ö���������ڽӵ㶼�Ѿ�������
        {
            Pop(pS, &cur, &p);      //����ǰ�����˶�ѡ��·������һ������
        }
        else                        //����ö��㻹��δ�����ʵĶ��㣬����ʣ���ǣ�ѹջ��ǰ��
        {
            j= p->adjVex;      
            pG->visited[j]= 1;                    //���
            printf("%s ", pG->AdjList[j].data);   //����
            p= pG->AdjList[j].first;              //ǰ��
            Push(pS, j, p);                       //ѹջ
        }
    }
    printf("\n");
    return 0;
}
//������ȱ�������������
int N_DFSTraverse(ADJLIST *pG)
{
    int i;
    if (pG== NULL) return -1;
    for(i=0; i < pG->iVertexCount; i++)      //���ø����ṹ��׼������
        pG->visited[i]= 0;
    for(i=0; i < pG->iVertexCount; i++)
    {
        //����δ���ʹ��Ķ������DFS�������������ͨͼ����˴�ֻ��ִ��1��
        if (pG->visited[i]==0)
            N_DFS(pG, i);
    }
    return 0;
}

//����6.7 ---------�ǵݹ��ͼ���ڽӱ�������ȱ�������������---------//
//�ļ�����AdjList.c����4���֣���5���֣�
//N_BFS����ֻ�����ڵ�����ͨͼ���������N_BFSTraverse���Ӻ�����
int N_BFS(ADJLIST *pG, int StartVex)
{
    int j, cur;
    LinkQueue *pQ;
    LinkListNode *p;           //����ָ���ڽӱ��еĵ�������
    if (pG==NULL) return -1;

    InitQueue(&pQ);
    cur= StartVex;
    p= pG->AdjList[cur].first;
    pG->visited[cur]= 1;
    printf("%s ", pG->AdjList[cur].data);
    EnQueue(pQ, cur);
    while( !QueueIsEmpty(pQ) )    //ÿ��Ԫ�ض�Ҫ���ӳ���һ�Σ��Զӿ������Ƴ������
    {
        //��p��������������δ�����ʹ��ĵ����α�ǡ����ʺ���ӡ��ѷ��ʹ��ĵ��Զ�Ʈ��
        while (p!= NULL) 
        {
            if (pG->visited[p->adjVex]==0)
            {
                j= p->adjVex;      
                pG->visited[j]= 1;                     //���
                printf("%s ", pG->AdjList[j].data);      //����
                EnQueue(pQ, j);                      //���
            }
            p= p->next;
        }

        if (p==NULL)                    //����ö���������ڽӵ㶼�Ѿ�������
        {
            DeQueue(pQ, &cur);           //�Ӷ�������ȡһ��Ԫ�أ��Ա������δ�����ʵ������ڽӵ�
            p= pG->AdjList[cur].first;                 //ǰ��
        }
    }
    printf("\n");
    return 0;
}
//������ȱ�������������
int N_BFSTraverse(ADJLIST *pG)
{
    int i;
    if (pG== NULL) return -1;
    for(i=0; i < pG->iVertexCount; i++)      //���ø����ṹ��׼������
        pG->visited[i]= 0;
    for(i=0; i < pG->iVertexCount; i++)
    {
        //����δ���ʹ��Ķ������DFS�������������ͨͼ����˴�ֻ��ִ��1��
        if (pG->visited[i]==0)
            N_BFS(pG, i);
    }
    return 0;
}

//����6.10 --------- �����ڽӱ��ͼ�����������㷨���� --------- //
//�ļ�����AdjList.c����5���֣���5���֣�
int TopoSortByAdjList(ADJLIST *pG)
{
    LinkListNode *p;
    int i, k, gettop;
    int count= 0;  //���ڼ��������ĸ����������ж����������Ƿ�����·
    int *stack;    //����һ�����׵�intջ�����ڴ�Ŵ���������Ϊ0�Ķ�����
    int top=0;     //stackջר�õ�ջ��ָʾ�� 
    if (pG==NULL) return -1;
    stack= (int *)malloc(pG->iVertexCount * sizeof(int));
    //��һ�����Ƚ��ڽӱ����������Ϊ0�Ķ�����ѹջ
    for(i=0; i < pG->iVertexCount; i++)
        if (pG->AdjList[i].InDegree==0)
        {
            top= top +1;
            stack[top]= i;
        }
    //�ڶ�������������ջ�Ķ��������²�����
    while(top!=0)
    {
        //��ջ��ȡ��һ�����Ϊ0�Ķ����ţ����
        gettop= stack[top];
        top= top - 1;
        printf("%s ", pG->AdjList[gettop].data);
        count++;
        //���Ըö���Ϊ��β�����л�ͷ���InDegreeֵ��1���Ա�ʾɾ����1����
        p= pG->AdjList[gettop].first;
        while(p!= NULL)
        {
            k= p->adjVex;
            pG->AdjList[k].InDegree--;
            if (pG->AdjList[k].InDegree == 0)   //��ɾ����֮����ȱ�Ϊ0�Ķ���ѹջ���Ա�������
            {
                top++;
                stack[top]= k;
            }
            p= p->next;
        }
    }
    if (count < pG->iVertexCount)    //��������ĸ��������ܶ��������˵�����ڻ�·
        return -2;
    else
        return 0;
}


int main()
{
    ADJLIST *pG;
    CreateAdjList(&pG);
	printf("�ǵݹ�Ļ����ڽӱ����ȱ���������£�\n");
    N_DFSTraverse(pG);
    return 0;
}

/*
����CreateAdjList��������
4 5
�� �� �� ��
1,3
3,0
1,0
3,2
1,2

N_DFSTraverse������������
15 70
A B C D E F G H I J L M N O P
0,1
0,5
0,6
1,0
1,2
1,5
1,6
1,7
2,1
2,3
2,6
2,7
2,8
3,2
3,4
3,8
3,9
4,3
4,8
4,9
5,0
5,1
5,6
5,10
5,11
6,0
6,1
6,2
6,5
6,7
6,10
6,11
6,12
7,1
7,2
7,6
7,8
7,11
7,12
8,2
8,3
8,4
8,7
8,9
8,12
8,13
8,14
9,3
9,4
9,8
9,13
10,5
10,6
10,11
11,5
11,6
11,7
11,10
11,12
12,6
12,7
12,8
12,11
12,13
13,8
13,9
13,12
13,14
14,8
14,13

��������Ĳ����������£�
11 20
A B T D R K G H P M S
0,1
0,5
1,2
2,3
2,7
4,0
4,5
4,9
5,1
5,2
5,6
5,10
6,2
6,9
7,3
7,10
8,4
8,5
8,9
9,10




����7 11��Ȼ������ABCDEFG7����
0,1
0,2
0,3
1,5
3,6
5,6
4,5
2,1
2,4
1,3
4,3

*/