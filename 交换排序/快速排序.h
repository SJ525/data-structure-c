//快速排序算法
//对数据元素allow]〜a[high]进行快速排序
void QuickSort(int a[], int low, int high)
{
	int i = low, j = high;
	//取第一个元素为标准数据元素
	int temp = a[low];

	while (i < j && temp<= a[j]) j--;//在数组的右端扫描
	if (i < j)
	{
		a[i] = a[j];
		i++;
	}

	while (i < j && a[i] < temp) i++;//在数组的左端扫描
	if (i < j)
	{
		a[j] = a[i];
		j--;
	}
	a[i] = temp;

	if (low < i) {
		QuickSort(a, low, i - 1);
	}
	if (i < high) {
		QuickSort(a, j + 1, high);
	}

}