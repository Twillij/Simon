#include "SequenceArray.h"


SequenceArray::SequenceArray()
{
	m_cap = 5;
	arr = new int[m_cap];
	arr[0] = -1;
}

SequenceArray::SequenceArray(int a_cap)
{
	m_cap = a_cap;
	arr = new int[m_cap];

	for (int i = 0; i < m_size; i++)
		arr[i] = -1;
}

SequenceArray::SequenceArray(const SequenceArray &old)
{
	for (int i = 0; i < m_size; i++)
		arr[i] = old.arr[i];
}

SequenceArray::~SequenceArray()
{
	delete[] arr;
}

void SequenceArray::PushBack(int a_value)
{
	// if full, construct a new arr with a bigger size and copy the previous values
	// if not full, then simply insert the value to the end

	m_size++;

	if (m_size > m_cap)
	{
		m_cap *= 2;
		int* temp = new int[m_cap];

		for (int i = 0; i < m_size; i++)
			temp[i] = arr[i];

		delete[] arr;

		arr = temp;
	}

	arr[m_size - 1] = a_value;
}

void SequenceArray::PushFront(int a_value)
{
	m_size++;

	if (m_size > m_cap)
	{
		m_cap *= 2;
		int* temp = new int[m_cap];

		for (int i = 0; i < m_size; i++)
			temp[i] = arr[i];

		delete[] arr;

		arr = temp;
	}

	for (int i = 1; i < m_size - 1; i++)
	{
		arr[m_size - i] = arr[m_size - i - 1];
	}

	arr[1] = arr[0];
	arr[0] = a_value;
}

void SequenceArray::PopBack()
{
	m_size--;
	arr[m_size] = -1;
}

void SequenceArray::PopFront()
{
	m_size--;

	for (int i = 0; i < m_size; i++)
		arr[i] = arr[i + 1];

	arr[m_size] = -1;
}

void SequenceArray::Resize()
{
	int* temp = new int[m_size];

	for (int i = 0; i < m_size; i++)
		temp[i] = arr[i];

	delete[] arr;

	arr = temp;
}

void SequenceArray::Clear()
{
	for (int i = 0; i < m_size; ++i)
	{
		arr[i] = -1;
	}

	m_size = 0;
}