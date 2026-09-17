#include "TreeNode.h"
#include <bits/stdc++.h>
#include <limits>

using namespace std;

class Solution {
public:
  int m_max;
  int maxPathSum(TreeNode *root) {
    m_max = numeric_limits<int>::min();

    int ret = traversal(root);

    return max(m_max, ret);
  }

  int traversal(TreeNode *node) {
    if (!node) {
      return 0;
    }

    int leftsum = traversal(node->left);
    int rightsum = traversal(node->right);

    int sum = leftsum + rightsum + node->val;

    m_max = max(m_max, sum);

    return max(leftsum + node->val, max(rightsum + node->val, 0));
  }
};