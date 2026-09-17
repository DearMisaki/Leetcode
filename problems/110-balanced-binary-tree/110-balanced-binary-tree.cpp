#include "TreeNode.h"

#include <cmath>

using namespace std;

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        return abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int depth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return 1 + max(depth(root->left), depth(root->right));
    }
};

class Solution2
{
public:
    bool isBalanced(TreeNode *root)
    {
        return height(root) != -1;
    }

    int height(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int left_height = height(root->left);
        int right_height = height(root->right);

        // 当存在一个 abs(left_height - right_height) > 1，后面就一直返回 -1
        if (abs(left_height - right_height) > 1 || left_height == -1 || right_height == -1)
        {
            return -1;
        }
        else
        {
            return max(left_height, right_height) + 1;
        }
    }
};