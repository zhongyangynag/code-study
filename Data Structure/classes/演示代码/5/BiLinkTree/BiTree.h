#ifndef _BT_H
#define _BT_H

typedef  struct  TelemType {        //���е�TelmType���Բ�д��Ϊ��������
	char  name[20];                 //�����ַ����鳤��Ϊ20��
	int   number;
} TelemType; 

typedef  struct  BitNode{          //����һ���ṹ�������ͣ���ΪBitNode���ں�һ��TelmType��
	TelemType  data;               //�ͳ�Աname������ָ���Լ����͵�ָ���Աlch��rch��ͬʱ��
	struct  BitNode  *Lch,  *Rch;  //ָ�������½ṹ�����͵�ָ������ͣ�ȡ��ΪBiTree��ע�⣬
} BiTNode,  *BiTree;               //BitNode��BiTree�����������֣����Ǳ�������

#endif