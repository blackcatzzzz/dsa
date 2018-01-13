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


void merge_s(int *a, int *b, int lo, int mi, int hi)
{
	int i = lo, j = mi, k = 0;

	while (i < mi && j < hi)
	{
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}

	while (i < mi)
		b[k++] = a[i++];

	while (j < hi)
		b[k++] = a[j++];

	for (size_t i = 0; i < k; i++)
		a[lo + i] = b[i];
}

// for interview, simple �汾
// [lo, hi)
void mergeSort_s(int *a, int * b, int lo, int hi)
{
	if (hi - lo < 2) // ֻʣ1��Ԫ��
		return;

	int mi = (lo + hi) >> 1;
	mergeSort_s(a, b, lo, mi);
	mergeSort_s(a, b, mi, hi);
	merge_s(a, b, lo, mi, hi);

	return;
}

int main()
{
	int data[] = { 1, 5, 2, 10, 8, 7, 11, 3, 5, 2, 6 };
	int len = sizeof data / sizeof(int);

	printArray(data, len);

	//mergeSort(data, 0, len);
	
	int *b = new int[len];
	memset(b, 0x00, len * sizeof(int));
	mergeSort_s(data, b, 0, len);

	printArray(data, len);

	delete[] b;
	getchar();

	return 0;
}

