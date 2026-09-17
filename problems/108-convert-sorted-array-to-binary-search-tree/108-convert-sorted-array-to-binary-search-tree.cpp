#include <TreeNode.h>

#include <vector>

using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return make(nums.begin(), nums.end());
    }

    TreeNode* make(vector<int>::iterator begin, vector<int>::iterator end)
    {
        if (begin >= end)
        {
            return nullptr;
        }

        auto middle = (end - begin) / 2;

        TreeNode* root = new TreeNode(*(begin + middle));

        root->left = make(begin, begin + middle);
        root->right = make(begin + middle + 1, end);

        return root;
    }
};