#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return nums.size();
        }

        unordered_set<int> uset;

        // set 去重
        for (const auto num : nums)
        {
            uset.insert(num);
        }

        int current_len = 1;
        int max_len = 1;

        for (const auto num: uset)
        {
            // 判断有没有比 当前数小的数，有的话说明当前数字不是起点
            if (uset.count(num - 1) != 0)
            {
                continue;
            }

            current_len = 1;

            int desired = num + 1;

            // 连续区间内后向判断
            while (uset.count(desired) != 0)
            {
                current_len ++;
                desired ++;
            }
            
            // 计算当前区间的长度
            max_len = max(max_len, current_len);
        }

        return max_len;
    }
};