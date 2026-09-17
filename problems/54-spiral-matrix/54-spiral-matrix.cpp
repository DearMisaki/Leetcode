#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0, right = n - 1;
        int up = 0, down = m - 1;

        vector<int> result;
        result.reserve(m * n);

        while (left <= right && up <= down)
        {
            // 向右
            for (int i = left; i <= right; ++i)
            {
                result.push_back(matrix[up][i]);
            }

            if (++up > down)
                break;

            for (int i = up; i <= down; ++i)
            {
                result.push_back(matrix[i][right]);
            }

            if (--right < left)
                break;

            for (int i = right; i >= left; --i)
            {
                result.push_back(matrix[down][i]);
            }

            if (--down < up)
                break;

            for (int i = down; i >= up; --i)
            {
                result.push_back(matrix[i][left]);
            }

            if (++left > right)
                break;
        }

        return result;
    }
};