#include<stdio.h>
#include"直接插入排序.h"
#include"希尔排序.h"

/*
//直接插入排序测试
int main() {
	DataType test[6] = { 64,5,7,89,6,24 };
	int i, n = 6;
	InsertSort(test, n);
	for (i = 0; i < n; i++)
	{
		printf("%d  ", test[i].key);
	}
}
*/

//希尔排序测试
int main()
{
	int test[] = { 64,5,7,89,6,24 };
	int i, n = 6;

	shellSort(test, n);

	for (i = 0; i < n; i++)
	{
		printf("%d  ", test[i]);
	}
}

