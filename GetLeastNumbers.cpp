#include <vector>
#include <queue>

using namespace std;

/*
* ����n���������ҳ�������С��K������
* ��������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
*/

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (input.size() == 0 || k <= 0 || k > input.size())
			return vector<int>();

		vector<int> output;
		heap_solution(input, k, output);
		return output;
	}

private:
	void heap_solution(vector<int> &input, int k, vector<int> &output)
	{
		priority_queue<int> pq;
		int i = 0;
		for (; i < k; ++i)
			pq.push(input[i]);

		for (; i < input.size(); ++i)
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
};