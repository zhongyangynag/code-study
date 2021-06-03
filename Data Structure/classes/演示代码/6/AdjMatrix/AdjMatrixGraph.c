//����6.1 ---------ͼ���ڽӾ�������ṹ�������---------//
//�ļ�����AdjMatrixGraph.c����1���֣���6���֣�
#include "stdio.h"
#include "malloc.h"
typedef char VertexType[20];         //�ٶ�����Ԫ�ص�����Ϊchar[20]
typedef float  EdgeType;
#define MAXVEX 100              //�ٶ�ͼ�����ֻ��100������
#define MAXEDGE 2000            //�ٶ�ͼ�����ֻ��2000���߻�
#define INFINITY 65535
typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType   arcs[MAXVEX][MAXVEX];
    int iCurVexCount;
    int iCurEdgeCount;
}AdjMatrix;

//����6.2 ---------ͼ���ڽӾ���"����"��������---------//
//�ļ�����AdjMatrixGraph.c����2���֣���6���֣�
//����ָ��ͼG�ṹ��Ķ���ָ��ppG���ں����ڽ������ݵ�¼��
int CreateAdjMatrix(AdjMatrix **ppG)
{
    int i,j,k;
    float weight;
    //��һ����������ͼ����Ҫ�Ľṹ��ռ�
    *ppG= (AdjMatrix *)malloc(sizeof(AdjMatrix));
    if (*ppG==NULL) return -1;
    //�ڶ��������붥��ͱ�/������Ŀ
    printf("�����붥����Ŀ�ͱ�/����Ŀ���ÿո����:\n");
    scanf("%d%d",&(*ppG)->iCurVexCount, &(*ppG)->iCurEdgeCount);
    //�������������������
    printf("�밴���˳������������������ֵ���ÿո����:\n");
    for(i=0; i < (*ppG)->iCurVexCount; i++)
        scanf("%s", (*ppG)->vexs[i]);
    //���Ĳ�����/�������ʼ��
    for(i=0; i < (*ppG)->iCurVexCount; i++)
        for(j=0; j < (*ppG)->iCurVexCount; j++)
            (*ppG)->arcs[i][j]= INFINITY;
    //���岽�����������/��
    printf("�����뻡����ʼ���š���ֹ���źͻ���Ȩֵ��\n");
    for(k=0; k < (*ppG)->iCurEdgeCount; k++)
    {
        scanf("%d%d%f",&i,&j,&weight);
        (*ppG)->arcs[i][j]=weight;
        (*ppG)->arcs[j][i]=weight;
    }
    return 0;
}

//����6.5 ---------�ݹ��ͼ���ڽӾ���ṹ�µ�����������������㷨����----------//
//�ļ�����AdjMatrixGraph.c����3���֣���6���֣�
int visited[MAXVEX];              //���Ӹ�����һά��������visited[]
int DFS(AdjMatrix *pG, int cur)
{
    int i;
    if (pG==NULL)  return -1;
    visited[cur]= 1;
    printf("%s ", pG->vexs[cur]);     //���ʶ���Ĳ������˴��ɸ���Ϊ��������
    for (i= 0; i < pG->iCurEdgeCount ; i++)
    {
        if (pG->arcs[cur][i]==1 && visited[i]==0)  //�ڽ���δ���ʣ�ע���ڽӷ���
            DFS(pG, i);                            //�ݹ����
    }
    return 0;
}
int DFSTraverse(AdjMatrix *pG)
{
    int i;
    if (pG== NULL) return -1;
    for(i=0; i < pG->iCurVexCount; i++)      //���ø����ṹ��׼������
        visited[i]= 0;
    for(i=0; i < pG->iCurVexCount; i++)
    {
        //����δ���ʹ��Ķ������DFS�������������ͨͼ����˴�ֻ��ִ��1��
        if (visited[i]==0)
            DFS(pG, i);
    }
    return 0;
}

//����6.8---------�����ڽӾ����Prim�㷨����---------//
//�ļ�����AdjMatrixGraph.c����4���֣���6���֣�
int Prim_AdjMatrix(AdjMatrix *pG)
{
    int i, j, k, StartPos;
    float min;
    //��¼�Ӷ��㼯U��I-U�Ĵ�����С�ıߵĸ������鶨��
    int adjvex[MAXVEX];                //
    float lowcost[MAXVEX];             //
    if (pG==NULL) return -1;
    StartPos= 0;
    for (i=0; i < pG->iCurVexCount; i++)
    {
        lowcost[i]= pG->arcs[StartPos][i];
        adjvex[i]= StartPos;
    }
    //�ڱ����У����ǴӶ���E�����4������������U={4}������U�е����е㣬��lowcostֵ����0
    lowcost[StartPos]= 0;
    adjvex[StartPos]=0;
    //ѭ������iֻ�����ѭ�����������ã��ڲ�����Ҫ��ѭ��n-1�Σ�ÿ���ҳ�һ����
    for(i=0; i<pG->iCurVexCount-1; i++)
    {
        //һ�αȽ϶����Ĵ��룬�ҳ�lowcost�����з�0Ԫ�ص���Сֵ�����õ����±�k
        //���lowcost[k]�ͱ�ʾ���㼯U��I-U�����б���Ȩֵ��С�������ߵ�Ȩֵ��
        min= INFINITY;
        j= 0;
        k= StartPos;
        while (j < pG->iCurVexCount)
        {
            if (lowcost[j]>1e-6 && lowcost[j]<min)
            {
                min= lowcost[j];
                k=j;
            }
            j++;
        }
        //��k�������ڼ���I-U���������ϼ���Ҫ�����յ�����U�еĶ�����
        //adjvex[k]�������ߵ�����һ���˵�Ķ����ţ������ڶ��㼯U��
        printf("(%d,%d)", adjvex[k], k);      //�����һ��ѡ�еıߣ�����С��������һ����
        //=0��ʾ���㼯U�����е㵽���Ϊk�Ķ���ľ�����0�����־�Ŷ���k�����뼯��U��
        lowcost[k]=0; 
        //��lowcost��������Ԫ�ض�У��һ��
        for(j= 0; j<pG->iCurVexCount; j++)
        {
            //���㼯U�����˶���k�󣬸���lowcost������"���ڶ��㼯I-U�Ĳ��ҵ����㼯U�ľ���
            //С��ԭ��lowcostֵ"��Ԫ�أ����Ѷ���k����������Vj�ľ�����lowcost[j]�Ƚϲ�ˢ�¡�
            if (lowcost[j]!=0 && pG->arcs[k][j] < lowcost[j])
            {
                lowcost[j]= pG->arcs[k][j];
                adjvex[j]=k;
            }
        }
    }
    return 0;
}


//����6.9 ---------�����ڽӾ����ͼ��Kruskal�㷨����(begin)---------//
//�ļ�����AdjMatrixGraph.c����5���֣���6���֣�
// ���㷨����GetEdges(), SortEdges(), GetBoss()��Kruskal_AdjMatrix()�ĸ���������
typedef struct EdgeData    // �ߵĽṹ�壬Kruskal�㷨��ר�����ݽṹ֮1
{
    char  startNo;           // �ߵ������
    char  endNo;             // �ߵ��յ���
    float weight;            // �ߵ�Ȩ��
}EdgeData;
// ���ڽӾ����е����бߵ���Ϣ��ȡ��һά�����У�Ϊ��Ȩֵ������׼��
int GetEdges(AdjMatrix *pG, EdgeData **ppED)
{
    int i,j;
    int index=0;
    if (pG==NULL) return -1;
    *ppED = (EdgeData *) malloc( pG->iCurEdgeCount * sizeof(EdgeData) );
    if (*ppED == NULL) return -2;
    for (i=0; i < pG->iCurVexCount; i++)
    {
        for (j=i+1; j < pG->iCurVexCount; j++)
        {
            if ( pG->arcs[i][j]!=INFINITY )
            {
                (*ppED)[index].startNo  = i;
                (*ppED)[index].endNo    = j;
                (*ppED)[index].weight   = pG->arcs[i][j];
                index++;
            }
        }
    }
    return 0;
}

//��pEdgesָ��������е�ǰlen��Ԫ�ذ��ձߵ�Ȩֵ��С��������(��С����)
int SortEdges(EdgeData* pEdges, int len)
{
    int i,j;
    EdgeData tmp;
    if (pEdges== NULL) return -1;
    if (len <= 0 ) return -2;
    for (i=0; i<len; i++)
    {
        for (j=i+1; j<len; j++)
        {
            if (pEdges[i].weight > pEdges[j].weight)
            {
                // ����"��i����"��"��j����"��ֵ
                tmp = pEdges[i];
                pEdges[i] = pEdges[j];
                pEdges[j] = tmp;
            }
        }
    }
    return 0;
}

// ��ȡi����ͨ��󶥵���
int GetBoss(int Boss[], int i)
{
    while (Boss[i] != 0)
        i = Boss[i];
    return i;
}

// ����Kruskal�㷨�����С�������ıߣ��ú��������GetEdges(), SortEdges(), GetBoss()����
int Kruskal_AdjMatrix(AdjMatrix *pG)
{
    int i,m,n;
    int index = 0;            // ���ڼ�¼�������ı������Ա���ǰ��������
    int Boss[MAXVEX]={0};     // ���ڱ���ÿ�������ڸ���С�������е���ͨ��󶥵���
    EdgeData *edges;
    GetEdges(pG, &edges);    // ��ȡ"ͼ�����еı�"
    SortEdges(edges, pG->iCurEdgeCount);           // ���߰���"Ȩ"�Ĵ�С��������(��С����)
    for (i=0; i<pG->iCurEdgeCount; i++)
    {
        m = GetBoss(Boss, edges[i].startNo); //��ȡ��i���ߵ�"���"�ڵ�ǰ�������е���ͨ��󶥵���
        n = GetBoss(Boss, edges[i].endNo);   //��ȡ��i���ߵ�"�յ�"�ڵ�ǰ�������е���ͨ��󶥵���
        if (m != n)        // ���m!=n����ζ��"��i"��"�Ѿ���ӵ���С�������еĶ���"û���γɻ�·
        {
            if (m<n)
            {
                Boss[m] = n;                       // ����m����ͨ��󶥵���Ϊn
            }
            else if (m > n)
            {
                Boss[n] = m;                       // ����n����ͨ��󶥵���Ϊm
            }
            printf("(%2d,%2d)ȨֵΪ%4f \n", edges[i].startNo, edges[i].endNo, edges[i].weight);
            index++;
            if (index== pG->iCurVexCount-1) break;       //�չ�n-1��������Խ���������
        }
    }
    free(edges);
    return 0;
}


//����6.11 ---------�����ڽӾ����ͼ��Dijkstra�㷨����(begin)---------//
//�ļ�����AdjMatrixGraph.c����6���֣���6���֣�
#include "stdlib.h"                            // Ϊ��ʹ��itoa()����
#include "string.h"                            //Ϊ��ʹ��strlen()����
#include "math.h"                            //Ϊ��ʹ��fabs()����/
typedef char *PathVexes[MAXVEX];            //���ڴ洢���·���±������
typedef float ShortPath[MAXVEX];             //�û��洢Դ�㵽�������·����Ȩֵ��
//�ַ���ƴ�Ӻ�����Dijkstra�㷨ר�ã�ֻ��Dijkstra()�����б�����
//���ı�ԭ�е�s1��s2�����ַ����������ɵ����ַ�����s1����s2����ֵ��ch�ַ����
char *strconnect(const char *s1, char ch, const char *s2)
{
    int i,j; 
    char *res;
    res= (char *)malloc(strlen(s1) + strlen(s2) + 2);     //�¿ռ��һ���������һ��������
    if (res==NULL) return res;
    i=j=0;
    while (s1[j]!='\0')
        res[i++]= s1[j++];
    res[i]= ch;  i++;              //ƴ������

    j=0;
    while (s2[j]!='\0')
        res[i++]= s2[j++];
    res[i]= '\0';             //д�������
    return res;               //����ֵ�Ǿֲ�malloc�����ָ����������������������ý�����free�� 
}

//Dijkstra�㷨��������ͼG��StartVexPos���㵽��������v�����·��P[v]��·������ֵD[v]
int Dijkstra(AdjMatrix *pG, int StartVexPos, PathVexes P, ShortPath D)
{
    int i, j, MinPos;
    float min;
    char ch1[6], ch2[6];
    int VexIsinS[MAXVEX];
    char *tmp1, *tmp2;
    if (pG== NULL) return -1;
    //��ʼ��D�����P�����ֵ
    for(i=0; i < pG->iCurVexCount; i++)
    {
        VexIsinS[i]=0;
        D[i]= pG->arcs[StartVexPos][i];
        P[i]= NULL;
        if (D[i]!= INFINITY)
        {
            itoa(StartVexPos, ch1, 10);
            itoa(i, ch2, 10);
            P[i]=strconnect(ch1, '-', ch2);
        }
    }
    D[StartVexPos]= 0;            //�������Լ����Լ���·��Ϊ0
    VexIsinS[StartVexPos]= 1;     //��Դ�����ڼ���S�У�����
    for(i=0; i < pG->iCurVexCount - 1; i++)
    {
        //�ҳ�I-S������Dֵ��С�Ķ�����MinPos����Сֵmin
        min= INFINITY;
        MinPos= -1;
        for(j= 0; j < pG->iCurVexCount; j++)
        {
            if (VexIsinS[j]==0 && D[j] < min )
            {
                MinPos= j;
                min= D[j];
            }
        }
        VexIsinS[MinPos]=1;       //���ö������յ�S������
        for(j=0; j < pG->iCurVexCount; j++)    //n��ѭ�����ѱ����ж���
        {
            if (VexIsinS[j]==0 && (D[MinPos] + pG->arcs[MinPos][j] < D[j]))  //��Ҫ�����������
            {
                D[j]= D[MinPos] + pG->arcs[MinPos][j];
                itoa(j, ch2, 10);
                if (P[j]!=NULL)                   //���ͷ�ԭ�е�·���ַ���
                    free(P[j]);
                P[j]= strconnect(P[MinPos], '-', ch2);  //�����µ�·���ַ���
            }
            //������ڶ������·��
            else if (VexIsinS[j]==0 && fabs(D[MinPos] + pG->arcs[MinPos][j] - D[j]) < 1e-6 )
            {
                itoa(j, ch2, 10);
                tmp1= P[j];                                //ԭ·��
                tmp2= strconnect(P[MinPos], '-', ch2);     //�ڶ���·��
                P[j]= strconnect(tmp1, '|', tmp2); //������·����"|"ƴ�ӣ������µ��ַ���������P[j]ָ��
                free(tmp1);                                //�ͷ�ԭ�е�����·�����ַ����ռ�
                free(tmp2);
            }
        }
    }
    return 0;
}



int main()
{
    AdjMatrix *pG;
    CreateAdjMatrix(&pG);
    DFSTraverse(pG);
    return 0;
}

/*
CreateAdjMatrix������������
4 5
�� �� �� ��
3 0 1700
0 1 1178
0 2 1950
3 1 2351
2 1 1308


DFSTraverse������������
15 70
A B C D E F G H I J L M N O P
0 1 1
0 5 1
0 6 1

1 0 1
1 2 1
1 5 1
1 6 1
1 7 1

2 1 1
2 3 1
2 6 1
2 7 1
2 8 1

3 2 1
3 4 1
3 8 1
3 9 1

4 3 1
4 8 1
4 9 1

5 0 1
5 1 1
5 6 1
5 10 1
5 11 1

6 0 1
6 1 1
6 2 1
6 5 1
6 7 1
6 10 1
6 11 1
6 12 1

7 1 1
7 2 1
7 6 1
7 8 1
7 11 1
7 12 1

8 2 1
8 3 1
8 4 1
8 7 1
8 9 1
8 12 1
8 13 1
8 14 1

9 3 1
9 4 1
9 8 1
9 13 1

10 5 1
10 6 1
10 11 1

11 5 1
11 6 1
11 7 1
11 10 1
11 12 1
 
12 6 1
12 7 1
12 8 1
12 11 1
12 13 1

13 8 1
13 9 1
13 12 1
13 14 1

14 8 1
14 13 1

Prim�㷨��Kruskal�㷨��������
16 84
A B C D E F G H I J K L M N O P

0 1 20
0 4 5
0 5 10
1 0 20
1 4 15
1 5 5
1 6 2
1 2 3
2 1 3
2 5 7
2 6 15
2 7 8
2 3 15
3 2 15
3 6 12
3 7 35
4 8 40
4 9 3
4 5 9
4 1 15
4 0 5
5 4 9
5 8 5
5 9 21
5 10 15
5 6 35
5 2 7
5 1 5
5 0 10
6 5 35
6 9 4
6 10 12
6 11 8
6 7 6
6 3 12
6 2 15
6 1 2
7 6 6
7 10 14
7 11 20
7 3 35
7 2 8
8 12 10
8 13 30
8 9 50
8 5 5
8 4 40
9 8 50
9 12 50
9 13 8
9 14 11
9 10 6
9 6 4
9 5 21
9 4 3
10 9 6
10 13 4
10 14 50
10 15 10
10 11 35
10 7 14
10 6 12
10 5 15
11 10 35
11 14 12
11 15 13
11 7 20
11 6 8
12 13 6
12 9 50
12 8 10
13 12 6
13 14 30
13 10 4
13 9 8
13 8 30
14 13 30
14 15 8
14 11 12
14 10 50
14 9 11
15 14 8
15 11 13
15 10 10
 
�������Ϊ��
(4,9)(9,6)(6,1)(1,2)(4,0)(1,5)(5,8)(6,7)(9,10)(10,13)(13,12)
(6,11)(10,15)(15,14)(6,3)



*/
