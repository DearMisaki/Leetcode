#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*
    KMP 算法
*/
class Solution
{
public:
    vector<int> get_next(string pattern)
    {
        vector<int> next(pattern.size(), 0);

        int j = 0;

        for (int i = 1; i < pattern.size(); ++i)
        {
            while (pattern[j] != pattern[i] && j > 0)
                j = next[j - 1];

            if (pattern[j] == pattern[i])
            {
                ++j;
            }

            next[i] = j;
        }
        return next;
    }

    int strStr(string haystack, string needle)
    {
        auto next = get_next(needle);

        for (int i = 0, j = 0; i < haystack.size(); ++i)
        {
            while (haystack[i] != needle[j] && j > 0)
                j = next[j - 1];

            if (haystack[i] == needle[j])
            {
                ++j;
            }

            if (j == needle.size())
                return i - needle.size() + 1;
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    string s1{"ababcaababcaabc"};
    string s2{"ababcaabc"};

    Solution slo;

    int index = slo.strStr(s1, s2);

    cout << index << endl;

    return 0;
}
