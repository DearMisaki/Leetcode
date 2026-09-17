#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);

        std::sort(nums.begin(), nums.end());

        backtrace(nums, used);

        return result;
    }

    void backtrace(vector<int>& nums, vector<bool> used)
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

            // 排序后才能这样做 used[i - 1] != true， 参考 {3 3 0 3}
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] != true)
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