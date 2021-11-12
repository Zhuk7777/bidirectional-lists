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

void addBeforBeg(TList beg, int elem)
{
	TList p = new Node;
	p->data = elem;
	p->prev = beg->prev;
	p->next = beg;
	beg->prev = p;
	if (p->prev)
		p->prev->next = p;
}

void addAfterBeg(TList beg, int elem)
{
	TList p = new Node;
	p->data = elem;
	p->next = beg->next;
	p->prev = beg;
	beg->next = p;
	p->next->prev = p;
}

void addAfterEnd(TList end, int elem)
{
	TList p = new Node;
	p->data = elem;
	p->next = end->next;
	p->prev = end;
	end->next = p;
	if (p->next)
		p->next->prev = p;
}

void deleteAfterNode(TList pNode,TList& tail)
{ 
	if (pNode != tail) {
		TList p = pNode->next;
		pNode->next = p->next;
		p->prev = nullptr;
		if (p != tail)
		{
			p->next->prev = pNode;
			p->next = nullptr;
		}
		else
			tail = pNode;
		delete p;
		p = nullptr;
	}
}

void deleteBeforeNode(TList pNode, TList& head)
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
		else
			head = pNode;
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
	else
		pNode = pNode->prev;
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

void clear(TList& head, TList& tail)
{
	while (head->next != nullptr)
		deleteAfterNode(head, tail);
	delete head;
	head = nullptr;
	tail = nullptr;
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

TList& findTail(TList head)
{
	while (head->next != nullptr)
		head = head->next;
	return head;
}

TList& findHead(TList tail)
{
	TList p = tail;

	while (p->prev)
		p = p->prev;

	return p;
}

