#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> need, window;

        for (char c: t)
        {
            need[c]++;
        }

        int left = 0, right = 0, start = 0;

        int min_len = INT_MAX;

        int valid = 0;

        while (right < s.size())
        {
            char c = s[right];

            if (need.count(c))
            {
                window[c]++;
                // 窗口内 c 的数量与 t 需求相等，代表满足了 这个字符的要求
                if (window[c] == need[c])
                {
                    ++valid;
                }
            }

            // 所有字符满足了，现在要缩小区间
            while (valid == need.size())
            {
                if (right - left + 1 < min_len)
                {
                    start = left;
                    min_len = right - left + 1;
                }

                char d = s[left];

                if (need.count(d))
                {
                    if (window[d] == need[d])
                    {
                        valid--;
                    }

                    window[d] --;
                }

                ++left;
            }

            ++right;
        }

        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};