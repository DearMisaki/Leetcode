#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;

        for (auto str : strs)
        {
            const auto pres = str;
            sort(str.begin(), str.end());

            umap[str].push_back(pres);
        }

        vector<vector<string>> result;

        for (auto const key: umap)
        {
            result.push_back(key.second);
        }

        return result;
    }
};