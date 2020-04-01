#pragma once
#include<stdio.h>
//定义顺序表的结构体SeqList
typedef int DataType;
//宏定义
#define MaxSize 100
typedef struct {
	DataType list[MaxSize];
	int size;
}SeqList;

//1.初始化Listlnitiate(L)
void Listlnitiate(SeqList* L)
{
	//定义初始数据元素个数
	L->size = 0;
}
//2.求当前数据元素个数ListLength(L)
//返回顺序表L的当前数据元素个数
int ListLength(SeqList L)
{
	return L.size;
}
//3.插入数据元素 ListInsert(L, i, x)
//在顺序表L的第i(OWiWsize)个位置前插入数据元素值x
//插入成功返回1, 插入失败返回0
int ListInsert(SeqList* L, int i, DataType x)
{
	int j;
	if (L->size >= MaxSize)
	{
		printf("顺序表己满无法插入！\n");
		return 0;
	}
	else if (i<0 || i>L->size)
	{
		printf("参数i不合法！\n");
		return 0;
	}
	else
	{
		//从后向前依次后移数据，为插入做准备
		for (j = L->size; j > i; j--) {
			L->list[j] = L->list[j - 1];
		}
		L->list[i] = x;//插入x
		L->size++;//元素加1
		return 1;
	}
}
//4.删除数据元素 ListDelete(L, i, x)
//删除顺序表L中位置i(OWiWsize - l)上的数据元素并保存到x中
//删除成功返回1,删除失败返回0
int ListDelete(SeqList* L, int i, DataType* x)
{
	int j;
	if (L->size <= 0)
	{
		printf("顺序表已空无数据元素可删！\n");
		return 0;
	}
	else if (i<0 || i>L->size - 1)
	{
		printf("参数i不合法");
		return 0;
	}
	else
	{
		//保存删除的元素到x中
		*x = L->list[i];

		//从前向后依次前移
		for (j = i + 1; j <= L->size - 1; j++) {
			L->list[j - 1] = L->list[j];
		}
		//数据元素减1
		L->size--;
		return 1;
	}
}
//5.取数据元素 ListGet(L, i, x)
//取顺序表L中第i个数据元素存于x中，成功返回1,失败返回0
int ListGet(SeqList L, int i, DataType* x)
{
	if (i<0 || i>L.size - 1)
	{
		printf("参数i不合法！ \n");
		return 0;
	}
	else {
		*x = L.list[i];
		return 1;
	}
}
//对顺序表进行升序排序，并返回
SeqList sortAsc(SeqList S) {
	int size = S.size;
	int i, j;
	int v;
	//排序主体
	for (i = 0; i < size - 1; i++)
		for (j = i + 1; j < size; j++)
		{
			if (S.list[i] > S.list[j])//如前面的比后面的大，则交换。
			{
				v = S.list[i];
				S.list[i] = S.list[j];
				S.list[j] = v;
			}
		}
	return S;
}
//输出顺序表元素
void printSeqList(SeqList S) {
	int size = S.size;
	for (int i = 0; i < size; i++)
	{
		printf("%d", S.list[i]);
		printf(" ");
	}
}