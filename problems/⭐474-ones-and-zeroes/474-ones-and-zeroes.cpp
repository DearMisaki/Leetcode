#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> nums(strs.size(), vector<int>(2, 0));

        for (int i = 0; i < strs.size(); ++i)
        {
            for(const auto c: strs[i])
            {
                nums[i][c - '0']++;
            }
        }

        // 两个维度的背包
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < nums.size(); ++i)
        {
            // 这里也是遍历两个维度，两两组合计算 MAX
            for (int j = m; j >= nums[i][0]; --j)
            {
                for (int k = n; k >= nums[i][1]; --k)
                {
                    dp[j][k] = max(dp[j][k], dp[j - nums[i][0]][k - nums[i][1]] + 1);
                }
            }
        }

        return dp[m][n];
    }
};