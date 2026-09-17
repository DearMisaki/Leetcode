    #include <bits/stdc++.h>

    using namespace std;

    class Solution {
    public:
        int trap(vector<int>& height) {\

            int total_area = 0;

            for (int i = 0; i < height.size(); ++i)
            {
                // 跳过
                if (height[i] == 0)
                    continue;

                int next = find_next(i, height);

                // 相邻两个之间无空隙，不能装水
                if (next == i + 1)
                    continue;

                if (next == -1)
                    continue;

                // next = i + N
                int x = next - i + 1;
                int y = min(height[i], height[next]);

                int area = x * y;

                for (int j = i; j <= next; ++j)
                {
                    area -= min(height[j], y);
                }

                total_area += area;

                i = next - 1;
            }

            return total_area;
        }

        // 找到下一个高度 >= h[index] 的下标 或者 右侧最高的（因为没有  >= h[index] 的元素）
        int find_next(int index, vector<int>& height)
        {
            int max_val = -1;
            int max_id = -1;
            for (int i = index + 1; i < height.size(); ++i)
            {
                if (height[i] >= height[index])
                {
                    return i;
                }

                if (height[i] > max_val)
                {
                    max_val = height[i];
                    max_id = i;
                }
            }

            return max_id;
        }
    };