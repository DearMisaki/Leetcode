#include "TreeNode.h"
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void flatten(TreeNode *root) {
    TreeNode *curr = root;

    while (curr) {
      if (curr->left == nullptr) {
        curr = curr->right;
        continue;
      }

      auto next = curr->left;

      auto pre = next;

      while (pre->right) {
        pre = pre->right;
      }

      pre->right = curr->right;

      curr->right = curr->left;

      curr->left = nullptr;
      curr = curr->right;
    }
  }
};