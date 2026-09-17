#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; ++i)
        {
            if (binary_search(matrix[i], target) != -1)
            {
                return true;
            }
        }

        return false;
    }

    int binary_search(vector<int> &array, int target)
    {
        int size = array.size();

        int left = 0, right = size - 1;

        while (left <= right)
        {
            int middle = (right - left) / 2 + left;

            if (target == array[middle])
            {
                return middle;
            }
            else if (target < array[middle])
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        return -1;
    }
};