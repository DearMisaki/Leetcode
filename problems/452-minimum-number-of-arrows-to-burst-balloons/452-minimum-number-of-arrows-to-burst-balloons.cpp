#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());

        int max_x = points[0][1];

        int count = 1;

        for (int i = 1; i < points.size(); ++i)
        {
            // 当前球的起点 > 上一个球的终点
            if (points[i][0] > max_x)
            {
                ++count;

                max_x = points[i][1];
            }
            // 当前球得起点在终点内，计算交集
            // 当前球的终点一定在上一个球得起点前（排序保证了）
            else
            {
                max_x = min(max_x, points[i][1]); 
            }
        }

        return count;
    }
};