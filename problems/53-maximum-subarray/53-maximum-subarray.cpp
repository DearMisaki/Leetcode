#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int size = nums.size();
    if (size == 0) {
      return 0;
    }

    if (size == 1) {
      return nums[0];
    }

    int sum = nums[0];

    int max_sum = sum;

    for (int i = 1; i < size; ++i) {
      // 记录应该拼接前面还是另起炉灶
      sum = max(sum + nums[i], nums[i]);

      // 记录全局最大值
      max_sum = max(max_sum, sum);
    }

    return max_sum;
  }
};

class Solution2 {
public:
  int maxSubArray(vector<int> &nums) {

    if (nums.size() == 1) {
      return nums[0];
    }

    int maxsum = nums[0];

    int max1 = numeric_limits<int>::min();

    for (int i = 1; i < nums.size(); ++i) {
      maxsum = max(nums[i] + maxsum, nums[i]);

      max1 = max(max1, maxsum);
    }

    return max(max1, nums[0]);
  }
};

int main() {
  vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

  Solution2().maxSubArray(nums);
}