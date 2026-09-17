#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
  int numDistinct(string s, string t) {

    int m = s.size();
    int n = t.size();

    vector<vector<unsigned long long>> dp(m + 1,
                                          vector<unsigned long long>(n + 1, 0));

    // 对于
    // 空t，那么任意一个s都有一种解法，因为可以任意删除字符，那么全部删除即可
    for (int j = 0; j < m + 1; ++j) {
      dp[j][0] = 1;
    }

    for (int i = 1; i < m + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    unsigned long long maxans = 0;

    for (int i = 0; i < m + 1; ++i) {
      maxans = max(maxans, dp[i][n]);
    }

    return maxans;
  }
};

int main() {
  string s = "rabbbit";
  string t = "rabbit";

  Solution().numDistinct(s, t);
}