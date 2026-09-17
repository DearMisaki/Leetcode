#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        backtrace(nums, 0);

        return result;
    }

    void backtrace(vector<int>& nums, int startIndex)
    {
        result.push_back(temp);

        for (int i = startIndex; i < nums.size(); ++i)
        {
            if (i > startIndex && nums[i] == nums[i - 1])
            {
                continue;
            }
            else
            {
                temp.push_back(nums[i]);

                backtrace(nums, i + 1);

                temp.pop_back();
            }
        }
    }

    vector<vector<int>> result;

    vector<int> temp;
};