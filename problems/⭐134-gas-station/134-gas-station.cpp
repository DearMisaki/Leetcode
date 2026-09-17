#include <bits/stdc++.h>

using namespace std;

// 油箱油量只可能 >= 0，所以当区间内油量 < 0 时，这个区间内所有的节点都不可能是起点了。
// 必须计算总剩余油量，如果 >= 0 那么必然有唯一解。
class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int n = gas.size();
        int totalSum = 0;      // 全部的盈亏和
        int curSum = 0;        // 当前段的盈亏和
        int start = 0;
        
        for (int i = 0; i < n; ++i) 
        {
            int diff = gas[i] - cost[i];
            totalSum += diff;
            curSum += diff;
            
            // 当前段累计不够，说明 [start, i] 都不能作为起点
            if (curSum < 0) 
            {
                curSum = 0;   // 重新开始累计
                start = i + 1; // 设置新起点
            }
        }
        
        // 如果总收益 < 0，说明无论从哪开始都不可能绕一圈
        return totalSum < 0 ? -1 : start;
    }
};
