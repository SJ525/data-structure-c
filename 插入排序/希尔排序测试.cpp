#include<stdio.h>
#include"Ï£¶ûÅÅĞò.h"

int main()
{
	int test[]= { 64,5,7,89,6,24 };
	int i, n = 6;

	shellSort(test, n);

	for (i = 0; i < n; i++)
	{
		printf("%d  ", test[i]);
	}
}