/*******************************
*	�����������
*	@auther cat zhang
*	@date 2018/1/14
********************************/

#include <stdio.h>
#include <vector>

using namespace std;

// �ⷨһ��ת��Ϊ��������������⣺����+LCS

// �ⷨ������̬�滮


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

// ��̬�滮��ʱ�临�Ӷȣ�N��ƽ��
int LIS_DP_N2(vector<int> & a)
{
	vector<int> LIS(a.size());	// LIS[i] : ����i��Ԫ�ص�����������г���
	vector<int> MaxV(a.size() + 1);	// MaxV[i] : ����Ϊi��LIS�����Ԫ���е���Сֵ

	MaxV[0] = INT_MIN; // ��֤�κ�Ԫ�������Ϊ����Ϊ1��LCS
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

// [lo, hi]�����û�ҵ����򷵻ص�һ��С��e��λ��
// -1��ʾ����e��ֻ�������������������һ���ڱ�λ��
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

 // ��̬�滮�����ö��ֲ����Ż����ﵽN*LogN
int LIS_DP_NLOGN(vector<int> & a)
{
	vector<int> LIS(a.size());	// LIS[i] : ����i��Ԫ�ص�����������г���
	vector<int> MaxV(a.size() + 1);	// MaxV[i] : ����Ϊi��LIS�����Ԫ���е���Сֵ

	MaxV[0] = INT_MIN; // ��֤�κ�Ԫ�������Ϊ����Ϊ1��LCS
	int maxLISLen = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		int j = binarySearch(MaxV, 0, maxLISLen, a[i]);
		//j = (j == -1 ? 0 : j); ����MaxV[0] = INT_MIN�� ��j������Ϊ-1����ʡ��
		if (MaxV[j] == a[i])
			continue;	// ��ͬ�����������������ǽ�����
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