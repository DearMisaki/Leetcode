#include "TreeNode.h"

#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;

        if (root == nullptr)
        {
            return result;
        }

        stack<pair<TreeNode *, string>> node_stack;
        node_stack.push({root, to_string(root->val)});

        while (!node_stack.empty())
        {
            auto [node, path] = node_stack.top();
            node_stack.pop();

            if (!node->left && !node->right)
            {
                result.push_back(path);
            }

            if (node->right)
            {
                node_stack.push({node->right, path + "->" + to_string(node->right->val)});
            }

            if (node->left)
            {
                node_stack.push({node->left, path + "->" + to_string(node->left->val)});
            }
        }
        
        return result;
    }
};