#include "List.h"
#include <iostream>
void addBeforeNode(TList& pNode, int elem)
{
	TList p = new Node;
	p->data = elem;
	p->prev = pNode->prev;
	p->next = pNode;
	pNode->prev = p;
	if (p->prev != nullptr)
		p->prev->next = p;
	else
		pNode = p;
}

void addAfterNode(TList pNode, int elem)
{
	TList p = new Node;
	p->data = elem;
	p->next = pNode->next;
	p->prev = pNode;
	pNode->next = p;
	if (p->next != nullptr)
		p->next->prev = p;
}

void deleteAfterNode(TList pNode)
{
	TList p = pNode->next;
	pNode->next = p->next;
	if (p->next != nullptr)
		p->next->prev = pNode;
	p->next = nullptr;
	p->prev = nullptr;
	delete p;
	p = nullptr;
}

void deleteBeforeNode(TList pNode)
{

	if (pNode->prev != nullptr)
	{
		TList p = pNode->prev;
		pNode->prev = p->prev;
		if (p->prev != nullptr)
		{
			p->prev->next = pNode;
			p->prev = nullptr;
		}
		p->next = nullptr;
		delete p;
		p = nullptr;
	}

}

void deleteCurrentNode(TList& pNode)
{
	TList p = pNode;
	if (p->prev != nullptr)
	{
		p->prev->next = p->next;
		p->prev = nullptr;
	}
	else
		pNode = pNode->next;

	if (p->next != nullptr)
	{
		p->next->prev = p->prev;
		p->next = nullptr;
	}

	//pNode->prev = nullptr;
	//pNode->next = nullptr;
	delete p;
	p = nullptr;
}

void init(TList& head, int elem)
{
	head = new Node;
	head->data = elem;
	head->next = nullptr;
	head->prev = nullptr;
}

bool isEmpty(TList head)
{
	return head == nullptr;
}

void printList(TList head)
{
	/*while (head != nullptr)
	{
		std::cout << head->data << " ";
		head = head->next;
	}*/
	TList p = head;
	while (p != nullptr)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
}

void clear(TList& head)
{
	while (head->next != nullptr)
		deleteAfterNode(head);
	delete head;
	head = nullptr;
}

void create(TList& head, int n)
{
	int elem;
	std::cout << "Enter data=";
	std::cin >> elem;
	init(head, elem);
	TList tail = head;

	for (int i = 1; i < n; i++)
	{
		std::cout << "Enter data=";
		std::cin >> elem;
		addAfterNode(tail, elem);
		tail = tail->next;

	}
	//return tail;
	//tail->next = nullptr;
}

TList findTail(TList head)
{
	while (head->next != nullptr)
		head = head->next;
	return head;
}

