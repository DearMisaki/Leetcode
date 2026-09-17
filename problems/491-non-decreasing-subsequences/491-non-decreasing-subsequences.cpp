#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        backtrace(nums, 0);

        return result;
    }

    void backtrace(vector<int> &nums, int startIndex)
    {
        if (temp.size() > 1)
        {
            result.push_back(temp);
        }

        unordered_set<int> uset;

        for (int i = startIndex; i < nums.size(); ++i)
        {
            // 使用集合过滤 7 7 7 这种情况，第一个7就把所有组合找到了，第二个7没用了
            // uset 只过滤本层相同元素，避免找到重复的序列
            if (!temp.empty() && nums[i] < temp.back() || uset.find(nums[i]) != uset.end())
            {
                continue;
            }

            uset.emplace(nums[i]);

            temp.push_back(nums[i]);

            backtrace(nums, i + 1);

            temp.pop_back();
        }
    }

    vector<int> temp;

    vector<vector<int>> result;
};

int main()
{
    vector<int> input{4, 6, 7, 7};

    auto result = Solution().findSubsequences(input);

    return 0;
}