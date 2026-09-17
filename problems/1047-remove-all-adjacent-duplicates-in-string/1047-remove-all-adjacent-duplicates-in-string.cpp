#include <string>
#include <stack>

using namespace std;


/*
*   题目要求删除**两个**相同的字符，并且要重复操作
*/
class Solution
{
public:
    string removeDuplicates(string s)
    {
        string s1;

        for (auto const &c: s)
        {
            if (!s1.empty() && c == s1.back())
            {
                s1.pop_back();
            }
            else
            {
                s1.push_back(c);
            }
        }
        return s1;
    }
};