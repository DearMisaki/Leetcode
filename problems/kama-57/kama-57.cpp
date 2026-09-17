#include <bits/stdc++.h>

using namespace std;


// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。 
// 每次你可以爬至多m (1 <= m < n)个台阶。你有多少种不同的方法可以爬到楼顶呢？ 

int main()
{
    int n, m;

    cin >> n >> m;

    vector<int> dp(n + 1, 0);

    dp[0] = 1;

    // 背包
    for (int i = 0; i <= n; ++i)
    {
        // 物品
        for (int j = 1; j <= m; j++)
        {
            if (i >= j)
            {
                dp[i] = dp[i] + dp[i - j];
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}