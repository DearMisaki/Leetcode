#include <vector>

using namespace std;

class Solution
{
public:
    /*
        1. 要求O(logN) 使用二分查找
    */
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        int middle, ans = right + 1;

        while (left <= right)
        {
            middle = ((right - left) >> 1) + left;

            if (target <= nums[middle])
            {
                ans = middle;
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        return ans;
    }
};