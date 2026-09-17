#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        int middle;

        while (left <= right)
        {
            int middle = left + ((right - left) / 2);

            if (nums[middle] < target)
            {
                ++left;
            } else if (nums[middle] > target)
            {
                --right;
            } else
            {
                // 此时 nums[middle] < target
                int i = middle, j = middle + 1;
                
                while (i >= 0 && nums[i] == target)
                    --i;

                while (j <= nums.size() - 1 && nums[j] == target)
                    ++j;

                return vector<int> {i + 1, j - 1};
            }
        }
        // 未找到 target
        return vector<int> {-1, -1};
    }
};