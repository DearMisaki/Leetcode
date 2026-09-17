#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

        int result = 0;

        unordered_map<int, int> umap;

        for (auto const &n1: nums1)
        {
            for (auto const &n2: nums2)
            {
                umap[n1 + n2] += 1;
            }
        }

        for (auto const &n3: nums3)
        {
            for (auto const &n4: nums4)
            {
                auto iter = umap.find(0 - n3 - n4);
                if (iter != umap.end())
                {
                    result += iter->second;
                }
            }
        }
        return result;
    }
};