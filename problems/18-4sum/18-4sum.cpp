#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        if (nums.size() < 4) return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for (int i = 0; i < nums.size() - 3; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            if ((long)nums[i] + (long)nums[i + 1] + (long)nums[i + 2] + (long)nums[i + 3] > target) return result;

            for (int j = i + 1; j < nums.size() - 2; ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                
                int left = j + 1, right = nums.size() - 1;

                while (left < right)
                {
                    if ((long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right] == target)
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        ++left;
                        --right;

                        while (left < right && nums[left] == nums[left - 1])
                        {
                            ++left;
                        }

                        while (left < right && nums[right] == nums[right + 1])
                        {
                            --right;
                        }
                    }
                    else if ((long)nums[j] + (long)nums[left] + (long)nums[right] < target - nums[i])
                    {
                        ++left;
                    }
                    else if ((long)nums[j] + (long)nums[left] + (long)nums[right] > target - nums[i])
                    {
                        --right;
                    }
                }
            }
        }
        return result;
    }
};