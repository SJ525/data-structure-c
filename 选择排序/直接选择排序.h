//ֱ��ѡ������
void SelectSort(int a[], int n)
{
	int i, j, small;	    
	int temp;

	for (i = 0; i < n - 1; i++)
	{
		//���i������Ԫ�عؼ�����С
		small = i;	 		
		for (j = i + 1; j < n; j++)
		{
			//Ѱ�ҹؼ�����С������Ԫ��
			if (a[j] < a[small]) {
				//��ס��СԪ�ص��±�
				small = j;
			}      
		}

		//����СԪ�ص��±겻Ϊiʱ����λ��
		if (small != i)		
		{
			temp = a[i];
			a[i] = a[small];
			a[small] = temp;
		}
	}
}
