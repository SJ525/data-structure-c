#include<stdio.h>
#include"冒泡排序.h"
#include"快速排序.h"

//冒泡排序测试
/*
int main()
{
	int test[] = {38,5,19,26,49,97,1,66 };
	int n = 8;
	BubbleSort(test, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d  ", test[i]);
	}
}*/

//快速排序测试
int main()
{
	int test1[] = {60,55,48,37,10,90,84,36};
	int n = 8;
	QuickSort(test1,0,7);
	for (int i = 0; i < n; i++)
	{
		printf("%d  ", test1[i]);
	}
}