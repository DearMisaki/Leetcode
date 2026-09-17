#include <bits/stdc++.h>
#include <stack>

#include "TreeNode.h"

using namespace std;

class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    TreeNode *curr = root;

    stack<TreeNode *> nodestack;

    nodestack.push(root);

    while (curr || !nodestack.empty()) {
      if (curr) {
        nodestack.push(curr);
        curr = curr->left;
      } else {
        TreeNode *node = nodestack.top();
        nodestack.pop();
        --k;

        if (k == 0) {
          return node->val;
        }

        if (node->right) {
          curr = curr->right;
        }
      }
    }

    return -1;
  }
};