#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i)
        {
            auto& last = res.back();

            // 区间重合
            if (intervals[i][0] <= last[1])
            {
                last[1] = max(last[1], intervals[i][1]);
            }
            // 区间不重合
            else
            {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};

int main()
{
    vector<vector<int>> input {{1,4}, {0,2}, {3,5}};

    auto result = Solution().merge(input);

    return 0;
}