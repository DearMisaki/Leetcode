#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        // 高度递减、k递增
        // 队列中最高的人，前面的人必定是和他一样高的人，ki必然存在0
        // 后续按k插入不会破坏相对关系                                                                                                               
        sort(people.begin(), people.end(), [](vector<int> x, vector<int> y) {
            if (x[0] != y[0])
            {
                return x[0] > y[0];
            }

            return x[1] < y[1];
        });

        vector<vector<int>> res;

        for (auto const &p: people)
        {
            res.insert(res.begin() + p[1], p);
        }

        return res;
     }
};