#include "TreeNode.h"
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    TreeNode *root = tranversal(preorder, inorder);

    return root;
  }

  TreeNode *tranversal(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() <= 0) {
      return nullptr;
    }

    int val = preorder[0];

    TreeNode *node = new TreeNode(val);

    if (preorder.size() == 1) {
      return node;
    }

    int i;

    for (i = 0; i < inorder.size(); ++i) {
      if (inorder[i] == val) {
        break;
      }
    }

    vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + i + 1);
    vector<int> right_preorder(preorder.begin() + i + 1, preorder.end());

    vector<int> left_inorder(inorder.begin(), inorder.begin() + i);
    vector<int> right_inorder(inorder.begin() + i + 1, inorder.end());

    // 对应 inorder 中第 i 个节点
    node->left = tranversal(left_preorder, left_inorder);
    node->right = tranversal(right_preorder, right_inorder);

    return node;
  }
};