#pragma once

class Node
{
public:
	Node();
	Node(int a_data);
	~Node();

	Node* next;
	Node* prev;
	int m_data; // the value being stored
};