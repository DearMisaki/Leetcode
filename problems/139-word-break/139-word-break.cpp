#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        auto index = s.begin();

        while (index != s.end())
        {
            for (auto const& word : wordDict)
            {
                if (word.compare(index - s.begin(), word.size(), s))
                {
                    index += word.size();
                    break;
                }
            }
        }

        if (index == s.end())
        {
            return true;
        }
        else
            return false;
    }

};