#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        for (int base = 0; base < nums.size(); ++base)
        {
            if (nums[base] == 0)
            {
                int j = base + 1;
                while (j < nums.size() && nums[j] == 0)
                {
                    ++j;
                }

                // base后向区间已经全为 0
                if (j == nums.size())
                {
                    return;
                }

                // 找到一个 非 0
                swap(nums[base], nums[j]);
            }
        }
    }
};