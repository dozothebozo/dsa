#include "doublylinkedlist.h"
#include <iostream>

int main()
{
    DoublyLinkedList<int> ddl1{};
    DoublyLinkedList<int> ddl2{'a'};
    DoublyLinkedList<int> ddl3{6, 7, 7, 6};
    DoublyLinkedList<int> ddl4{'t', 'a', 't', 't', 'a', 'r', 'r', 'a', 't', 't', 'a', 't'};

    std::cout << std::boolalpha;

    std::cout << ddl1.isPalindrome() << '\n';
    std::cout << ddl2.isPalindrome() << '\n';
    std::cout << ddl3.isPalindrome() << '\n';
    std::cout << ddl4.isPalindrome() << '\n';
}
