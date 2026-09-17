#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int result = 0;

        if (s.empty())
            return result;

        int j = 0;
        unordered_set<char> uset;

        for (int i = 0; i < s.size(); ++i)
        {
            // set 还未出现重复字符
            while (j < s.size() && uset.count(s[j]) == 0)
            {
                uset.insert(s[j]);
                ++j;
            }

            // 出现重复字符，代表找到从 i 开始的极长序列
            result = max(result, j - i);

            uset.erase(s[i]);
        }

        return result;
    }
};