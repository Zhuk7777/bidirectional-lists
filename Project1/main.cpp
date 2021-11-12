//есть число С. Переставить значения элементов так, чтобы сначала следовали(в произвольном порядке) 
//элементы, меньшие числа С, затем не меньшие числа С
#include <iostream>
#include "List.h"
#include <Windows.h>

void sortList(TList& head,int elem) {

    TList beg = new Node;
    TList end = new Node;

    beg->next = end;
    end->prev = beg;

    beg->prev = nullptr;
    end->next = nullptr;

    TList p = head;

    while (p)
    {
        if (p->data < elem)
            addBeforBeg(beg, elem);

        if (p->data > elem)
            addAfterEnd(end, elem);

        if (p->data == elem)
            addAfterBeg(beg, elem);

        p = p->next;
    }

    TList tail = findTail(head);
    clear(head, tail);

    head = findHead(beg);

    deleteCurrentNode(beg);
    deleteCurrentNode(end);
    
}

int main()
{
    SetConsoleOutputCP(1251);

    TList head = nullptr;
    int size, c;

    std::cout << "Введите количество элементов в списке\n";
    std::cin >> size;
    create(head, size);

    std::cout << "Введите с\n";
    std::cin >> c;

    sortList(head, c);

    printList(head);

    return 0;
}

