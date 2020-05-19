#include <stdio.h>

// [lo, hi]
int partition(int *a, int lo, int hi)
{
	int pivot = a[lo];
	int i = lo, j = hi;
	while (i < j)
	{
		while (i < j && pivot <= a[j])
			--j;
		a[i] = a[j];

		while (i < j && a[i] <= pivot)
			++i;

		a[j] = a[i];
	}

	a[i] = pivot;
	
	return i;
}

// [lo, hi]
void quickSort(int * a, int lo, int hi)
{
	if (lo >= hi)
		return;

	int index = partition(a, lo, hi);
	quickSort(a, lo, index - 1);
	quickSort(a, index + 1, hi);

	return;
}

void pringArray(int *a, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);

	printf("\n");
}

int main()
{
	int a[] = {4, 2, 5, 1, 7, 8, 2, 9, 3, 10};
	int n = sizeof(a) / sizeof(int);
	pringArray(a, n);
	quickSort(a, 0, n - 1);
	pringArray(a, n);
	getchar();
	return 0;
}