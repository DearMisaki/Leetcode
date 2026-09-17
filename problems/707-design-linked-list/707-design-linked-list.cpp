
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyLinkedList
{
private:
    struct ListNode *m_dummyhead;
    int m_size;

public:
    MyLinkedList()
    {
        m_dummyhead = new ListNode();
        m_size = 0;
    }

    int get(int index)
    {
        if (index > m_size - 1 || index < 0)
            return -1;

        ListNode *node = m_dummyhead->next;
        while (index--)
        {
            node = node->next;
        }
        return node->val;
    }

    void addAtHead(int val)
    {
        ListNode *node = new ListNode(val, m_dummyhead->next);
        m_dummyhead->next = node;
        ++m_size;
    }

    void addAtTail(int val)
    {
        ListNode *node = m_dummyhead;

        while (node->next != nullptr)
        {
            node = node->next;
        }
        ListNode *new_node = new ListNode(val, nullptr);
        node->next = new_node;
        ++m_size;
    }

    void addAtIndex(int index, int val)
    {
        if (index > m_size) return;
        if (index <= 0) return addAtHead(val);

        ListNode *node = m_dummyhead;
        while (index--)
        {
            node = node->next;
        }
        ListNode *new_node = new ListNode(val, node->next);
        node->next = new_node;
        ++m_size;
    }

    void deleteAtIndex(int index)
    {
        if (index > m_size - 1 || index < 0) return;

        ListNode *node = m_dummyhead;
        while (index--)
        {
            node = node->next;
        }
        ListNode *old_node = node->next;
        node->next = old_node->next;
        delete old_node;
        old_node = nullptr;
        -- m_size;
    }
};