#include <vector>

using namespace std;

class Solution
{
public:
	int search(vector<int> &nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;

		while (left <= right)
		{
			int middle = left + ((right - left) / 2);
			if (nums.at(middle) == target) {
				return middle;
			} else if (nums.at(middle) < target) {
				left = middle + 1;
			} else {
				right = middle - 1;
			}
		}
		return -1;
	}
};