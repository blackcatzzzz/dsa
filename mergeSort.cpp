#include <iostream>

using namespace std;

void printArray(int * a, int len)
{
	for (size_t i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

// ����廪�˿�����ʦ�����ݽṹ�γ̣�
// ���ƴ����ָ�ڱ�������a,b,c�Ķ�λ
// ��ͬ��: ����ʱ������߼�����Ȼ�������ظ����룬�����������
void merge(int *data, int lo, int mi, int hi)
{
	int *a = data + lo;

	int lb = mi - lo;
	int *b = new int[lb];
	for (size_t i = 0; i < lb; i++)
	{
		b[i] = a[i];
	}


	int lc = hi - mi;
	int *c = data + mi;

	int i = 0, j = 0, k = 0;

	while (j < lb && k < lc)
	{
		if (b[j] <= c[k])
		{
			a[i++] = b[j++];
		}
		else
		{
			a[i++] = c[k++];
		}
	}

	while (j < lb)
	{
		a[i++] = b[j++];
	}

	while (k < lc)
	{
		a[i++] = c[k++];
	}

	delete[] b;
}

// [lo,hi)
void mergeSort(int * data, int lo, int hi)
{
	// ������1��Ԫ��ʱ������
	if (hi - lo < 2)
	{
		return;
	}

	int mi = (lo + hi) >> 1;
	mergeSort(data, lo, mi);
	mergeSort(data, mi, hi);

	printArray(data + lo, mi - lo);
	printArray(data + mi, hi - mi);

	cout << endl;

	merge(data, lo, mi, hi);
}

int main()
{
	int data[] = { 1, 5, 2, 10, 8, 7, 11, 3, 5, 2, 6 };
	int len = sizeof data / sizeof(int);
	mergeSort(data, 0, len);
	printArray(data, len);
	getchar();

	return 0;
}

