#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));

        int num = 1;
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        
        while (left < right && top < bottom)
        {
            for (int j = left; j <= right; ++j)
            {
                result[top][j] = num++;
            }

            for (int i = top + 1; i <= bottom; ++i)
            {
                result[i][right] = num++;
            }

            for (int j = right - 1; j >= left; --j)
            {
                result[bottom][j] = num++;
            }

            for (int i = bottom - 1; i >= top + 1; --i)
            {
                result[i][left] = num++;
            }

            left += 1; right  -= 1;
            top  += 1; bottom -= 1;
        }
        if (n % 2 == 1) result[n / 2][n / 2] = num;
        
        return result;
    }
};

int main()
{
    Solution slo;
    auto rsult = slo.generateMatrix(3);
}