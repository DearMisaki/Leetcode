#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
  int longestPalindromeSubseq(string s) {
    string s_rev = s;
    reverse(s.begin(), s.end());

    int m = s.size();

    vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

    for (int i = 1; i < m + 1; ++i) {
      for (int j = 1; j < m + 1; ++j) {
        if (s[i - 1] == s_rev[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[m][m];
  }
};

class Solution2 {
public:
  int longestPalindromeSubseq(string s) {

    int m = s.size();

    vector<vector<int>> dp(m, vector<int>(m, 0));

    for (int i = m - 1; i >= 0; --i) {
      for (int j = i + 1; j < m; ++j) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        } else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[0][m - 1];
  }
};