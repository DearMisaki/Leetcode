#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        if (bills[0] != 5)
        {
            return false;
        }

        int five = 0, ten = 0;

        for (int i = 0; i < bills.size(); ++i)
        {
            if (bills[i] == 5)
            {
                five++;
            }
            else if (bills[i] == 10)
            {
                five--;
                ten++;

                if (five < 0)
                {
                    return false;
                }
            }
            else
            {
                if (ten)
                {
                    ten--;
                    five--;
                }
                else
                {
                    five -= 3;
                }

                if (ten < 0 || five < 0)
                {
                    return false;
                }
            }
        }

        return true;
    }
};