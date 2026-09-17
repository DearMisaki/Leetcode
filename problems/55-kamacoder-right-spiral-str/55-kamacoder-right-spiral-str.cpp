#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

void reverse(string::iterator begin, string::iterator end)
{
    if (begin > end)
        throw runtime_error("The beginning index must be less than the end index.");
    
    --end;

    while (begin < end)
    {
        iter_swap(begin, end);

        --end;
        ++begin;
    }
}

int main()
{
    int n;
    string s;

    cin >> n >> s;

    reverse(s.begin(), s.end());

    reverse(s.begin(), s.begin() + n);

    reverse(s.begin() + n, s.end());

    cout << s << endl;

    return 0;
}