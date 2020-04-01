#pragma once
#include<stdio.h>
//����˳���Ľṹ��SeqList
typedef int DataType;
//�궨��
#define MaxSize 100
typedef struct {
	DataType list[MaxSize];
	int size;
}SeqList;

//1.��ʼ��Listlnitiate(L)
void Listlnitiate(SeqList* L)
{
	//�����ʼ����Ԫ�ظ���
	L->size = 0;
}
//2.��ǰ����Ԫ�ظ���ListLength(L)
//����˳���L�ĵ�ǰ����Ԫ�ظ���
int ListLength(SeqList L)
{
	return L.size;
}
//3.��������Ԫ�� ListInsert(L, i, x)
//��˳���L�ĵ�i(OWiWsize)��λ��ǰ��������Ԫ��ֵx
//����ɹ�����1, ����ʧ�ܷ���0
int ListInsert(SeqList* L, int i, DataType x)
{
	int j;
	if (L->size >= MaxSize)
	{
		printf("˳������޷����룡\n");
		return 0;
	}
	else if (i<0 || i>L->size)
	{
		printf("����i���Ϸ���\n");
		return 0;
	}
	else
	{
		//�Ӻ���ǰ���κ������ݣ�Ϊ������׼��
		for (j = L->size; j > i; j--) {
			L->list[j] = L->list[j - 1];
		}
		L->list[i] = x;//����x
		L->size++;//Ԫ�ؼ�1
		return 1;
	}
}
//4.ɾ������Ԫ�� ListDelete(L, i, x)
//ɾ��˳���L��λ��i(OWiWsize - l)�ϵ�����Ԫ�ز����浽x��
//ɾ���ɹ�����1,ɾ��ʧ�ܷ���0
int ListDelete(SeqList* L, int i, DataType* x)
{
	int j;
	if (L->size <= 0)
	{
		printf("˳����ѿ�������Ԫ�ؿ�ɾ��\n");
		return 0;
	}
	else if (i<0 || i>L->size - 1)
	{
		printf("����i���Ϸ�");
		return 0;
	}
	else
	{
		//����ɾ����Ԫ�ص�x��
		*x = L->list[i];

		//��ǰ�������ǰ��
		for (j = i + 1; j <= L->size - 1; j++) {
			L->list[j - 1] = L->list[j];
		}
		//����Ԫ�ؼ�1
		L->size--;
		return 1;
	}
}
//5.ȡ����Ԫ�� ListGet(L, i, x)
//ȡ˳���L�е�i������Ԫ�ش���x�У��ɹ�����1,ʧ�ܷ���0
int ListGet(SeqList L, int i, DataType* x)
{
	if (i<0 || i>L.size - 1)
	{
		printf("����i���Ϸ��� \n");
		return 0;
	}
	else {
		*x = L.list[i];
		return 1;
	}
}
//��˳�������������򣬲�����
SeqList sortAsc(SeqList S) {
	int size = S.size;
	int i, j;
	int v;
	//��������
	for (i = 0; i < size - 1; i++)
		for (j = i + 1; j < size; j++)
		{
			if (S.list[i] > S.list[j])//��ǰ��ıȺ���Ĵ��򽻻���
			{
				v = S.list[i];
				S.list[i] = S.list[j];
				S.list[j] = v;
			}
		}
	return S;
}
//���˳���Ԫ��
void printSeqList(SeqList S) {
	int size = S.size;
	for (int i = 0; i < size; i++)
	{
		printf("%d", S.list[i]);
		printf(" ");
	}
}