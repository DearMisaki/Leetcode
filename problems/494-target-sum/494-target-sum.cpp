#include <bits/stdc++.h>

using namespace std;

// gemini 解析 https://docs.google.com/document/d/1xM5pQFNFEgAubDnSkZFgcOZ331H_eWrUZ6bxMAASTao/edit?usp=sharing

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > sum) return 0;

        // 见公式推导
        if ((sum + target) % 2 == 1) return 0;

        vector<int> dp((sum + target) / 2 + 1, 0);

        // 背包大小为 0，那么不装任何东西就可以装满，也是一种方法
        dp[0] = 1;

        // 遍历物品
        for (int i = 0; i < nums.size(); ++i)
        {
            // 遍历背包
            for (int j = dp.size() - 1; j >= nums[i]; --j)
            {
                // 更新dp数组
                // 1. 不加上当前物品，已经右上面的步骤推出来了
                // 2. 加上当前物品，简化成大小为 j - nums[i] 的背包
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }

        return dp[(sum + target) / 2];
    }
};