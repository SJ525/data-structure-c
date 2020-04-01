#include"链式队列.h"
void RadixSort(int a[], int n, int m, int d)
{
	int i, j, k, power = 1;
	LQueue* tub;			//把d个队列定义为动态数组
	tub = (LQueue*)malloc(sizeof(LQueue) * d);
	for (i = 0; i < d; i++)
		QueueInitiate(&tub[i]);	//d个队列分别初始化
	for (i = 0; i < m; i++) // 进行m次放和收
	{
		  if (i == 0) power = 1;
		  else power = power * d;
		  for (j = 0; j < n; j++)			//放
		  {
			k = a[j] / power - (a[j]/ (power * d)) * d;
			QueueAppend(&tub[k], a[j]);//把a[j]放入第k个队列
		  }
		  k = 0;
		for (j = 0; j < d; j++)			//回收
		while (QueueNotEmpty(tub[j]) != 0)
		{
			QueueDelete(&tub[j], &a[k]);//从各队列中回收
			k++;
		}
	}
}
