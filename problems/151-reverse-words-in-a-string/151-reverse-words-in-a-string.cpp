#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

class Solution
{
public:
    /*
        1. 先将整个字符串反转（包括里面的所有空格）
        2. 遍历反转后的字符串，寻找第一个单词的起点，遍历到单词末尾，反转，并插入一个空格
        3. 寻找下一个单词的起点
    */

    void reverse(string::iterator begin, string::iterator end)
    {
        if (begin > end)
            throw runtime_error("require begin < end.");
        --end;

        while (begin < end)
        {
            iter_swap(begin, end);

            ++begin;
            --end;
        }
    }

    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());

        int index = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != ' ')
            {

                int end = i;
                while (end < s.size() && s[end] != ' ')
                {
                    s[index++] = s[end++];
                }

                reverse(s.begin() + index - (end - i), s.begin() + index);

                // 最后一个单词后会多插入一个空格
                s[index++] = ' ';

                i = end;
            }
        }

        if (s[index - 1] == ' ') --index;
        
        s.erase(s.begin() + index, s.end());
        
        return s;
    }
};

int main()
{
    string s{"hello  world "};

    Solution slo;

    auto result = slo.reverseWords(s);

    cout << result << endl;

    return 0;
}