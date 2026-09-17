#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s1;
        
        for (auto const& token: tokens)
        {
            if (token != "+" && token != "-" && token != "*" && token != "/")
            {
                s1.push(stoi(token));
            }
            else
            {
                int number2 = s1.top(); s1.pop();
                int number1 = s1.top(); s1.pop();

                if (token == "+")
                {
                    s1.push(number1 + number2);
                }
                else if (token == "-")
                {
                    s1.push(number1 - number2);
                }
                else if (token == "*")
                {
                    s1.push(number1 * number2);
                }
                else
                {
                    s1.push(number1 / number2);
                }
            }
        }
        return s1.top();
    }
};

int main(int argc, char const *argv[])
{
    Solution slo;
    vector<string> tokens {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int result = slo.evalRPN(tokens);

    

    return 0;
}
