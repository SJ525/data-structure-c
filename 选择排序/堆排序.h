//创建堆
void CreatHeap(int a[], int n, int h)
{
	int i, j, flag;
	int temp;
	i = h;				// i为要建堆的二叉树根结点下标
	j = 2 * i + 1;			// j为i的左孩子结点的下标
	temp = a[i];
	flag = 0;
	while (j < n && flag != 1)
	{        //寻找左右孩子结点中的较大者,j为其下标
		if (j < n - 1 && a[j] < a[j + 1])  j++;
		if (temp > a[j])	//a[i].key>a[j].key
			flag = 1;		//标记结束筛选条件
		else			//否则把a[j]上移
		{
			a[i] = a[j];
			i = j;
			j = 2 * i + 1;
		}
	}
	a[i] = temp;			//把最初的a[i]赋予最后的a[j]
}
//初始化创建最大堆算法如下：
void InitCreatHeap(int a[], int n)
{
	int i;
	for (i = (n - 2) / 2; i >= 0; i--)
		CreatHeap(a, n, i);
}
//堆排序算法如下：
void HeapSort(int a[], int n)
{
	int i;
	int temp;
	InitCreatHeap(a, n);		//初始化创建最大堆 
	for (i = n - 1; i > 0; i--)		//当前最大堆个数每次递减1
	{        //把堆顶a[0]元素和当前最大堆的最后一个元素交换
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		CreatHeap(a, i, 0);	//调整根结点满足最大堆
	}
}



