#include "TreeNode.h"

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int val = 0, max_height = 0;

        dfs(root, 0, val, max_height);

        return val;
    }

    void dfs(TreeNode *node, int height, int &val, int &max_height)
    {
        if (node == nullptr)
        {
            return;
        }

        height += 1;
        
        dfs(node->left, height, val, max_height);
        dfs(node->right, height, val, max_height);

        if (height > max_height)
        {
            val = node->val;
            max_height = height;
        }
    }
};