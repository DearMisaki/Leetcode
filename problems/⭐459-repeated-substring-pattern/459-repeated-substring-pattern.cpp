#include <string>
#include <iostream>
#include <vector>

using namespace std;


/*
    暴力搜索
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i < s.size(); ++i)
        {
            if (s.size() % i == 0)
            {
                bool match = true;
                for (int j = i; j < s.size(); ++j)
                {
                    if (s[j] != s[j - i])
                    {
                        match = false;
                        break;
                    }
                }

                if (match) return true;
            }
        }
        return false;
    }
};

/*
    KMP 算法
*/

class Solution2 {
public:
    vector<int> get_next(string pattern)
    {
        vector<int> next(pattern.size());

        int i = 0;
        for (int j = 1; j < pattern.size(); ++j)
        {
            while (pattern[i] != pattern[j] && i > 0)
                i = next[i - 1];

            if (pattern[i] == pattern[j])
            {
                ++i;
            }

            next[j] = i;
        }

        return next;
    }

    bool repeatedSubstringPattern(string s) {
        vector<int> next = get_next(s);

        int j = 0;

        string ss = s + s;
        ss.erase(ss.begin());
        ss.erase(ss.end() - 1);

        for (int i = 0; i < ss.size(); ++i)
        {
            while (ss[i] != s[j] && j > 0)
                j = next[j - 1];

            if (ss[i] == s[j])
            {
                ++j;
            }

            if (j == s.size())
                return true;
        }
        
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution2 slo;
    bool is_repeated = slo.repeatedSubstringPattern("aabaaba");

    cout << is_repeated << endl;
    return 0;
}
