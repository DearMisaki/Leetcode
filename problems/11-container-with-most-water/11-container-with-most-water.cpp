#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;

        int max_area = 0;

        int current = 0;

        while (i < j)
        {
            current = min(height[i], height[j]) *(j - i);
            max_area = max(max_area, current);

            // 面积总是由矮的拿一个决定
            if (height[i] > height[j])
                --j;
            else
                ++i;
        }

        return max_area;
    }
};