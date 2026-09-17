#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int size = prices.size();
        vector<vector<int>> dp(size, vector<int>(2));

        // 收盘卖出，手中 0 支
        dp[0][0] = 0;
        // 收盘买入，手中 1 支
        dp[0][1] = -prices[0];

        for (int i = 1; i < size; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[size - 1][0];
    }
};