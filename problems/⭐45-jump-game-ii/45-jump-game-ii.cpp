#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int end = 0;
        int max_edge = 0;
        int step = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            max_edge = max(max_edge, i + nums[i]);

            // 起跳点到落点之间的所有位置都访问过，计算出了之间所有位置能够到达的最大距离 max_edge
            if (i == end)
            {
                // 起跳点 - （中间点/最大落点起跳点） - 落点 - 最大落点。
                end = max_edge;
                step++;        
            }
        }

        return step;
    }
};