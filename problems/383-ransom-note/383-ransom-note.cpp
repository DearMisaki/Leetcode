#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap;

        for (const char &c: magazine)
        {
            umap[c] += 1;
        }

        for (const char &c: ransomNote)
        {
            auto iter = umap.find(c);
            if (iter != umap.end())
            {
                iter->second -= 1;
                if (iter->second == 0)
                {
                    umap.erase(iter->first);
                }
            }
            else 
            {
                return false;
            }
        }
        return true;
    }
};