#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (k <= 0 || input.size() == 0 || (unsigned long)k > input.size())
			return vector<int>();
		vector<int> output;
		partition_solution(input, k, output);
		return output;
	}

private:
	void heap_solution(vector<int> &input, int k, vector<int> &output)
	{
		priority_queue<int, vector<int>> pq;
		for (int i = 0; i < k; ++i)
			pq.push(input[i]);
		for (unsigned int i = k; i < input.size(); ++i)
		{
			if (pq.top() > input[i])
			{
				pq.pop();
				pq.push(input[i]);
			}
		}

		while (!pq.empty())
		{
			output.push_back(pq.top());
			pq.pop();
		}

		return;
	}

	void partition_solution(vector<int> &input, int k, vector<int> &output)
	{
		int lo = 0, hi = input.size() - 1;
		while (true)
		{
			int index = partition(input, lo, hi);

			if (index == k - 1)
				break;

			if (k - 1 < index)
				hi = index - 1;
			else
				lo = index + 1;
		}

		for (int i = 0; i < k; ++i)
			output.push_back(input[i]);
		return;
	}

	// [lo, hi]
	int partition(vector<int> &input, int lo, int hi)
	{
		int i = lo, j = hi;
		int pivot = input[i];
		while (i < j)
		{
			while (i < j && pivot <= input[j])
				j--;
			input[i] = input[j];

			while (i < j && input[i] <= pivot)
				i++;
			input[j] = input[i];
		}
		input[i] = pivot;

		return i;
	}
};

int main()
{
	Solution s;
	vector<int> input = { 4,5,1,6,2,7,3,8 };
	vector<int> output = s.GetLeastNumbers_Solution(input, 4);
	getchar();
    return 0;
}

