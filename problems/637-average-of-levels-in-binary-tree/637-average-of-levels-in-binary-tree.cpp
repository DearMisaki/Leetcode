#include "TreeNode.h"

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;

        if (root == nullptr)
        {
            return result;
        }

        queue<TreeNode*> que;

        que.push(root);

        while (!que.empty())
        {
            size_t level_size = que.size();

            double level_average = 0;

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

                level_average += node->val;
            }
            
            level_average /= level_size;
            result.push_back(level_average);
        }

        return result;
    }
};