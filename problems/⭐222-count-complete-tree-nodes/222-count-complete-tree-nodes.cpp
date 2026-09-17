#include "TreeNode.h"

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

class Solution2
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        if (!root->left && !root->right)
        {
            return 1;
        }

        TreeNode *node = root;

        int depth = 0;

        // 获取完全二叉树的深度
        while (node->left)
        {
            node = node->left;
            ++depth;
        }

        // 完全二叉树节点数量介于 [1, 1 << (depth + 1) - 1] 之间， depth 从 0 开始
        // 使用二分查找，查找二叉树的节点个数；对于每个 mid 节点使用 check 函数在 **最后一层** 判断其是否存在
        int low = 1 << depth; // 最后一层的第一个节点
        int high = (1 << (depth + 1)) - 1;
        int mid;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (check(root, depth, mid))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        // high 是最后一个存在，low 是第一个不存在的节点
        return high;
    }

    // check 函数从 root 节点开始，按路径查找当前节点是否存在，依赖完全二叉树编号的绘制
    // 左 0 右 1，例如编号为 2 的节点 -> 10；为 3 的节点 -> 11
    bool check(TreeNode *root, int depth, int k)
    {
        // 从 k 的次高位开始判断
        int bits = 1 << (depth - 1);

        while (root && bits > 0)
        {
            if (!(bits & k))
            {
                root = root->left;
            }            
            else
            {
                root = root->right;
            }
            bits >>= 1;
        }

        return root != nullptr;
    }
};