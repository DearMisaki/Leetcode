#include <bits/stdc++.h>

using namespace std;

// Gemini 解析
// https://docs.google.com/document/d/17qtohGLGJvCILfGdaiUPRyZ_x-sMQFxpNzm9-124yOw/edit?usp=sharing

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);

        int target = sum / 2;

        vector<int> dp(target + 1, 0);

        // 因为 除法会向下取整，所以总是会小于等于sum的一半，代表的是 negative
        for (int i = 0; i < stones.size(); ++i)
        {
            for (int j = target; j >= stones[i]; --j)
            {
                dp[j] = max(dp[j], stones[i] + dp[j - stones[i]]);
            }
        }

        // positive - negative 就等于之间最小的差值了
        // 为什么是最小，因为我们使用背包装的时候就是找到最接近于 sum / 2 这个总重量的所有石头
        return sum - dp[target] - dp[target];
    }
};