#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return 1;
        }

        int prediff = nums[1] - nums[0];

        int count = prediff != 0 ? 2 : 1;

        for (int i = 2; i < nums.size(); ++i)
        {
            int diff = nums[i] - nums[i - 1];

            if (diff > 0 && prediff <= 0 || diff < 0 && prediff >= 0)
            {
                count++;
                prediff = diff;
            }

        }

        return count;
    }
};

class Solution2 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
        {
            return nums.size();
        }

        vector<vector<int>> dp(nums.size(), vector<int>(2, 1));

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + 1);
                dp[i][1] = dp[i - 1][1];
            }
            else if (nums[i] < nums[i - 1])
            {
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + 1);
                dp[i][0] = dp[i - 1][0];
            }
            else
            {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1];
            }
        }

        return max(dp[nums.size() - 1][1], dp[nums.size() - 1][0]);
    }
};