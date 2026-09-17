#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);

        // 数字 2 只能拆分成 1 1
        dp[2] = 1;

        for (int i = 3; i <= n; ++i)
        {
            for (int j = 1; j <= i - 1; ++j)
            {
                dp[i] = max(max((i - j) * j, dp[i - j] * j), dp[i]);
            }
        }

        return dp[n];
    }
};