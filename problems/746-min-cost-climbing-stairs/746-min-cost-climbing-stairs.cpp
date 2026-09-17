#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = cost[0];
        int b = cost[1];
        int c = 0;

        for (int i = 2; i < cost.size(); ++i)
        {
            c = cost[i] + min(a, b); // 当前点位起跳开销加上，前面点位跳过来的开销

            a = b;

            b = c;

            // 最后一步，a 为倒数第二个点，b 为倒数第一个点
        }

        return min(a, b);
    }
};

class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size());

        dp[0] = 0;
        dp[1] = 0;

        // 10个台阶 0 - 9，但是还存在一个楼顶所以是下标10
        for (int i = 2; i <= cost.size(); ++i)
        {
            dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
        }

        return dp[cost.size()];
    }
};