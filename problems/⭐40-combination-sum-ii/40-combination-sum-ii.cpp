#include <algorithm>
#include <vector>

#include <memory_resource>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    
    // 必须排序才能用 candidates[i] == candidates[i - 1] 去重
    std::sort(candidates.begin(), candidates.end(), std::less<int>());

    backtracing(candidates, target, 0);

    return result;
  }

  void backtracing(vector<int> &candidates, int target, int startIndex) {
    if (sum == target) {
      result.push_back(set);
      return;
    }

    for (int i = startIndex; i < candidates.size(); ++i) {
      // 剪枝，当同层元素相同时，跳过重复的元素。例如 [1, 1, 2, 5, 6]
      // 第一次 1 1, 1 2, 1 5, 1 6
      // 第二次如果不跳过 1 2, 1 5, 1 6
      if (i > startIndex && candidates[i] == candidates[i - 1]) {
        continue;
      }

      if (sum + candidates[i] > target) {
        break;
      }

      sum += candidates[i];
      set.push_back(candidates[i]);

      backtracing(candidates, target, i + 1);

      sum -= set.back();
      set.pop_back();
    }
  }

  vector<int> set;

  vector<vector<int>> result;

  int sum = 0;
};

int main() {
  vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};

  auto result = Solution().combinationSum2(candidates, 8);
}