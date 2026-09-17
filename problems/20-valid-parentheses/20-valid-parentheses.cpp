#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> s1;
        unordered_map<char, char> umap{
            {'}', '{'},
            {']', '['},
            {')', '('}};

        for (auto const &c : s)
        {
            if (c == '{' || c == '[' || c == '(')
            {
                s1.push(c);
            }
            // 可能是这种情况 '}[]()'
            // 第一个 '}' 前必须判断 stack 是否为空
            else if (!s1.empty() && s1.top() == umap[c])
            {
                s1.pop();
            }
            else
            {
                return false;
            }
        }

        if (s1.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};