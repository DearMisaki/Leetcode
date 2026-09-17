#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int last[26];

        // 找到每个字符最后一次出现的位置
        for (int i = 0;i < s.size(); ++i)
        {
            last[s[i] - 'a'] = i;
        }

        int end = 0;
        int start = 0;

        vector<int> res;

        for(int i = 0; i < s.size(); ++i)
        {
            end = max(end, last[s[i] - 'a']);

            if (i == end)
            {
                res.push_back(i - start + 1);
                start = end + 1;            
            }
        }

        return res;
    }
};