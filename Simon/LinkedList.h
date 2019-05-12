#pragma once
#include "Node.h"

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	enum E_INSERT { InsertAfter = 0, InsertAt = 1, InsertBefore = 2 };

	Node *head;
	Node *tail;
	int m_length;

	void Print();

	void Fill(int a_data);

	bool Empty(); // true if list is empty

	void PushFront(int a_start); // add a new value to the front of the list

	void PushBack(int a_end); // add a new value to the end of the list

	void Insert(int a_iterator, int a_value, E_INSERT a_insertType);

	void Erase(int a_iterator);

	int Begin();
	int End();

	int First();
	int Last();

	void Search(int a_wanted);

	int Count();

	void Remove(int a_wanted); // remove all elements with matching values

	void PopFront(); // remove the first element
	void PopBack(); // remove the last element

	void Clear(); // remove all elements in the list
};