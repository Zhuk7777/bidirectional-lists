#pragma once
struct Node
{
	int data;
	Node* next;
	Node* prev;
};
typedef Node* TList;
void addBeforeNode(TList& head, int elem);
void addAfterNode(TList pNode, int elem);

void addBeforBeg(TList beg, int elem);
void addAfterBeg(TList beg, int elem);
void addAfterEnd(TList end, int elem);

void deleteAfterNode(TList pNode, TList& tail);
void deleteBeforeNode(TList pNode, TList& head);
void deleteCurrentNode(TList& pNode);

void init(TList& head, int elem);

bool isEmpty(TList head);

void printList(TList head);

void clear(TList& head, TList& tail);

void create(TList& head, int n);

TList& findTail(TList head);
TList& findHead(TList tail);


