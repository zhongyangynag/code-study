//����7.1---------�۰�����㷨�Ĳο�����---------//
// dataΪ�������ƣ�nΪdata�����ʵ��Ԫ�ظ�����KΪҪ���ҵ�Ԫ��ֵ���������������Ԫ��Ϊint��
#include "stdio.h"
int main()
{
    int i, KK, pos, AA[20];
	int  Binary_Search(int  data[], int  n, int  K);
    printf("�����ϸ񵥵�������˳��������ұ��15��������\n");
    for(i= 0; i < 15; i++)
        scanf("%d", &AA[i]);
    printf("������Ҫ���ҵ�������");
    scanf("%d", &KK);
    pos=Binary_Search(AA, 15, KK); 
    if (pos == -1)
        printf("����ʧ�ܣ����ұ���û�и�Ԫ�أ�");
    else
        printf("���ҳɹ���%d�ڲ��ұ��еĵ�%d��λ���ϡ�", KK, pos);
    return 0;
}

int  Binary_Search(int  data[], int  n, int  K)
{
    int  low,  high,  mid;
    low=  0;  high=  n-1;      //��ʼ����±�Ϊ0����ʼ����±�Ϊn-1
    while (low <= high) {         //��ǰ�᲻���� ������ѭ����������
        mid= (low+high)/2;      //�۰루ע�⣬���±�λ�õ��۰룬��������Ԫ��ֵ���۰룩
        if (K < data[mid])
            high= mid - 1;
        else if (K > data[mid])
            low= mid + 1;
        else
            return  mid;
    }
    return -1;
}

/*
�������ݣ�
5 10 13 18 20 24 27 31 33 39 43 46 48 52 55


*/