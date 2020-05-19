class Solution {
public:
	// https://blog.csdn.net/yi_afly/article/details/52012593
	int NumberOf1Between1AndN_Solution(int n)
	{
		if (n < 1)
			return 0;
		int count = 0;
		int base = 1;
		int round = n;
		int weight = 0;
		while (round)
		{
			weight = round % 10;
			round /= 10;
			count += round * base;
			if (weight == 1)
				count += n % base + 1;
			else if (weight > 1)
				count += base;
			base *= 10;
		}

		return count;
	}
};

int main()
{
	return 0;
}