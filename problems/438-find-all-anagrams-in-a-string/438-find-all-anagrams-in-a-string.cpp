#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        
        vector<int> result;

        if (s.size() < p.size())
            return result;

        int count[26];

        for (int i = 0; i < p.size(); ++i)
        {
            count[s[i] - 'a']++;
            count[p[i] - 'a']--;
        }

        int diff = 0;

        for (int i = 0; i < 26; ++i)
        {
            if (count[i] != 0)
                ++diff;
        }

        if (diff == 0)
        {
            result.push_back(0);
        }

        for (int i = 0; i < s.size() - p.size(); ++i)
        {
            // 去掉开头的元素
            if (count[s[i] - 'a'] == 1)
            {
                --diff;
            }
            else if (count[s[i] - 'a'] == 0)
            {
                ++diff;
            }

            --count[s[i] -'a'];

            if (count[s[i + p.size()] - 'a'] == -1)
            {
                --diff;
            }
            else if (count[s[i + p.size()] - 'a'] == 0)
            {
                ++diff;
            }

            ++count[s[i + p.size()] - 'a'];

            if (diff == 0)
            {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};