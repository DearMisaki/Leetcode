#include <vector>
#include <cmath>

using namespace std;

/*
* 题目说明 nums 是非严格递增的，所以平方后的较大的数集中在数组两端，所以 k 要从大到小。
*/

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        int k = nums.size() - 1;

        vector<int> result(nums.size());

        while (left <= right)
        {
            if (fabs(nums[left]) < fabs(nums[right]))
            {
                result[k--] = pow(nums[right], 2);
                --right;
            }
            else
            {
                result[k--] = pow(nums[left], 2);
                ++left;
            }
        }
        return result;
    }
};