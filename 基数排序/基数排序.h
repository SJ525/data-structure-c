#include"��ʽ����.h"
void RadixSort(int a[], int n, int m, int d)
{
	int i, j, k, power = 1;
	LQueue* tub;			//��d�����ж���Ϊ��̬����
	tub = (LQueue*)malloc(sizeof(LQueue) * d);
	for (i = 0; i < d; i++)
		QueueInitiate(&tub[i]);	//d�����зֱ��ʼ��
	for (i = 0; i < m; i++) // ����m�ηź���
	{
		  if (i == 0) power = 1;
		  else power = power * d;
		  for (j = 0; j < n; j++)			//��
		  {
			k = a[j] / power - (a[j]/ (power * d)) * d;
			QueueAppend(&tub[k], a[j]);//��a[j]�����k������
		  }
		  k = 0;
		for (j = 0; j < d; j++)			//����
		while (QueueNotEmpty(tub[j]) != 0)
		{
			QueueDelete(&tub[j], &a[k]);//�Ӹ������л���
			k++;
		}
	}
}
