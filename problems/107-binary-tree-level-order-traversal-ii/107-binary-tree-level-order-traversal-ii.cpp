#include "TreeNode.h"

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;

        if (root == nullptr)
        {
            return result;
        }

        queue<TreeNode *> que;

        que.push(root);

        while (!que.empty())
        {
            int level_size = que.size();

            result.emplace_back(vector<int>());

            for (int i = 0; i < level_size; ++i)
            {
                TreeNode *node = que.front();
                que.pop();

                result.back().push_back(node->val);

                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};