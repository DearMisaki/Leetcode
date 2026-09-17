#include "TreeNode.h"

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
        {
            umap[inorder[i]] = i;
        }

        post_index = postorder.size() - 1;

        return build(inorder, postorder, 0, inorder.size() - 1);

    }

    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(postorder[post_index--]);

        auto root_index = umap[root->val];
        
        root->right = build(inorder, postorder, root_index + 1, right);
        root->left = build(inorder, postorder, left, root_index - 1);

        return root;
    }

private:
    // val -> inorder 下标
    unordered_map<int, int> umap;

    int post_index;
};