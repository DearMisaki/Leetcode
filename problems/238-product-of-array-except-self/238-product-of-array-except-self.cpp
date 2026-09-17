#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> result;

        int pre = 1;

        for (int i = 0; i < nums.size(); ++i)
        {
            result.push_back(pre);
            pre *= nums[i];
        }

        int post = 1;

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            result[i] *= post;
            post *= nums[i];
        }

        return result;
    }
};