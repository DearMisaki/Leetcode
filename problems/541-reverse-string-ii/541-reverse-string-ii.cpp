#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void partial_reverse(string::iterator &begin, string::iterator &end)
    {
        --end;

        while (begin < end)
        {
            iter_swap(begin, end);

            ++begin;
            --end;
        }
    }

    string reverseStr(string s, int k)
    {
        if (s.size() == 0)
            return s;

        for (int i = 0; i < s.size(); i += 2 * k)
        {
            auto begin = s.begin() + i;
            auto end   = (i + k > s.size()) ? s.end() : begin + k;

            partial_reverse(begin, end);
        }
        return s;
    }
};