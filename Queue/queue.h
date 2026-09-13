#ifndef QUEUE_H
#define QUEUE_H

#include <initializer_list>

template <typename T>
class Queue
{
  private:
    struct Node
    {
        T value{};
        Node* next{nullptr};
    };

    Node* m_first{};
    Node* m_last{};
    int m_length{};

  public:
    Queue() = default;

    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    explicit Queue(const T& val) : m_first{new Node{val}}, m_last{m_first}, m_length{1}
    {
    }

    Queue(std::initializer_list<T> list)
    {
        for (const auto& val : list)
            enqueue(val);
    }

    ~Queue()
    {
        while (!m_first)
            dequeue();
    }

    void enqueue(const T& val)
    {
        Node* node{new Node{val}};
        if (!m_first)
        {
            m_first = node;
            m_last = node;
        }
        else
        {
            m_last->next = node;
            m_last = node;
        }
        ++m_length;
    }

    void dequeue()
    {
        if (!m_first)
            return;
        Node* temp{m_first};
        m_first = m_first->next;
        delete temp;
        --m_length;
        if (!m_first)
            m_last = nullptr;
    }

    const T& first() const
    {
        return m_first->value;
    }

    const T& last() const
    {
        return m_last->value;
    }

    int length() const
    {
        return m_length;
    }

    bool empty() const
    {
        return !m_first;
    }
};

#endif // QUEUE_H
