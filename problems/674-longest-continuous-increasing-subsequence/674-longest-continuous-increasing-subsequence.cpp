#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    int ans = 0;

    int start = 0;
    for (int j = 1; j < nums.size(); ++j) {
      if (nums[j] <= nums[j - 1]) {
        start = j;
      }

      ans = max(ans, j - start + 1);
    }

    return ans;
  }
};