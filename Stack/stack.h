#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include <initializer_list>
#include <vector>

template <typename T>
class Stack
{
  private:
    std::vector<T> m_data{};

  public:
    Stack() = default;

    Stack(std::initializer_list<T> list) : m_data{list}
    {
    }

    void push(const T& val)
    {
        m_data.push_back(val);
    }

    void pop()
    {
        if (!m_data.empty())
            m_data.pop_back();
    }

    const T& top() const
    {
        return m_data.back();
    }

    bool empty() const
    {
        return m_data.empty();
    }

    std::size_t size() const
    {
        return m_data.size();
    }
};

#endif // STACK_H
