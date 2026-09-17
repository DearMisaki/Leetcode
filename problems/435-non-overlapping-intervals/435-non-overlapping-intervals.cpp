#include <bits/stdc++.h>

using namespace std;

class Solution1
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<int> f(n, 1);

        sort(intervals.begin(), intervals.end());

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                // 区间不重合
                if (intervals[j][1] <= intervals[i][0])
                {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }

        return n - *max_element(f.begin(), f.end());
    }
};

class Solution2
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const auto &x, const auto &y) {
            return x[1] < y[1];
        });

        int count = 1;

        // 区间不重合时的右侧最大值
        int right = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i)
        {
            // 区间不重合
            if (intervals[i][0] >= right)
            {
                ++count;
                right = intervals[i][1];
            }
        }

        return intervals.size() - count;
    }
};