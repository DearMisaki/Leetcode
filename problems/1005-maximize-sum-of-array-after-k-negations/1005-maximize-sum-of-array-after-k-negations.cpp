#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        // 绝对值从大到小排序
        sort(nums.begin(), nums.end(), [](int x, int y)
             { return abs(x) > abs(y); });

        int sum = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (k > 0 && nums[i] < 0)
            {
                nums[i] *= -1;
                --k;
            }
            sum += nums[i];
        }

        if (k % 2 == 1)
        {
            sum -= 2 * *(nums.end() - 1);
        }

        return sum;
    }
};