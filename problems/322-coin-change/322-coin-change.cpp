#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // 这里用amount + 1 代表 MAX，
        // 千万不能用INT_MAX，因为存在
        // MAX + 1的操作，可能溢出

        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        // 物品
        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = coins[i]; j <= amount; ++j)
            {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};