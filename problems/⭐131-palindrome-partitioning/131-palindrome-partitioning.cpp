#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        int n = s.size();

        f.assign(n, vector<bool>(n, true));

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i; j <= n - 1; ++j)
            {
                if (i == j)
                    f[i][j] = true;
                else
                {
                    f[i][j] = f[i + 1][j - 1] && (s[i] == s[j]);
                }
            }
        }

        backtrace(s, 0);

        return result;
    }

    void backtrace(string s, int staretIndex)
    {
        if (staretIndex >= s.size())
        {
            result.emplace_back(temp);

            return;
        }

        for (int j = staretIndex; j < s.size(); ++j)
        {
            if (f[staretIndex][j])
            {
                temp.emplace_back(s.substr(staretIndex, j - staretIndex + 1));

                backtrace(s, j + 1);

                temp.pop_back();
            }
        }
    }

    vector<vector<bool>> f;

    vector<vector<string>> result;

    vector<string> temp;
};

int main()
{
    auto result = Solution().partition("aab");
}