#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <initializer_list>
#include <iostream>

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

    explicit LinkedList(T val) : m_head{new Node{val}}, m_tail{m_head}, m_length{1} {};

    LinkedList(std::initializer_list<T> list)
    {
        for (const auto& val : list)
            append(val);
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

    int length() const
    {
        return m_length;
    }

    const Node* head() const
    {
        return m_head;
    }

    const Node* tail() const
    {
        return m_tail;
    }

    void print() const
    {
        Node* temp{m_head};
        while (temp)
        {
            std::cout << temp->value << ' ';
            temp = temp->next;
        }
        std::cout << '\n';
    }

    void append(T val)
    {
        Node* node{new Node{val}};
        if (m_head)
        {
            m_tail->next = node;
            m_tail = node;
        }
        else
        {
            m_head = node;
            m_tail = node;
        }
        m_length++;
    }

    void pop()
    {
        if (!m_head)
            return;

        if (m_head->next)
        {
            Node* temp{m_head};
            Node* pre{m_head};
            while (temp->next)
            {
                pre = temp;
                temp = temp->next;
            }
            m_tail = pre;
            m_tail->next = nullptr;
            delete temp;
        }
        else
        {
            delete m_head;
            m_head = nullptr;
            m_tail = nullptr;
        }

        m_length--;
    }

    void prepend(T val)
    {
        Node* node{new Node{val}};
        if (!m_head)
        {
            m_head = node;
            m_tail = node;
        }
        else
        {
            node->next = m_head;
            m_head = node;
        }
        m_length++;
    }
};

#endif // !LINKEDLIST_H
