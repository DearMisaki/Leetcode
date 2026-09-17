#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        backtrace(nums, 0);

        return result;
    }

    void backtrace(vector<int>& nums, int startIndex)
    {
        result.push_back(temp);

        for (int i = startIndex; i < nums.size(); ++i)
        {
            temp.push_back(nums[i]);

            backtrace(nums, i + 1);

            temp.pop_back();
        }
    }

    vector<vector<int>> result;

    vector<int> temp;
};