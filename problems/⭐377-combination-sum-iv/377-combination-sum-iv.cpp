#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<uint64_t> dp(target + 1, 0);

        // 必要
        dp[0] = 1;

        // 组合（不考虑元素位置）是外层遍历物品，内层遍历背包
        // 排列（要考虑物品位置）是外层遍历背包，内层遍历物品
        // 因为内层遍历物品的话，每个背包容量都可以考虑到所有的物品，而全排列就是
        // 每个位置考虑所有物品
        for (int i = 1; i <= target; ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
            {
                if (i >= nums[j])
                {
                    dp[i] = dp[i] + dp[i - nums[j]];
                }
            }
        }

        return dp[target];
    }
};