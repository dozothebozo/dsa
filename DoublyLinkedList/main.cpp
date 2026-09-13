#include "doublylinkedlist.h"
#include <iostream>

int main()
{
    DoublyLinkedList<int> ddl{1};
    ddl.append(3);
    ddl.insert(1, 2);
    ddl.print();
}
