#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

    int m = nums1.size();
    int n = nums2.size();

    int max_len = 0;

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (nums1[i - 1] == nums2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          max_len = max(max_len, dp[i][j]);
        } else {
          dp[i][j] = 0;
        }
      }
    }

    return max_len;
  }
};