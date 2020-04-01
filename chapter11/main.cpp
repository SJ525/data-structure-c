// chapter11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//顺序查找、有序查找、折半查找
#include "SeqList.h"

/*定义顺序查找函数*/
int SeqSearch(SeqList S,DataType x) {
	int i = 0;
	//如果没遇到相等
	while (S.size>i&&S.list[i]!= x)
	{
		i++;
	}
	//如果遇到相等
	if (S.list[i] == x) {
		return i;
	}
	else
	{
		return -1;
	}
}

/*定义有序查找*/
//在有序顺序表S中顺序查找数据元素x
//查找成功，则返回该数据元素的位置；否则返回-1
int orderSeqSearch(SeqList S, DataType x) {
	//执行排序
	S = sortAsc(S);
	//执行查找
	int i = 0;
	//如果没遇到相等
	while (S.size > i&& S.list[i] != x)
	{
		i++;
	}
	//如果遇到相等
	if (S.list[i] == x) {
		return i;
	}
	else
	{
		return -1;
	}
}

/*定义有序顺序表折半查找函数*/
//在有序顺序表S中顺序查找数据元素x
//查找成功，则返回该数据元素的位置；否则返回-1
int binarySearch(SeqList S, DataType x) {
	//确定初始查找区间上下界
	int low = 0, high = S.size - 1;
	int mid;
	//执行查找操作
	while (low<=high)
	{
		//确定查找区间中心位置
		mid = (low + high) / 2;
		//查找成功
		if (S.list[mid]==x)
		{
			return mid;
		}
		//继续移动位置
		else if (S.list[mid] < x) {
			low = mid + 1;
		}
		else if (S.list[mid] > x) {
			high = mid - 1;
		}
	}
	return -1;
}

int main(){
	//定义SeqList类型变量
	SeqList myS = { {710, 342, 45, 686, 6, 841, 429, 134, 68, 264},10 };
	DataType x = 68;
	
	/*执行查找操作*/
	//int i = SeqSearch(myS, x);
	//if (i!=-1)
	//{
	//	printf("该数据元素位置为%d", i);
	//}
	//else {
	//	printf("查找失败");
	//}

	/*执行有序查找*/
	//myS=sortAsc(myS);
	//printf("排序后：");
	//printSeqList(myS);
	//printf("\n");
	////执行有序查找操作
	//int i=orderSeqSearch(myS, x);
	//if (i!=-1)
	//{
	//	printf("该数据元素位置为%d", i+1);
	//}
	//else {
	//	printf("查找失败");
	//}

	/*有序顺序表折半查找*/
	myS=sortAsc(myS);
	printf("排序后：");
	printSeqList(myS);
	printf("\n");
	int i = binarySearch(myS,x);
	if (i!=-1)
	{
		printf("该数据元素位置为%d", i+1);
	}
	else {
		printf("查找失败");
	}
	return 0;
}


