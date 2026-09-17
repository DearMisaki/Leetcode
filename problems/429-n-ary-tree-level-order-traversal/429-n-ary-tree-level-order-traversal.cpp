#include <vector>
#include <queue>

using namespace std;

// n叉树
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> result;

        if (root == nullptr)
        {
            return result;
        }

        queue<Node *> que;

        que.push(root);

        while (!que.empty())
        {
            result.emplace_back();

            size_t level_size = que.size();

            for (size_t i = 0; i < level_size; i++)
            {
                Node *node = que.front();
                que.pop();

                for (auto const& child: node->children)
                {
                    if (child)
                    {
                        que.push(child);
                    }
                }

                result.back().push_back(node->val);
            }
        }

        return result;
    }
};