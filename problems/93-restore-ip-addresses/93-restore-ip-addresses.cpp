#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        backtrace(s, 0, 3);

        return result;
    }

    void backtrace(string s, int startIndex, int remain)
    {
        if (remain == 0)
        {
            if (isValid(s, startIndex, s.size() - 1))
            {
                result.push_back(s);
            }

            return;
        }

        for (int i = startIndex; i < s.size(); ++i)
        {
            if (isValid(s, startIndex, i))
            {
                s.insert(i + 1, ".");

                backtrace(s, i + 2, remain - 1);

                s.erase(i + 1, 1);
            }
            else
            {
                break;
            }
        }
    }

    bool isValid(const string &s, int start, int end)
    {
        if (start > end) return false;

        if (end - start + 1 > 3) return false;

        if (s[start] == '0' && (end - start + 1) > 1)
        {
            return false;
        }

        int num = 0;

        for (int i = start; i <= end; ++i)
        {
            if (s[i] > '9' || s[i] < '0')
            {
                return false;
            }

            num = num * 10 + s[i] - '0';

            if (num < 0 || num > 255)
            {
                return false;
            }
        }

        return true;
    }

    vector<string> result;
};

int main()
{
    auto result = Solution().restoreIpAddresses("25525511135");

    return 0;
}