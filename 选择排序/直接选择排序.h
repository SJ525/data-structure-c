//直接选择排序
void SelectSort(int a[], int n)
{
	int i, j, small;	    
	int temp;

	for (i = 0; i < n - 1; i++)
	{
		//设第i个数据元素关键字最小
		small = i;	 		
		for (j = i + 1; j < n; j++)
		{
			//寻找关键字最小的数据元素
			if (a[j] < a[small]) {
				//记住最小元素的下标
				small = j;
			}      
		}

		//当最小元素的下标不为i时交换位置
		if (small != i)		
		{
			temp = a[i];
			a[i] = a[small];
			a[small] = temp;
		}
	}
}
