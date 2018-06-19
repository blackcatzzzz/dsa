#include <vector>

using namespace std;

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.size() == 0)
			return 0;
		int lo = 0, hi = data.size();
		int index = binarySearch(data, lo, hi, k);
		if (index == -1)
			return 0;
		int firstIndex = index;
		int lastIndex = index;

		int firstHi = index;
		while (lo < firstHi)
		{
			int index = binarySearch(data, lo, firstHi, k);
			if (index != -1)
			{
				firstIndex = index;
				firstHi = index;
			}
		}

		int lastLo = index + 1;
		while (lastLo < hi)
		{
			int index = binarySearch(data, lastLo, hi, k);
			if (index != -1)
			{
				lastIndex = index;
				lastLo = index + 1;
			}
		}

		return lastIndex - firstIndex + 1;

	}

private:
	// [lo, hi)
	int binarySearch(vector<int>& data, int& lo, int& hi, int k)
	{
		while (lo < hi)
		{
			int mi = (lo + hi) >> 1;
			if (data[mi] < k)
				lo = mi + 1; // [mi+1. hi)
			else if (k < data[mi])
				hi = mi; // [lo, mi)
			else
				return mi;
		}

		return -1;
	}
};

// 2018.6.19
class Solution1 {
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.size() == 0)
			return 0;
		int lo = 0, hi = data.size() - 1;
		int index = binarySearch(data, lo, hi, k);
		if (index == -1)
			return 0;
		int firstIndex = index;
		int lastIndex = index;

		int firstHi = index;
		while (lo <= firstHi)
		{
			int index = binarySearch(data, lo, firstHi, k);
			if (index == -1)
				break;
			firstIndex = index;
			firstHi = index - 1;
		}

		int lastLo = index + 1;
		while (lastLo <= hi)
		{
			int index = binarySearch(data, lastLo, hi, k);
			if (index == -1)
				break;
			lastIndex = index;
			lastLo = index + 1;
		}

		return lastIndex - firstIndex + 1;

	}

private:
	// [lo, hi]
	int binarySearch(vector<int>& data, int& lo, int& hi, int k)
	{
		while (lo <= hi)
		{
			int mi = (lo + hi) >> 1;
			if (data[mi] < k)
				lo = mi + 1; // [mi+1. hi]
			else if (k < data[mi])
				hi = mi - 1;// [lo, mi - 1]
			else
				return mi;
		}

		return -1;
	}
};

int main()
{
	getchar();
	return 0;
}