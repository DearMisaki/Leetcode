#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);

        int flag = -1;

        for (int i = s.size() - 1; i > 0; --i)
        {
            if (s[i] < s[i - 1])
            {
                flag = i;
                s[i - 1] -= 1;
            }
        }

        for (int i = flag; i < s.size() && flag != -1; ++i)
        {
            s[i] = '9';
        }

        return stoi(s);
    }
};
