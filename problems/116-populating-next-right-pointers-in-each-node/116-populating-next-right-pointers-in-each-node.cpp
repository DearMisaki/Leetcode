#include <queue>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {

        if (root == nullptr)
        {
            return nullptr;
        }

        queue<Node *> que;

        que.push(root);

        while (!que.empty())
        {
            size_t level_size = que.size();

            for (size_t i = 0; i < level_size; i++)
            {
                Node *node = que.front();
                que.pop();
                
                if (i == level_size - 1)
                {
                    node->next = nullptr;
                }
                else
                {
                    node->next = que.front();
                }

                if (node->left)
                {
                    que.push(node->left);
                }

                if (node->right)
                {
                    que.push(node->right);
                }
            }
        }

        return root;
    }
};