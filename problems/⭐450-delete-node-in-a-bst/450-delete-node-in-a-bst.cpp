#include <TreeNode.h>

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->val == key)
        {
            // 边界条件：
            // 1. 只有一边子树 2. 两边子树 3. 两边子树都没有

            // 这段代码会执行两次
            // 1. 找到要删除的节点，并且其没有右子树，字节返回左子树
            // 2. 上一步已经执行替换操作，此步将删除替换节点（必然是叶子节点），返回 null
            if (!root->right)
            {
                return root->left;
            }

            TreeNode *current = root->right;
            while (current->left)
            {
                current = current->left;
            }

            std::swap(root->val, current->val);

            // 这里不能直接用 return root ！因为从此节点往下找到替换节点后还要将其删除
            // 重点是将父节点的 left 替换为 null
            // current 指向 替换节点，不能将这个替换节点之间直接删除，否则会使其变成野指针
        }

        if (root->left)
            root->left = deleteNode(root->left, key);

        if (root->right)
            root->right = deleteNode(root->right, key);

        return root;
    }
};

