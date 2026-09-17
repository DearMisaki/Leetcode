#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;

    cin >> m >> n;

    vector<int> weight(m, 0);
    vector<int> value(m, 0);

    for (int i = 0; i < m; ++i)
    {
        cin >> weight[i];
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> value[i];
    }

    vector<vector<int>> dp(m, vector<int>(n + 1, 0));

    for (int j = 0; j <= n; ++j)
    {
        if (j >= weight[0])
        {
            dp[0][j] = value[0];
        }
    }

    for (int i = 1; i < m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (j < weight[i])
                // 不足以加入当前物品
                dp[i][j] = dp[i - 1][j];
            else
                // 继承上面的物品 与 加入当前物品（空间足够时同时加入上面物品）比较大小
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }

    // 一步步继承下来，肯定能在最后一行得到最大结果
    cout << dp[m - 1][n] << endl;

    return 0;
}