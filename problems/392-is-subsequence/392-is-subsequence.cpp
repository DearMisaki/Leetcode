#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {

    int i = 0, j = 0;

    while (i < s.size() && j < t.size()) {
      if (s[i] == s[j]) {
        ++i;
      }
      ++j;
    }

    return i == s.size();
  }
};

int main() {
  string s = "axe";
  string t = "ahbgdc";
  Solution().isSubsequence(s, t);
}