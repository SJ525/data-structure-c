#include<stdio.h>
#include"归并排序.h"

int main()
{
	int test[] = { 72,73,71,23,94,16,5,68,64 };
	int i,n = 9;
	MergeSort(test, n);
	for (i = 0; i < n; i++)
	{
		printf("%d  ", test[i]);
	}
}