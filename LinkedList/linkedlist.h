#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <initializer_list>

template <typename T>
class LinkedList
{
  private:
    struct Node
    {
        T value{};
        Node* next{nullptr};
    };

    Node* m_head{};
    Node* m_tail{};
    int m_length{};

  public:
    LinkedList() = default;

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    explicit LinkedList(T val) : m_head{new Node(val)}, m_tail{m_head}, m_length{1} {};

    LinkedList(std::initializer_list<T> list)
    {
        for (const auto& val : list)
        {
            if (m_tail)
            {
                m_tail->next = new Node{val};
                m_tail = m_tail->next;
            }
            else
            {
                m_head = new Node{val};
                m_tail = m_head;
            }
            ++m_length;
        }
    }

    ~LinkedList()
    {
        Node* temp{m_head};
        while (m_head)
        {
            m_head = m_head->next;
            delete temp;
            temp = m_head;
        }
    }
};

#endif // !LINKEDLIST_H
