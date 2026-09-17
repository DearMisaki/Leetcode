#include "TreeNode.h"

#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return root;
        }

        queue<TreeNode *> que;

        que.push(root);

        while (!que.empty())
        {
            TreeNode *node = que.front(); que.pop();

            swap(node->left, node->right);

            if (node->left)
            {
                que.push(node->left);
            }

            if (node->right)
            {
                que.push(node->right);
            }
        }

        return root;
    }
};

class Solution2
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        stack<TreeNode*> node_stack;

        TreeNode* curr = root;

        while (curr || !node_stack.empty())
        {
            if (curr)
            {
                node_stack.push(curr);
                curr = curr->left;
            }
            else
            {
                TreeNode* prev = node_stack.top(); node_stack.pop();

                swap(prev->left, prev->right);

                if (prev->left)
                {
                    curr = prev->left;
                }
            }
        }
        return root;
    }
};