#include<stdio.h>
#include"直接选择排序.h"
#include"堆排序.h"

//1.直接选择排序测试
/*
int main() {
	int test[] = {64,5,7,89,6,24},n=6;

	SelectSort(test, n);
	for (int i = 0; i < n;i++)
	{
		printf("%d  ", test[i]);
	}
	return 0;
}
*/


//2.堆排序测试
int main() {
	int test[] = { 64,5,7,89,6,24 }, n = 6;

	HeapSort(test, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d  ", test[i]);
	}
	return 0;
}
