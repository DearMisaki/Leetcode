#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1 {nums1.begin(), nums1.end()};
        unordered_set<int> inter_s {};

        for (auto const &num: nums2)
        {
            if (s1.count(num))
            {
                inter_s.insert(num);
            }
        }

        return vector<int> {inter_s.begin(), inter_s.end()};
    }
};