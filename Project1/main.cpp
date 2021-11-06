//есть число С. Переставить значения элементов так, чтобы сначала следовали(в произвольном порядке) 
//элементы, меньшие числа С, затем не меньшие числа С
#include <iostream>
#include "List.h"
#include <Windows.h>
int main()
{
    SetConsoleOutputCP(1251);
    TList head = nullptr;
    int n;
    std::cout << "Введите количество элементов в списке" << std::endl;
    std::cin >> n;
    create(head, n);


    TList oldTail = findTail(head);
    TList tail = oldTail;
    int c;
    std::cout << "Введите С" << std::endl;
    std::cin >> c;

    TList p = head;
    while (p != oldTail)
    {
        if (p->data > c)
        {
            TList tmp = p;
            p = p->next;
            addAfterNode(tail, tmp->data);
            deleteCurrentNode(tmp);
            tail = tail->next;
        }
        else
        {
            if (p->data < c)
            {
                TList tmp = p;
                p = p->next;
                addBeforeNode(head, tmp->data);
                deleteCurrentNode(tmp);
            }
        }

    }
    printList(head);
    return 0;
}

