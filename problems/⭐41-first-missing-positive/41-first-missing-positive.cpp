#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        // 两种极端情况，一种是全重复，一种是全不重复
        // 但是所有的情况都导致这个 缺失的正数 落在 1 - N + 1 之间

        int size = nums.size();

        for (int &num : nums)
        {
            if (num <= 0)
            {
                num = size + 1;
            }
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            // 由于一个正数可能映射到其前后任意位置，如果是其后面，那么后面的遍历
            // 可能仍然会出现负数，所以这里取正
            int num = abs(nums[i]);

            if (nums[i] < size + 1)
            {
                // 比如 nums[i] = K，那么把 K - 1 位置的值设为负数（标签）
                // 代表出现过 K 这个正数了
                nums[nums[i] - 1] = -nums[nums[i] - 1];
            }
        }

        // 如果所有位置都打上了标签，那么就返回 N + 1
        // 否则返回第一个没有标签的位置 i + 1
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
            {
                return i + 1;
            }
        }

        return size + 1;
    }
};