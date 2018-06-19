#include <vector>
#include <iostream>

using namespace std;


/*
* 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
* 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
*/

// https://blog.csdn.net/hongchh/article/details/52242415
// https://www.cnblogs.com/coffy/p/5896541.html
class Solution {
public:
	int InversePairs(vector<int> data) {
		if (data.size() == 0)
			return 0;

		vector<int> copy(data);

		return inversPairs(data, 0, data.size(), copy) % 1000000007;
	}

private:
	// data[lo, hi)
	unsigned long long inversPairs(vector<int> &data, int lo, int hi, vector<int> &copy)
	{
		if (hi - lo < 2)
			return 0;

		int mi = (lo + hi) >> 1;
		unsigned long long left = inversPairs(data, lo, mi, copy);
		unsigned long long right = inversPairs(data, mi, hi, copy);

		unsigned long long count = 0;
		// merge and count inversPairs
		int i = mi - 1, j = hi - 1, k = hi - lo - 1;
		while (i >= lo && j >= mi)
		{
			if (data[i] > data[j])
			{
				copy[k--] = data[i--];
				count += j - mi + 1;
			}
			else
			{
				copy[k--] = data[j--];
			}
		}

		while (i >= lo)
			copy[k--] = data[i--];
		while (j >= mi)
			copy[k--] = data[j--];

		for (int i = lo; i < hi; i++)
		{
			data[i] = copy[i - lo];
		}

		return left + right + count;
	}
};

// 2018.6.19
class Solution1 {
public:
	int InversePairs(vector<int> data) {
		if (data.size() == 0)
			return 0;

		vector<int> copy(data.size());
		//copy.reserve(data.size()); // 新元素未构造，不能使用[]
		return inversePaires(data, 0, data.size() - 1, copy) % 1000000007;
	}

private:
	// [lo, hi]
	unsigned long long inversePaires(vector<int> &data, int lo, int hi, vector<int> &copy)
	{
		if (lo >= hi)
			return 0;

		int mid = (lo + hi) >> 1;
		unsigned long long left = inversePaires(data, lo, mid, copy);
		unsigned long long right = inversePaires(data, mid + 1, hi, copy);

		// merge and count
		int i = lo, j = mid + 1, k = 0;
		unsigned long long count = 0;
		while (i <= mid && j <= hi)
		{
			if (data[i] <= data[j])
				copy[k++] = data[i++];
			else
			{
				copy[k++] = data[j++];
				count += mid - i + 1;
			}
		}

		while (i <= mid)
			copy[k++] = data[i++];

		while (j <= hi)
			copy[k++] = data[j++];

		for (int k = 0; k <= hi - lo; ++k)
			data[k + lo] = copy[k];

		return left + right + count;
	}
};

int main()
{
	vector<int> v = {2,1,3,7,4,6,5,8};
	Solution1 s;
	cout << s.InversePairs(v) << endl;
	getchar();
	return 0;
}