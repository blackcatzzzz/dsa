/*******************************
*	最长递增子序列
*	@auther cat zhang
*	@date 2018/1/14
********************************/

#include <stdio.h>
#include <vector>

using namespace std;

// 解法一：转化为最长公共子序列问题：排序+LCS

// 解法二：动态规划


int max(vector<int> & a)
{
	int max = a[0];
	for (size_t i = 1; i < a.size(); i++)
	{
		if (a[i] > max)
			max = a[i];
	}

	return max;
}

// 动态规划，时间复杂度：N的平方
int LIS_DP_N2(vector<int> & a)
{
	vector<int> LIS(a.size());	// LIS[i] : 到第i个元素的最长递增子序列长度
	vector<int> MaxV(a.size() + 1);	// MaxV[i] : 长度为i的LIS的最大元素中的最小值

	MaxV[0] = INT_MIN; // 保证任何元素自身成为长度为1的LCS
	int maxLISLen = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		int j = maxLISLen;
		for (; j >= 0; --j)
		{
			if (a[i] > MaxV[j])
			{
				LIS[i] = j + 1;
				break;
			}
		}

		if (LIS[i] > maxLISLen)
		{
			maxLISLen = LIS[i];
			MaxV[LIS[i]] = a[i];
		}
		else if (MaxV[j] < a[i] && a[i] < MaxV[j + 1])
			MaxV[j + 1] = a[i];
	}

	return max(LIS);
}

int BinarySearch(int *array, int value, int nLength)
{
	int begin = 0;
	int end = nLength - 1;
	while (begin <= end)
	{
		int mid = begin + (end - begin) / 2;
		if (array[mid] == value)
			return mid;
		else if (array[mid] > value)
			end = mid - 1;
		else
			begin = mid + 1;
	}
	return begin;
}

// [lo, hi]，如果没找到，则返回第一个小于e的位置
// -1表示均比e大，只能在数组左侧外面虚拟一个哨兵位置
int binarySearch(vector<int>& array, int lo, int hi, int e)
{
	int i = lo, j = hi;
	while (i < j)
	{
		int mi = (i + j) >> 1;
		if (e < array[mi])
			j = mi - 1;
		else if (array[mi] < e)
			i = mi + 1;
		else
			return mi;
	}

	if (i == lo && e < array[i])
		return -1;
	if (e < array[i])
		--i;
	return i;
}

 // 动态规划，利用二分查找优化，达到N*LogN
int LIS_DP_NLOGN(vector<int> & a)
{
	vector<int> LIS(a.size());	// LIS[i] : 到第i个元素的最长递增子序列长度
	vector<int> MaxV(a.size() + 1);	// MaxV[i] : 长度为i的LIS的最大元素中的最小值

	MaxV[0] = INT_MIN; // 保证任何元素自身成为长度为1的LCS
	int maxLISLen = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		int j = binarySearch(MaxV, 0, maxLISLen, a[i]);
		//j = (j == -1 ? 0 : j); 由于MaxV[0] = INT_MIN， 故j不可能为-1，可省略
		if (MaxV[j] == a[i])
			continue;	// 相同则继续，否则变成了最长非降序列
		LIS[i] = j + 1;

		if (LIS[i] > maxLISLen)
		{
			maxLISLen = LIS[i];
			MaxV[LIS[i]] = a[i];
		}
		else if (MaxV[j] < a[i] && a[i] < MaxV[j + 1])
			MaxV[j + 1] = a[i];
	}

	return max(LIS);
}

void printVec(vector<int>& a)
{
	for (size_t i = 0; i < a.size(); i++)
		printf("%d ", a[i]);

	printf("\n");
}

int main()
{
	int b[] = { 1, 2, 3, 5, 7 };
	int i = BinarySearch(b, 6, 5);
	vector<int> array = { 1, -1, 2, -3, 4, -5, 6, -7 };
	array = { 5,6,7,1,2,3,4,5,5,8};
	printVec(array);
	printf("LIS: %d", LIS_DP_NLOGN(array));

	getchar();
	return 0;
}