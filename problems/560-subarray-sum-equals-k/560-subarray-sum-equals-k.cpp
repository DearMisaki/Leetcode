#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> umap;

        umap[0] = 1;

        int pre = 0;

        int count = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            // 已经知道了当前的 前缀和
            pre += nums[i];
    
            // 但是要找到区间 i...j 和为 k 的前缀和，也即是 pre_i - pre_j-1 = k
            if (umap.find(pre - k) != umap.end())
            {
                // 这里 pre_j-1 = pre_i - k 可能有多个
                // 因为数组元素可能为负数
                count += umap[pre - k];
            }

            umap[pre]++;
        }

        return count;
    }
};

int main()
{
    vector<int> nums{1, 2, 3};

    Solution().subarraySum(nums, 3);

    return 0;
}