#include "TreeNode.h"

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

        traversal(root, result);

        return result;
    }

    void traversal(TreeNode* root, vector<int>& result)
    {
        if (root == nullptr)
        {
            return;
        }

        traversal(root->left, result);
        traversal(root->right, result);

        result.push_back(root->val);
    }
};

class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return vector<int>();

        stack<TreeNode*> node_stack;
        vector<int> result;

        TreeNode* curr = root;
        TreeNode* last_visited = nullptr;
        
        while (curr || !node_stack.empty())
        {
            // 一直往左下走
            if (curr)
            {
                node_stack.push(curr);
                curr = curr->left;

                continue;
            }
            else
            {
                TreeNode* prev = node_stack.top();

                // 往左走到头了，现在往右走，下一次循环再往左走
                // 回溯到上一个节点时，会再次判断右节点，所以要有个标签判断
                if (prev->right && prev->right != last_visited)
                {
                    curr = prev->right;
                }
                // 往上回溯
                else
                {
                    result.push_back(prev->val);
                    node_stack.pop();

                    // 指向输出节点的下面那个节点，
                    // 当前节点存在右节点时，指向这个右节点
                    last_visited = prev;
                }
            }
        }

        return result;
    }
};