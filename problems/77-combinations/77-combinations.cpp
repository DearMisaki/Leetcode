#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        backtracing(n, k, 1);

        return results;
    }

    void backtracing(int n, int k, int startIndex)
    {
        if (path.size() + n - startIndex + 1 < k)
        {
            return;
        }

        if (path.size() == k)
        {
            results.push_back(path);
            return;
        }

        for (int i = startIndex; i <= n; ++i)
        {
            path.push_back(i);
            backtracing(n, k, i + 1);
            path.pop_back();
        }
    }

    vector<int> path;
    vector<vector<int>> results;
};