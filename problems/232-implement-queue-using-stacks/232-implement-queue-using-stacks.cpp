#include <stack>

using namespace std;

class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        stack1.push(x);
    }

    int pop()
    {
        int data;

        if (!stack2.empty())
        {
            data = stack2.top();
            stack2.pop();

            return data;
        }

        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }

        data = stack2.top();
        stack2.pop();

        return data;
    }

    int peek()
    {
        int data = pop();

        stack2.push(data);

        return data;
    }

    bool empty()
    {
        if (stack1.empty() && stack2.empty())
        {
            return true;
        }
        return false;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */