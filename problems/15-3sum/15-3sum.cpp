#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int j = i + 1, k = nums.size() - 1;

            while (j < k)
            {
                if (nums[j] + nums[k] == -nums[i])
                {
                    result.push_back({nums[i], nums[j], nums[k]});

                    ++j;
                    --k;

                    while (j < k && nums[j] == nums[j - 1])
                    {
                        ++j;
                    }
                    if (j < k && nums[k] == nums[k + 1])
                    {
                        --k;
                    }
                }

                if (nums[j] + nums[k] < -nums[i])
                {
                    ++j;
                }

                if (nums[j] + nums[k] > -nums[i])
                {
                    --k;
                }
            }
        }
        return result;
    }
};