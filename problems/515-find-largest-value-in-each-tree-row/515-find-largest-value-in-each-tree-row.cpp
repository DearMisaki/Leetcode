#include "TreeNode.h"

#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> result;

        if (root == nullptr)
        {
            return result;
        }

        queue<TreeNode *> que;

        que.push(root);

        while (!que.empty())
        {
            size_t level_size = que.size();

            int level_max = numeric_limits<int>::min();

            for (size_t i = 0; i < level_size; i++)
            {
                TreeNode *node = que.front();
                que.pop();

                if (node->left)
                {
                    que.push(node->left);
                }

                if (node->right)
                {
                    que.push(node->right);
                }

                level_max = max(node->val, level_max);
            }

            result.push_back(level_max);
        }

        return result;
    }
};