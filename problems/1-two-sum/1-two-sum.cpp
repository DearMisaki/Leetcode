#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            auto iter = umap.find(target - nums[i]);
            if (iter != umap.end())
            {
                return {i, iter->second};
            }
            umap[nums[i]] = i;
        }
        return {};
    }
};