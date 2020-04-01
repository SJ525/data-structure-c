#include<malloc.h>
void Merge(int a[], int n, int swap[], int k)
//kΪ�����鳤�ȣ�һ�ζ�·�鲢�����������д�������swap��
{
	int m = 0, u1, l2, i, j, u2;
	int l1 = 0;				//��һ�������������½�Ϊ0
	while (l1 + k <= n - 1)
	{
		l2 = l1 + k;			//�ڶ��������������½�
		u1 = l2 - 1;			//��һ�������������Ͻ�
		u2 = (l2 + k - 1 <= n - 1) ? l2 + k - 1 : n - 1;  //�ڶ����������Ͻ�
		  //��������������ϲ�
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
		//������2���꣬��������1��ʣ���Ԫ�ش�ŵ�swap
		while (i <= u1)
		{
			swap[m] = a[i];      m++;         i++;
		}
		//������1���꣬��������2��ʣ���Ԫ�ش�ŵ�swap
		while (j <= u2)
		{
			swap[m] = a[j];       m++;        j++;
		}
		l1 = u2 + 1;
	}
	//��ԭʼ������ֻ��һ�������Ԫ��˳���ŵ�����swap
	for (i = l1; i < n; i++, m++)  swap[m] = a[i];
}


//��·�鲢�����㷨����
void MergeSort(int a[], int n)
{
	//�鲢���ȴ�1��ʼ
	int i, k = 1;
	int *swap;

	//���붯̬����ռ�
	swap = (int *)malloc(sizeof(int) * n);

	while (k<n)
	{
		//���ù鲢����Merge (a, n, swap, k)
		Merge(a, n, swap, k);
		for (i = 0; i < n; i++)
		{
			a[i] = swap[i]; //��Ԫ�ش���ʱ����swap�Ż�����a��
		}
		k = 2 * k;//�鲢���ȼӱ�
	}
	free(swap);//�ͷŶ�̬����ռ�
}