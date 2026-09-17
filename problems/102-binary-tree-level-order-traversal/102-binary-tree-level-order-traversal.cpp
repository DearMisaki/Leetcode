#include "TreeNode.h"

#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;

        if (root == nullptr)
        {
            return result;
        }

        traversal(root, result);

        return result;
    }

    void traversal(TreeNode *root, vector<vector<int>> &result)
    {
        queue<TreeNode *> que;

        que.push(root);

        while (!que.empty())
        {
            result.emplace_back(vector<int>());

            // 遍历队列中存在的节点
            // 先取出队列的大小，此时的元素个数就是某一层的元素个数
            int level_size = que.size();

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
    }
};