#include <iostream>
#include <cstdint>

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0) return 0;
        
        double x0 = x, x1 = 0.5 * (x0 + x / x0);
        while (abs(x1 - x0) > 1e-7)
        {
            x0 = x1;
            x1 = 0.5 * (x0 + x / x0);
        }
    
        return int(x1);
    }
};