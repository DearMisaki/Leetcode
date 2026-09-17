#include <vector>
#include <limits>
#include <cmath>

using namespace std;

class Solution
{
public:
    // 前缀和
    int minSubArrayLen(int target, vector<int> &nums)
    {
        vector<int> sums(nums.size() + 1, 0);
        // 构建前缀和 sums[0] = 0; sums[i] = nums[0] + ... + nums[i - 1];
        for (int i = 1; i < sums.size(); ++i)
        {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        int min_size = numeric_limits<int>::max();

        for (int i = 0; i < nums.size(); ++i)
        {
            // sum[j] - sum[i] >= target; sum[j] >= target + sums[i];
            // 针对 nums 每一个位置, 寻找一个 j
            auto index = lower_bound(sums.begin(), sums.end(), sums[i] + target);
            if (index != sums.end())
            {
                min_size = min((long)min_size, index - sums.begin() - i);
            }
        }

        return min_size < numeric_limits<int>::max() ? min_size : 0;
    }
};

class Solution2
{
public:
    // 滑动窗口
    int minSubArrayLen(int target, vector<int> &nums)
    {
        if (nums.empty()) return 0;

        int sum = 0;
        int min_len = numeric_limits<int>::max();

        for (int i = 0, j = 0; j < nums.size(); ++j)
        {
            sum += nums[j];

            while (sum >= target)
            {
                min_len = min(min_len, j - i + 1);
                sum -= nums[i];
                ++i;
            }
        }
        return min_len == numeric_limits<int>::max() ? 0 : min_len;
    }
};