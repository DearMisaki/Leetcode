#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    int n = s.size();

    int ans = 0;

    // 遍历奇数中心
    for (int i = 0; i < s.size(); ++i) {
      int l = i, r = i;

      while (l >= 0 && r < n && s[l] == s[r]) {
        --l;
        ++r;
        ++ans;
      }
    }

    for (int i = 0; i <= n - 2; ++i) {
      int l = i, r = i + 1;

      while (l >= 0 && r < n && s[l] == s[r]) {
        --l;
        ++r;
        ++ans;
      }
    }

    return ans;
  }
};