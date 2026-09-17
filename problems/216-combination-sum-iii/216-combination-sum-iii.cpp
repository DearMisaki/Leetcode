#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtracing(k, n, 1);

        return result;
    }

    void backtracing(int k, int n, int startIndex)
    {
        if (set.size() + 9 - startIndex + 1 < k)
        {
            return;
        }

        if (set.size() == k)
        {
            if (sum == n)
            {
                result.push_back(set);
            }
            return;
        }

        for (int i = startIndex; i <= 9; ++i)
        {
            if (sum + i > n)
            {
                break;
            }

            sum += i;
            set.push_back(i);
            backtracing(k, n, i + 1);
            sum -= set.back();
            set.pop_back();
        }
    }

    int sum = 0;

    vector<int> set;

    vector<vector<int>> result;
};