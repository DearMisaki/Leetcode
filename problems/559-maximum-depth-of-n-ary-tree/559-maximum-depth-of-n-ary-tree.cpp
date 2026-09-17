#include <vector>
#include <queue>

using namespace std;

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

class Solution2
{
public:
    int maxDepth(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        queue<Node *> que;

        que.push(root);

        int depth = 0;

        while (!que.empty())
        {
            size_t level_size = que.size();

            for (size_t i = 0; i < level_size; i++)
            {
                Node *node = que.front(); que.pop();

                for (auto const &n : node->children)
                {
                    if (n)
                    {
                        que.push(n);
                    }
                }
            }
            depth += 1;
        }
        return depth;
    }
};