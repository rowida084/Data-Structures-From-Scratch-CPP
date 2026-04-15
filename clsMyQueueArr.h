#pragma once
#include<iostream>
#include"clsDynamicArray.h"
using namespace std;
template <class t>
class clsMyQueueArr
{
protected:
	clsDynamicArray <t> originalArray;

public:
	void push(t value)
	{
		originalArray.insertAtEnd(value);
	}

	void pop()
	{
		originalArray.deleteFirstItem();
	}

	int size()
	{
		return originalArray.size();
	}

	t front()
	{
		return originalArray.getAtim(0);
	}

	t back()
	{
		return originalArray.getAtim(originalArray.size() - 1);
	}

	void clear()
	{
		originalArray.clear();
	}

	void print()
	{
		originalArray.printList();
	}

	bool isEmpty()
	{
		return originalArray.isEmpty();
	}

};

