#pragma once
#include <iostream>

using namespace std;

class SequenceArray
{
private:
	int* arr;
	int m_cap = 1;
	int m_size = 0;

public:
	SequenceArray();
	SequenceArray(int a_size);
	SequenceArray(const SequenceArray &old);
	~SequenceArray();

	int* getArray() { return arr; }
	int getCap() { return m_cap; }
	int getSize() { return m_size; }

	void PushBack(int a_value);
	void PushFront(int a_value);
	void PopBack();
	void PopFront();
	void Resize();
	void Clear();
};