#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        // 双指针 i 存储下一个元素 j 遍历数组
        int i, j, count;

        i = 0, count = 0;

        for (j = 0; j < nums.size(); ++j)
        {
            if (nums[j] == val)
            {
                ++count;
                continue;
            }
            else if (i == j)
            {
                ++i;
                continue;
            }
            else
            {
                nums[i] = nums[j];
                ++i;
            }
        }
        int actual_size = nums.size() - count;
        return actual_size;
    }

    int removeElement2(vector<int> &nums, int val)
    {
        int left_index = 0;
        int right_index = nums.size() - 1;

        while (left_index <= right_index)
        {
            // 从左往右找到第一个 val 的位置
            while (left_index <= right_index && nums[left_index] != val)
                ++left_index;

            // 从右往左找到第一个 非val 的位置
            while (left_index <= right_index && nums[right_index] == val)
                --right_index;

            /* 边界条件
                1. left_index < right_index 正常交换
                2. left_index = right_index 交换无意义
                3. left_index > right_index 不能交换
            */
            if (left_index < right_index)
                nums[left_index++] = nums[right_index--];
        }
        return left_index;
    }
};