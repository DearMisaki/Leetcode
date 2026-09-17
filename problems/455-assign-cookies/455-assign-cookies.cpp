#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        if (s.empty() || g.empty())
        {
            return 0;
        }

        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int result = 0;

        for(int i = g.size() - 1; i >= 0 && !s.empty(); --i)
        {
            if (s.back() >= g[i])
            {
                result ++;
                s.pop_back();
            }
        }

        return result;
    }
};