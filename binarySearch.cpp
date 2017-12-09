#include <iostream>

using namespace std;

// °æ±¾C
// [lo, hi)
int binarySearch_C(int * a, int e, int lo, int hi)
{
	while (lo < hi)
	{
		int mi = (lo + hi) >> 1;
		e < a[mi] ? hi = mi : lo = mi + 1;
	}

	return --lo;
}

// °æ±¾B
// [lo, hi)
int binarySearch_B(int * a, int e, int lo, int hi)
{
	while (hi - lo > 1)
	{
		int mi = (lo + hi) >> 1;
		e < a[mi] ? hi = mi : lo = mi;
	}

	return e == a[lo] ? lo : -1;
}

// °æ±¾A
// [lo, hi)
int binarySearch_A(int * a, int e, int lo, int hi)
{
	while (lo < hi)
	{
		int mi = (lo + hi) >> 1;
		if (e < a[mi])
		{
			hi = mi;
		}
		else if (a[mi] < e)
		{
			lo = mi + 1;
		}
		else
		{
			return mi;
		}
	}

	return -1;
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof a / sizeof(int);
	int e = 4;
	cout << binarySearch_A(a, e, 0, n) << endl;
	cout << binarySearch_B(a, e, 0, n) << endl;
	cout << binarySearch_C(a, e, 0, n) << endl;
	getchar();
	return 0;
}

