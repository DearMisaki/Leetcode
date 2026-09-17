#include "TreeNode.h"

#include <queue>
#include <limits>

using namespace std;

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        // 空间复杂度 O(N)
        queue<TreeNode*> que;

        que.push(root);

        int depth = 0;

        while (!que.empty())
        {
            size_t level_size = que.size();

            for (size_t i = 0; i < level_size; i++)
            {
                TreeNode* node = que.front(); que.pop();

                if (!node->left && !node->right)
                {
                    return depth + 1;
                }

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


class Solution2 {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }

       int min_depth = numeric_limits<int>::max();
       
       if (root->left)
       {
            min_depth = min(minDepth(root->left), min_depth);
       }

       if (root->right)
       {
            min_depth = min(minDepth(root->right), min_depth);
       }

       return min_depth + 1;
    }
};