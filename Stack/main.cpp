#include "stack.h"
#include <iostream>

int main()
{
    Stack<int> s{10, 20, 30};

    std::cout << s.top() << '\n';

    s.pop();

    std::cout << s.top() << '\n';

    s.push(40);

    std::cout << s.top() << '\n';
}
