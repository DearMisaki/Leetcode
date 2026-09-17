#include <string>
#include <iostream>

using namespace std;


int main()
{
    string s;

    cin >> s;

    for (int i = 0; i < s.size(); ++i)
    {
        if (isdigit(s[i]))
        {
            s.replace(i, 1, "number");
        }
    }

    cout << s << endl;

    return 0;
}