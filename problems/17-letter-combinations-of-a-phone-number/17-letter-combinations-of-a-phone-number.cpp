#include <vector>
#include <string>
#include <unordered_map>
#include <array>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        for (int i = 97, n = '2'; i <= 122; i += 3, n += 1)
        {
            umap[n][0] = i;
            umap[n][1] = i + 1;
            umap[n][2] = i + 2;

            if (n == '7' || n == '9')
            {
                umap[n][3] = i + 3;
                i += 1;
            }
        }

        backtrace(digits, 0);

        return result;
    }

    void backtrace(const string &digits, int depth)
    {
        if (depth == digits.size())
        {
            result.push_back(temp);

            return;
        }

        for (int i = 0; i < umap[digits[depth]].size(); ++i)
        {

            if ((digits[depth] != '7' && digits[depth] != '9') && i == 3)
            {
                break;
            }

            temp.push_back(umap[digits[depth]][i]);

            backtrace(digits, depth + 1);

            temp.pop_back();
        }
    }

    unordered_map<char, array<char, 4>> umap;

    vector<string> result;

    string temp;
};

int main()
{
    auto result = Solution().letterCombinations("23");
}