#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        // 长度为 1
        if (s.size() == 1)
        {
            return s;
        }

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

        // 长度为 1 的串
        for (int i = 0; i < s.size(); ++i)
        {
            dp[i][i] = 1;
        }

        int max_n = 1;
        int start = 0;

        // 遍历长度
        for (int n = 2; n <= s.size(); ++n)
        {
            // 起始点
            for (int i = 0; i < s.size(); ++i)
            {
                // 加上长度后越界了
                if (i + n - 1 > s.size() - 1)
                    break;

                // 长度为 2 或 3
                if ((n == 2 || n == 3) && s[i] == s[i + n - 1])
                {
                    dp[i][i + n - 1] = 1;
                }
                
                if (n > 3)
                {
                    dp[i][i + n - 1] = dp[i + 1][i + n - 2] && s[i] == s[i + n - 1];
                }

                if (dp[i][i + n - 1])
                {
                    max_n = n;
                    start = i;
                }

            }

        }

        return s.substr(start, max_n);
    }
};