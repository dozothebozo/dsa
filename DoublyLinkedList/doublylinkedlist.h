#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <initializer_list>
#include <iostream>

template <typename T>
class DoublyLinkedList
{
  private:
    struct Node
    {
        T value{};
        Node* next{nullptr};
        Node* prev{nullptr};
    };

    Node* m_head{};
    Node* m_tail{};
    int m_length{};

  public:
    DoublyLinkedList() = default;

    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    explicit DoublyLinkedList(T val) : m_head{new Node{val}}, m_tail{m_head}, m_length{1} {};

    DoublyLinkedList(std::initializer_list<T> list)
    {
        for (const auto& val : list)
            append(val);
    }

    ~DoublyLinkedList()
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

    Node* head() const
    {
        return m_head;
    }

    Node* tail() const
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
            node->prev = m_tail;
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
            Node* temp{m_tail};
            m_tail = m_tail->prev;
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
            m_head->prev = node;
            m_head = node;
        }
        m_length++;
    }

    void deleteHead()
    {
        if (!m_head)
            return;
        if (m_head->next)
        {
            Node* temp{m_head};
            m_head = m_head->next;
            m_head->prev = nullptr;
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

    Node* get(int index)
    {
        if (index < 0 || index >= m_length)
            return nullptr;
        if (index < (m_length / 2))
        {
            Node* temp{m_head};
            for (int i{0}; i < index; ++i)
            {
                temp = temp->next;
            }
            return temp;
        }
        else
        {
            Node* temp{m_tail};
            for (int i{m_length - 1}; i > index; --i)
            {
                temp = temp->prev;
            }
            return temp;
        }
    }

    bool set(int index, T val)
    {
        Node* node{get(index)};
        if (node)
        {
            node->value = val;
            return true;
        }
        return false;
    }

    bool insert(int index, T val)
    {
        if (index < 0 || index > m_length)
            return false;
        if (index == 0)
        {
            prepend(val);
            return true;
        }
        if (index == m_length)
        {
            append(val);
            return true;
        }
        Node* node{new Node{val}};
        Node* before{get(index - 1)};
        Node* after{before->next};
        node->prev = before;
        node->next = after;
        before->next = node;
        after->prev = node;
        m_length++;
        return true;
    }

    void deleteNode(int index)
    {
        if (index < 0 || index >= m_length)
            return;
        if (index == 0)
        {
            deleteHead();
            return;
        }
        if (index == (m_length - 1))
        {
            pop();
            return;
        }
        Node* temp{get(index)};
        Node* before{temp->prev};
        Node* after{temp->next};
        before->next = after;
        after->prev = before;
        delete temp;
        m_length--;
    }
};

#endif // !DOUBLYLINKEDLIST_H
