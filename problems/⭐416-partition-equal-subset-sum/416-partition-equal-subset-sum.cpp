#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum %2 == 1) return false;

        int target = sum / 2;

        vector<int> dp(target + 1, 0);

        // 循环到任意一行，能装满背包，那么后面的行都可以装满背包
        // 相当于后面的行直接继承前面的行
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = target; j >= nums[i]; --j)
            {
                dp[j] = max(dp[j], nums[i] + dp[j - nums[i]]);
            }
        }

        // 看看能不能装满背包
        // 任意一行可以装满背包，都说可以选出和为 sum / 2 的 N 个元素
        return dp[target] == target;
    }
};