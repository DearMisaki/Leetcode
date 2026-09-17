#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        unordered_map<char, int> um;

        for (auto &c: s) um[c]++;
        for (auto &c: t) if (--um[c] < 0) return false;

        return true;
    }
};