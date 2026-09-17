#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int x = sqrt(n);

        vector<int> squares;
        vector<int> dp(n + 1, n + 1);

        // n = 0，不存在 这种组合
        dp[0] = 0;

        for (int i = 1; i <= x; ++i)
        {
            squares.push_back(i * i);
        }

        for (int i = 0; i < squares.size(); ++i)
        {
            for (int j = squares[i]; j <= n; ++j)
            {
                dp[j] = min(dp[j], dp[j - squares[i]] + 1);
            }
        }

        return dp[n];
    }
};