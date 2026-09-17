#include "TreeNode.h"

#include <stack>

using namespace std;

// 使用递归深度优先搜索的优势在于函数的栈帧能自动恢复现场，不用保存每一步的中间值。验证时方便快捷
// 比如下面递归调用后的 sum -= node->val
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int sum = 0;

        return dfs(root, sum, targetSum);
    }

    bool dfs(TreeNode *node, int &sum, int target)
    {
        if (node == nullptr)
        {
            return false;
        }

        sum += node->val;

        if (!node->left && !node->right && sum == target)
        {
            return true;
        }
        else if (!node->left && !node->right && sum != target)
        {
            // 回溯叶子节点到中间节点
            sum -= node->val;
            return false;
        }

        bool left = dfs(node->left, sum, target);
        bool right = dfs(node->right, sum, target);

        // 回溯中间节点到上一个节点
        sum -= node->val;

        // 当前中间节点的左右子树的满足状态
        return left || right;
    }
};

class Solution2
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return false;
        }

        stack<pair<TreeNode *, int>> node_stack;

        node_stack.push({root, root->val});

        while (!node_stack.empty())
        {
            auto [node, sum] = node_stack.top(); node_stack.pop();

            if (!node->left && !node->right && sum == targetSum)
            {
                return true;
            }

            if (node->right)
            {
                node_stack.push({node->right, sum + node->right->val});
            }

            if (node->left)
            {
                node_stack.push({node->left, sum + node->left->val});
            }
        }
        return false;
    }
};