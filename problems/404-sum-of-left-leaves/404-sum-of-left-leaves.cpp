#include "TreeNode.h"

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }

        int sum = 0;

        // 当前节点的左节点是叶子节点
        if (root->left && !root->left->left && !root->left->right)
        {
            sum += root->left->val;

            // 跳过叶子节点
            return sum + sumOfLeftLeaves(root->right);
        }

        return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};