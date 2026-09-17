#include <unordered_set>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> uset;

        int sum = 0;
        while (n != 0)
        {
            int num1 = n % 10;
            sum += num1 * num1;

            n /= 10;
            if (n == 0)
            {
                if (sum == 1)
                    return true;

                if (uset.count(sum))
                {
                    return false;
                }
                uset.insert(sum);

                n = sum;
                sum = 0;
            }
        }
        return false;
    }
};