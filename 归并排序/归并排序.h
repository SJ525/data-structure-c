#include<malloc.h>
void Merge(int a[], int n, int swap[], int k)
//k为子数组长度，一次二路归并排序后的子序列存于数组swap中
{
	int m = 0, u1, l2, i, j, u2;
	int l1 = 0;				//第一个有序子数组下界为0
	while (l1 + k <= n - 1)
	{
		l2 = l1 + k;			//第二个有序子数组下界
		u1 = l2 - 1;			//第一个有序子数组上界
		u2 = (l2 + k - 1 <= n - 1) ? l2 + k - 1 : n - 1;  //第二个子数组上界
		  //两个有序子数组合并
		for (i = l1, j = l2; i <= u1 && j <= u2; m++)
		{
			if (a[i]<= a[j])
			{
				swap[m] = a[i];   i++;
			}
			else
			{
				swap[m] = a[j];   j++;
			}
		}
		//子数组2已完，将子数组1中剩余的元素存放到swap
		while (i <= u1)
		{
			swap[m] = a[i];      m++;         i++;
		}
		//子数组1已完，将子数组2中剩余的元素存放到swap
		while (j <= u2)
		{
			swap[m] = a[j];       m++;        j++;
		}
		l1 = u2 + 1;
	}
	//将原始数组中只够一组的数据元素顺序存放到数组swap
	for (i = l1; i < n; i++, m++)  swap[m] = a[i];
}


//二路归并排序算法如下
void MergeSort(int a[], int n)
{
	//归并长度从1开始
	int i, k = 1;
	int *swap;

	//申请动态数组空间
	swap = (int *)malloc(sizeof(int) * n);

	while (k<n)
	{
		//调用归并函数Merge (a, n, swap, k)
		Merge(a, n, swap, k);
		for (i = 0; i < n; i++)
		{
			a[i] = swap[i]; //将元素从临时数组swap放回数组a中
		}
		k = 2 * k;//归并长度加倍
	}
	free(swap);//释放动态数组空间
}