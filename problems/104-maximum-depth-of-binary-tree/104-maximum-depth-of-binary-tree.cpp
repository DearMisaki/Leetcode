#include "TreeNode.h"

#include <queue>

using namespace std;

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        queue<TreeNode*> que;

        que.push(root);

        int depth = 0;

        while (!que.empty())
        {
            size_t level_size = que.size();

            for (size_t i = 0; i < level_size; i++)
            {
                TreeNode* node = que.front(); que.pop();

                if (node->left)
                {
                    que.push(node->left);
                }

                if (node->right)
                {
                    que.push(node->right);
                }
            }
            
            depth += 1;
        }

        return depth;
        
    }
};

class Solution2
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }

        int max_depth = 0;

        if (root->left)
        {
            max_depth = max(maxDepth(root->left), max_depth);
        }

        if (root->right)
        {
            max_depth = max(maxDepth(root->right), max_depth);
        }

        return max_depth + 1;
    }
};