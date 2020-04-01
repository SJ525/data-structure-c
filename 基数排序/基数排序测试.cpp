#include"基数排序.h"

int main() {
	int test[] = { 710,432,45,686,6,841,429,134,68,246 };
	int i, n = 10, m = 3, d = 10;

	RadixSort(test, n, m, d);
	for ( i = 0; i < n; i++)
	{
		printf("%d  ", test[i]);
	}
}