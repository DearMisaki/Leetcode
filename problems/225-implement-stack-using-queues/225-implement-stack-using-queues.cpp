#include <queue>
#include <memory>

using namespace std;

class MyStack
{
public:
    MyStack()
    {
        q1 = make_shared<queue<int>>();
        q2 = make_shared<queue<int>>();
    }

    void push(int x)
    {
        q2->push(x);
        while (!q1->empty())
        {
            q2->push(q1->front());
            q1->pop();
        }

        swap(q1, q2);
    }

    int pop()
    {
        int data = q1->front();

        q1->pop();

        return data;
    }

    int top()
    {
        return q1->front();
    }

    bool empty()
    {
        return q1->empty();
    }

private:
    shared_ptr<queue<int>> q1;
    shared_ptr<queue<int>> q2;
};