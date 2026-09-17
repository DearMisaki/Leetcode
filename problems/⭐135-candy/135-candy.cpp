#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> Candies(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
                Candies[i] = Candies[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                Candies[i] = max(Candies[i], Candies[i + 1] + 1);
        }
        return accumulate(Candies.begin(), Candies.end(), 0);
    }
};

/*

我们可以通过一个简单的例子来理解： 评分序列：[1, 2, 8, 4, 3, 1]

    初始状态：[1, 1, 1, 1, 1, 1]

    左往右看：

        2 > 1 → [1, 2, 1, 1, 1, 1]

        8 > 2 → [1, 2, 3, 1, 1, 1]

        其他不满足 >，保持。结果：[1, 2, 3, 1, 1, 1]

    右往左看：

        3 > 1 → [1, 2, 3, 1, 2, 1]

        4 > 3 → [1, 2, 3, 3, 2, 1]

        8 > 4 → 原本是 3，现在需要 max(3, 3+1) = 4。结果：[1, 2, 4, 3, 2, 1]

*/