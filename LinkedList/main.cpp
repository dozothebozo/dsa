#include "linkedlist.h"
#include <iostream>
#include <string_view>

template <typename T>
void printMiddleNode(std::string_view label, LinkedList<T>& linkedlist)
{
    const auto* mid{linkedlist.middleNode()};
    if (mid)
    {
        std::cout << label << ": " << mid->value << '\n';
    }
    else
    {
        std::cout << label << ": empty\n";
    }
}

int main()
{
    LinkedList even{1, 2, 3, 4, 5, 6};
    LinkedList odd{1.5, 2.1, 3.67, 4.4, 5.67676};
    LinkedList<int> ll{};

    printMiddleNode("even", even);
    printMiddleNode("odd", odd);
    printMiddleNode("ll", ll);

    return 0;
}
