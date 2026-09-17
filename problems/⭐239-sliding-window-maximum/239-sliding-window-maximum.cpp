#include <vector>
#include <limits>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> result;

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < k; ++i)
        {
            pq.push({nums[i], i});
        }

        result.push_back(pq.top().first);

        for (int i = k; i < nums.size(); ++i)
        {
            pq.push({nums[i], i});

            // 这里判断当前 top 位的元素是否是区间外的元素
            // 这里不能用 if 只能用 while，因为不一定每次都会移除元素，就可能导致边界外的元素
            // 在某一时间点集中在 top 附近
            while (pq.top().second < i - k + 1)
            {
                pq.pop();
            }

            result.push_back(pq.top().first);
        }

        return result;
    }
};

class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> result;

        deque<int> q;

        for (int i = 0; i < k; ++i)
        {
            // 这里队列中装的是 **下标**， 隐含了队列存储的下标是单调递增的
            // 如果当前入队元素 > 队尾元素（之前入队的元素）
            // 那么在后面的窗口中，这个队尾元素永远不可能成为最大值，因为窗口始终是向右边移动的
            while (!q.empty() && nums[i] >= nums[q.back()])
            {
                q.pop_back();
            }

            q.push_back(i);
        }

        result.push_back(nums[q.front()]);

        for (int i = k; i < nums.size(); ++i)
        {
            while (!q.empty() && nums[i] >= nums[q.back()])
            {
                q.pop_back();
            }

            q.push_back(i);
            
            // 删除区间外的最大元素
            while (q.front() < i - k + 1)
            {
                q.pop_front();
            }

            result.push_back(nums[q.front()]);
        }
        return result;
    }
};

/*
* 分块的做法
* 将整个数组按 k 分块，使用两个辅助数组计算滑动窗口内的最大值
* https://leetcode.cn/problems/sliding-window-maximum/solutions/543426/hua-dong-chuang-kou-zui-da-zhi-by-leetco-ki6m/comments/2161226/
*/
class Solution3 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> prefix(nums.size(), 0);
        vector<int> suffix(nums.size(), 0);

        vector<int> result;
        
        // 计算 preffix
        // prefix 数组存储的是，在分组内部，从 分组起点 到 i 区间内的最大值
        // 可以通过一次循环获得
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i % k == 0)
            {
                prefix[i] = nums[i];
            }
            else
            {
                prefix[i] = max(prefix[i - 1], nums[i]);
            }
        }

        // 计算 suffix
        // suffix 数组存储的是，在分组内部，从 分组终点 到 i （逆序）区间内的最大值
        // 这里要考虑数组内元素不够整数个分组的情况
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (i == nums.size() - 1 || i % k == k - 1)
            {
                suffix[i] = nums[i];
            }
            else
            {
                suffix[i] = max(suffix[i + 1], nums[i]);
            }
        }

        for (int i = k - 1; i < nums.size(); ++i)
        {
            // 当前窗口与组对齐，suffix[i - k + 1] 与 prefix[i]相等
            if (i % k == (k - 1))
            {
                result.push_back(prefix[i]);
            }
            // 不对齐，则取前一个窗口的后缀与后一个窗口的前缀的最大值
            else
            {
                result.push_back(max(prefix[i], suffix[i - k + 1]));
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums {1,3,-1,-3,5,3,6,7};

    Solution2 slo;
    auto result = slo.maxSlidingWindow(nums, 3);
    return 0;
}
