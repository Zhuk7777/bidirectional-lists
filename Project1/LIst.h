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

void deleteAfterNode(TList pNode);
void deleteBeforeNode(TList pNode);
void deleteCurrentNode(TList& pNode);

void init(TList& head, int elem);

bool isEmpty(TList head);

void printList(TList head);

void clear(TList& head);

void create(TList& head, int n);

TList findTail(TList head);


