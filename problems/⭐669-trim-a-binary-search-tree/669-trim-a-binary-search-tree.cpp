#include <TreeNode.h>

class Solution
{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
            return nullptr;
        else if (root->val < low)
            return trimBST(root->right, low, high);
        else if (root->val > high)
            return trimBST(root->left, low, high);

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};

class Solution2
{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {

        // 找到第一个满足条件的根节点
        while (root && (root->val < low || root->val > high))
        {
            root = root->val < low ? root->right : root->left;
        }

        if (root == nullptr)
            return nullptr;

        // 以当前根节点为基准，分别向左向右剪枝
        TreeNode *node = root;

        while (node->left)
        {
            if (node->left->val < low)
            {
                node->left = node->left->right;
            }
            else
                node = node->left;
        }

        node = root;

        while (node->right)
        {
            if (node->right->val > high)
            {
                node->right = node->right->left;
            }
            else
                node = node->right;
        }

        return root;
    }
};