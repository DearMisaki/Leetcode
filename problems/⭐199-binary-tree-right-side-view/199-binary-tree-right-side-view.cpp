#include "TreeNode.h"

#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;

        if (root == nullptr)
        {
            return result;
        }

        vector<vector<int>> level_traversal;

        queue<TreeNode *> que;

        que.push(root);

        // 先取得层序遍历的值
        while (!que.empty())
        {
            int level_size = que.size();

            level_traversal.emplace_back();

            for (int i = 0; i < level_size; i++)
            {
                TreeNode *node = que.front();
                que.pop();

                level_traversal.back().push_back(node->val);

                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }

        // 取出每层的最后一个数
        for (auto const &vec : level_traversal)
        {
            result.push_back(vec.back());
        }

        return result;
    }
};

class Solution2
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;

        if (root == nullptr)
        {
            return result;
        }

        int max_depth = -1;;

        stack<pair<TreeNode*, int>> node_stack;

        // depth -> node
        unordered_map<int, TreeNode *> rightmost_node;

        node_stack.push({root, 0});

        while (!node_stack.empty())
        {
            auto [node, depth] = node_stack.top();
            node_stack.pop();

            max_depth = max(max_depth, depth);

            // 当前层不存在任何元素，则插入元素
            // 下面是先插入 left，再插入 right，所以实际插入的时候总是最右边的值
            if (rightmost_node.find(depth) == rightmost_node.end())
                rightmost_node[depth] = node;

            if (node->left)
            {
                node_stack.push({node->left, depth + 1});
            }

            if (node->right)
            {
                node_stack.push({node->right, depth + 1});
            }
        }
        
        for (int i = 0; i <= max_depth; i++)
        {
            result.push_back(rightmost_node[i]->val);
        }
        
        return result;
    }
};