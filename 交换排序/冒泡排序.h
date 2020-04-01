//冒泡排序算法如下：
//用冒泡排序法对数组元素a[0]〜a[n-1]进行排序
void BubbleSort(int a[], int n)
{
	int i, j, flag = 1;
	int temp;
	for (i = 1; i < n && flag == 1; i++)
	{
		flag = 0;
		for (j = 0; j < n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				flag = 1;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
