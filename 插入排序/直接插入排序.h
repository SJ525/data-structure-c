typedef int KeyType;
typedef struct
{
	KeyType key;
}DataType;
void InsertSort(DataType a[], int n)
//用直接插入法对a[0]--a[n-1]排序
{
	int i, j;
	DataType temp;
	for (i = 0; i < n - 1; i++)
	{
		temp = a[i + 1];
		j = i;
		while (j > -1 && temp.key < a[j].key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}

