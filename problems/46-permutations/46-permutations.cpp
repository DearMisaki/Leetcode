#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);

        backtrace(nums, used);

        return result;
    }

    void backtrace(vector<int>& nums, vector<bool>& used)
    {
        if (temp.size() == nums.size())
        {
            result.push_back(temp);

            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (used[i])
            {
                continue;
            }

            used[i] = true;

            temp.push_back(nums[i]);

            backtrace(nums, used);

            temp.pop_back();

            used[i] = false;
        }
    }

    vector<vector<int>> result;

    vector<int> temp;
};                                             