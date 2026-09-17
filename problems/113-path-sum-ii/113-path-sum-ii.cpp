#include "TreeNode.h"

#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        dfs(root, targetSum);

        return result;
    }

    void dfs(TreeNode *node, int targetSum)
    {
        if (node == nullptr)
        {
            return;
        }

        targetSum -= node->val;
        path.emplace_back(node->val);

        if (!node->left && !node->right && targetSum == 0)
        {
            result.push_back(path);
        }

        dfs(node->left, targetSum);
        dfs(node->right, targetSum);

        path.pop_back();
    }

private:
    vector<int> path;

    vector<vector<int>> result;
};