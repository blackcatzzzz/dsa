// Source : https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/er-fen-cha-zhao-xiang-jie

#include "common.h"

// 左闭右开 [low, hi)
class Solotion_A{
public:
	int binarySearch(vector<int>& nums, int target){
		if(nums.size() == 0) return -1;
		int low = 0, hi = nums.size(); // 搜索区间[low, hi)
		while(low < hi){ //  终止条件low == hi
			int mid = low + (hi - low) / 2;
			if(nums[mid] == target)
				return mid;	// 直接返回
			else if(nums[mid] < target)
				low = mid + 1;
			else if(nums[mid] > target)
				hi = mid;
		}

		return -1;
	}

	// 寻找左边界 [1,2,2,2,3] return 1
	int left_bound(vector<int>& nums, int target){
		if(nums.size() == 0) return -1;
		int low = 0, hi = nums.size(); // 搜索区间[low, hi)
		while(low < hi){ //  终止条件low == hi
			int mid = low + (hi - low) / 2;
			if(nums[mid] == target)
				hi = mid;	// 缩紧右边界
			else if(nums[mid] < target)
				low = mid + 1;
			else if(nums[mid] > target)
				hi = mid;
		}

		// 处理边界情况
		if(low == nums.size() || nums[low] != target)
			return -1;

		return low;		
	}

	// 寻找右边界 [1,2,2,2,3] return 3
	int right_bound(vector<int>& nums, int target){
		if(nums.size() == 0) return -1;
		int low = 0, hi = nums.size(); // 搜索区间[low, hi)
		while(low < hi){ //  终止条件low == hi
			int mid = low + (hi - low) / 2;
			if(nums[mid] == target)
				low = mid + 1;	// 缩紧左边界
			else if(nums[mid] < target)
				low = mid + 1;
			else if(nums[mid] > target)
				hi = mid;
		}

		// 处理边界情况, 因为nums[mid] == target时, low = mid + 1, 所以mid = low - 1
		if(low == 0 || nums[low - 1] != target)
			return -1;

		return low - 1;
	}
};

// 左闭右闭 [low, hi]
class Solotion_B{
public:
	int binarySearch(vector<int>& nums, int target){
		if(nums.size() == 0) return -1;
		int low = 0, hi = nums.size() - 1; // 搜索区间[low, hi]
		while(low <= hi){ //  终止条件 low = hi + 1, 即 low > hi
			int mid = low + (hi - low) / 2;
			if(nums[mid] == target)
				return mid;	// 直接返回
			else if(nums[mid] < target)
				low = mid + 1;
			else if(nums[mid] > target)
				hi = mid - 1;
		}

		return -1;
	}

	// 寻找左边界 [1,2,2,2,3] return 1
	int left_bound(vector<int>& nums, int target){
		if(nums.size() == 0) return -1;
		int low = 0, hi = nums.size() - 1; // 搜索区间[low, hi]
		while(low <= hi){ //  终止条件 low = hi + 1, 即 low > hi
			int mid = low + (hi - low) / 2;
			if(nums[mid] == target)
				hi = mid - 1;	// 缩紧右边界
			else if(nums[mid] < target)
				low = mid + 1;
			else if(nums[mid] > target)
				hi = mid - 1;
		}

		// 处理边界情况
		if(low == nums.size() || nums[low] != target)
			return -1;

		return low;		
	}

	// 寻找右边界 [1,2,2,2,3] return 3
	int right_bound(vector<int>& nums, int target){
		if(nums.size() == 0) return -1;
		int low = 0, hi = nums.size() - 1; // 搜索区间[low, hi]
		while(low <= hi){ //  终止条件 low = hi + 1, 即 low > hi
			int mid = low + (hi - low) / 2;
			if(nums[mid] == target)
				low = mid + 1;	// 缩紧左边界
			else if(nums[mid] < target)
				low = mid + 1;
			else if(nums[mid] > target)
				hi = mid - 1;
		}

		// 处理边界情况, 因为nums[mid] == target时, low = mid + 1, 所以mid = low - 1
		if(low == 0 || nums[low - 1] != target)
			return -1;

		return low - 1;
	}
};

int main()
{
	int a[] = {1,2,2,4,5,5,7,8,9,10};
	int n = sizeof a / sizeof(int);
	vector<int> nums(a, a + n);
	Solotion_A sa;
	Solotion_B sb;
	cout << "1: | SA: " << sa.binarySearch(nums, 1) << " | SB: " << sb.binarySearch(nums, 1) << endl;
	cout << "5: | SA:" << sa.binarySearch(nums, 5) << " | SB: " << sb.binarySearch(nums, 5) << endl;
	cout << "0: | SA:" << sa.binarySearch(nums, 0) << " | SB: " << sb.binarySearch(nums, 0) << endl;
	cout << "left 5 | SA: " << sa.left_bound(nums, 5) << " | SB: " << sb.left_bound(nums, 5) <<  endl;
	cout << "left 0 | SA: " << sa.left_bound(nums, 0) << " | SB: " << sb.left_bound(nums, 0) <<  endl;
	cout << "left 11 | SA: " << sa.left_bound(nums, 11) << " | SB: " << sb.left_bound(nums, 11) <<  endl;
	cout << "right 5 | SA: " << sa.right_bound(nums, 5) << " | SB: " << sb.right_bound(nums, 5) <<  endl;
	cout << "right 0 | SA: " << sa.right_bound(nums, 0) << " | SB: " << sb.right_bound(nums, 0) <<  endl;
	cout << "right 11 | SA: " << sa.right_bound(nums, 11) << " | SB: " << sb.right_bound(nums, 11) <<  endl;
	// getchar();
	return 0;
}