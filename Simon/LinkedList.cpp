#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
	this->m_length = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

LinkedList::~LinkedList()
{
	Node *prev;

	while (head != nullptr)
	{
		prev = head;
		head = head->next;
		delete prev;
	}

	cout << "Single Linked List Deleted" << endl;
}

void LinkedList::Print()
{
	Node *head = this->head;
	int i = 1;

	while (head)
	{
		cout << i << ": " << head->m_data << endl;
		head = head->next;
		i++;
	}
}

void LinkedList::Fill(int a_data)
{
	Node *node = new Node();
	node->m_data = a_data;
	node->next = this->head;
	this->head = node;
	this->m_length++;
}

bool LinkedList::Empty()
{
	return head == nullptr;
}

void LinkedList::PushFront(int a_start)
{
	Node *node = new Node();
	node->m_data = a_start;
	node->next = head;
	head = node;
}

void LinkedList::PushBack(int a_end)
{
	Node *node = new Node();
	node->m_data = a_end;

	if (Empty())
	{
		node->next = head;
		head = node;
	}
	else
	{
		Node *curr = head;

		while (curr->next != nullptr)
			curr = curr->next;

		node->next = curr->next;
		curr->next = node;
	}
}

void LinkedList::Insert(int a_iterator, int a_value, E_INSERT a_insertType)
{
	while (a_insertType != 0 && a_insertType != 1 && a_insertType != 2)
	{
		cout << "Invalid insertion type, default to to 'InsertAfter'" << endl;
		a_insertType = InsertAfter;
	}

	Node *curr = head;
	Node *prev = new Node();
	Node *temp = new Node();

	for (int i = 0; i < a_iterator - a_insertType; ++i)
	{
		prev = curr;
		curr = curr->next;
	}

	temp->m_data = a_value;
	prev->next = temp;
	temp->next = curr;
}

void LinkedList::Erase(int a_iterator)
{
	Node *curr = head;
	Node *prev = new Node();

	for (int i = 1; i < a_iterator; ++i)
	{
		prev = curr;
		curr = curr->next;
	}

	prev->next = curr->next;
}

int LinkedList::Begin()
{
	if (!Empty())
		return 1;

	cout << "This is an empty list" << endl;
	return -1;

}

int LinkedList::End()
{
	Node *curr = head;
	int count = 0;

	if (!Empty())
		count++;
	else
	{
		cout << "Tthis is an empty list" << endl;
		return -1;
	}

	while (curr->next != nullptr)
	{
		curr = curr->next;
		count++;
	}

	return count;
}

int LinkedList::First()
{
	if (!Empty())
		return head->m_data;
	else
	{
		cout << "There are no elements are in the current list" << endl;
		return -1;
	}
}

int LinkedList::Last()
{
	if (!Empty())
	{
		Node *curr = head;

		while (curr->next != nullptr)
			curr = curr->next;

		return curr->m_data;
	}
	else
	{
		cout << "There are no elements om the current list" << endl;
		return -1;
	}
}

void LinkedList::Search(int a_wanted)
{
	if (Empty())
		cout << "The list is empty" << endl;

	else
	{
		bool check = false;
		Node *node = head;

		while (node != nullptr)
		{
			if (node->m_data == a_wanted)
			{
				cout << "Value was found" << endl;
				check = true;
				break;
			}
			else
				node = node->next;
		}

		if (!check)
			cout << "Value could not be found" << endl;
	}
}

int LinkedList::Count()
{
	Node *head = this->head;
	int i = 0;

	while (head)
	{
		head = head->next;
		i++;
	}

	m_length = i;
	return m_length;
}

void LinkedList::Remove(int a_wanted)
{
	Node *curr = head;
	Node *prev = nullptr;

	if (Empty())
		cout << "The list is already empty" << endl;

	else if (curr->m_data == a_wanted)
	{
		head = curr->next;
		delete curr;
	}
	else
	{
		while (curr->m_data != a_wanted && curr->next != nullptr)
		{
			prev = curr;
			curr = curr->next;
		}

		if (curr->next == nullptr && curr->m_data != a_wanted)
			cout << "The value(" << a_wanted << ") was not found in the list" << endl;
		else
		{
			prev->next = curr->next;
			delete curr;
		}
	}
}

void LinkedList::PopFront()
{
	if (Empty())
		cout << "The list is already empty" << endl;

	else
	{
		Node *node = head;
		head = node->next;
		delete node;
	}
}

void LinkedList::PopBack()
{
	if (Empty())
		cout << "The list is already empty" << endl;

	else if (head->next == nullptr)
	{
		Node *node = head;
		head = nullptr;
		delete node;
	}
	else
	{
		Node *curr = head;
		Node *prev = nullptr;

		while (curr->next != nullptr)
		{
			prev = curr;
			curr = curr->next;
		}

		prev->next = nullptr;
		delete curr;
	}
}

void LinkedList::Clear()
{
	Node *node = head->next;

	while (node != nullptr)
	{
		head->next = node->next;
		node->next = nullptr;
		delete node;
		node = head->next;
	}

	PopFront();
}