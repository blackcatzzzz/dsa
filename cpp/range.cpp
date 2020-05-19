//@Descriptioin
//Let S be a set of n integral points on the x - axis.For each given interval[a, b], you are asked to count the points lying inside.
//
//@Input
//The first line contains two integers : n(size of S) and m(the number of queries).
//
//The second line enumerates all the n points in S.
//
//Each of the following m lines consists of two integers a and b and defines an query interval[a, b].
//
//@Output
//The number of points in S lying inside each of the m query intervals.
//
//@Example
//Input
//
//5 2
//1 3 7 9 11
//4 6
//7 12
//Output
//
//0
//3
//@Restrictions
//0 <= n, m <= 5 * 10 ^ 5
//
//For each query interval[a, b], it is guaranteed that a <= b.
//
//Points in S are distinct from each other.
//
//Coordinates of each point as well as the query interval boundaries a and b are non - negative integers not greater than 10 ^ 7.
//
//Time: 2 sec
//
//  Memory : 256 MB

#include <cstdio>

using namespace std;

void printArr(int a[], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

// 查找第一个在左边界中的元素
// [lo,hi)
int binarySearch_firstLeftElem(int a[], int e, int lo, int hi)
{
	while (hi - lo > 1)
	{
		int mi = (lo + hi) >> 1;
		if (e < a[mi])
			hi = mi;
		else
			lo = mi;
	}

	return e <= a[lo] ? lo : ++lo;
}

int binarySearch_rightLeftElem(int a[], int e, int lo, int hi)
{
	while (hi - lo > 1)
	{
		int mi = (lo + hi) >> 1;
		if (e < a[mi])
			hi = mi;
		else
			lo = mi;
	}

	return a[lo] <= e ? lo : -1;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(int *a, int lo, int hi)
{
	//int pivot = (lo + hi) >> 1;
	int pivot = a[lo];
	int i = lo, j = hi;
	while (i < j)
	{
		while (a[j] >= pivot && i < j)
			j--;
		while (a[i] <= pivot && i < j)
			i++;
		swap(a[i] , a[j]);
	}

	swap(a[lo], a[i]);

	return i;
}

// [lo ,hi]
void quikSort(int *a, int lo, int hi)
{
	if (lo >= hi)
	{
		return;
	}

	int index = partition(a, lo ,hi);
	quikSort(a, lo, index - 1);
	quikSort(a, index + 1, hi);

}

int main()
{
	int N, M;
	scanf("%d %d", &N , &M);
	int * a = new int[N];
	for (size_t i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}

	quikSort(a, 0 , N - 1);

	int lb, rb;

	while (M--)
	{
		scanf("%d %d", &lb, &rb);
		int lp = binarySearch_firstLeftElem(a, lb, 0, N);
		//printf("lp:%d ", lp);
		if (lp == N)
		{
			printf("0\n");
			continue;
		}

		int rp = binarySearch_rightLeftElem(a, rb, 0, N);
		//printf("rp:%d ", rp);
		if (rp == -1)
		{
			printf("0\n");
			continue;
		}

		printf("%d\n", rp - lp + 1);
	}

	//printArr(a, N);

	//getchar();
	//getchar();

	return 0;
}