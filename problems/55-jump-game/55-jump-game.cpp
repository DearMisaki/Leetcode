#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int size = nums.size();

        if (nums[0] == 0 && size == 1)
        {
            return false;
        }

        int maxstep = nums[0];

        for (int i = 1; i < size; ++i)
        {
            maxstep = max(nums[i], maxstep - 1);

            if (maxstep == 0 && i < size - 1)
            {
                return false;
            }
        }

        return true;
    }
};