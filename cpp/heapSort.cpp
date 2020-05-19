#include <cstdio>

using namespace std;

#define InHeap(n,i)			( ( -1 < i && i < n ) )
#define	Parent(i)			( ( i - 1 ) >> 1 )
#define LastInternal(n)		Parent( n - 1 )
#define LChild(i)			( 1 + i * 2 )
#define RChild(i)			( ( 1 + i ) * 2 )
#define LChildValid(n, i)	InHeap(n, LChild(i))
#define RChildValid(n, i)	InHeap(n, RChild(i))
#define Bigger(a, i, j)		( ( a[i] < a[j] ) ? j : i )	// 相等则取i
#define ProperParent(a , n, i)	/*父子（至多）三者中的大者*/ \
			( RChildValid(n, i) ? Bigger( a, Bigger( a, i, LChild(i) ), RChild(i) ) : \
			( LChildValid(n, i) ? Bigger( a, i , LChild(i) )  : i \
			) \
			)
				

template <typename T> void swap(T &a, T &b)
{
	T c(a); a = b; b = c;
}

void percolateDown(int *a, int n, int i)
{
	int j = 0;
	while (i != (j = ProperParent(a, n, i)))
	{
		swap(a[i], a[j]);
		i = j;
	}
}

// 对n个元素的数组a进行堆排序
void heapSort(int *a, int n)
{
	// build heap
	for (int i = LastInternal(n); InHeap(n, i); --i)
	{
		percolateDown(a, n ,i);
	}

	// sort
	for (int i = n - 1; i > 0; --i)
	{
		swap(a[0], a[i]);
		percolateDown(a, i, 0);
	}

}

void printArray(int * a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int a[] = { 2, 1, 5, 7, 13, 1, 14, 3 , 2, 8, 9, 10 };
	int n = sizeof a / sizeof(int);
	printArray(a, n);
	heapSort(a, n);
	printArray(a, n);
	getchar();
    return 0;
}

