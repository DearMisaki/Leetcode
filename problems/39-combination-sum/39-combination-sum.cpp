#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());

        backtrace(candidates, target, 0);

        return result;
    }

    void backtrace(vector<int> &candidates, int remain, int depth)
    {
        if (remain == 0)
        {
            result.push_back(temp);

            return;
        }

        for (int i = depth; i < candidates.size(); ++i)
        {
            if (remain - candidates[i] < 0)
            {
                break;;
            }

            temp.push_back(candidates[i]);

            backtrace(candidates, remain - candidates[i], i);

            temp.pop_back();
        }
    }

    vector<vector<int>> result;

    vector<int> temp;
};

int main()
{
    vector<int> input{2, 3, 6, 7};

    auto result = Solution().combinationSum(input, 7);
}