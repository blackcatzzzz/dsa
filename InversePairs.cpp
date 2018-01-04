#include <stdio.h>
#include <vector>

using namespace std;

// data[lo, hi)
int inversPairs(vector<int> &data, int lo, int hi, vector<int> &copy)
{
	if (hi - lo < 2)
		return 0;

	int mi = (lo + hi) >> 1;
	int left = inversPairs(data, lo, mi, copy);
	int right = inversPairs(data, mi, hi, copy);

	int count = 0;
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

int InversePairs(vector<int>& data) 
{
	if (data.size() == 0)
		return 0;

	vector<int> copy(data);

	return inversPairs(data, 0, data.size(), copy);
}



int main()
{
	vector<int> data = { 7, 5, 6, 4 };
	int count = InversePairs(data);
	getchar();
	return 0;
}

