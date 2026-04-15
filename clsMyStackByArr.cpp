#pragma once
#include<iostream>
#include"clsDynamicArray.h"
using namespace std;

template <class t>
class clsMyStackArr
{
protected :
	clsDynamicArray<t> _list;

public:
	void push(t value)
	{
		_list.insertAtEnd(value);
	}

	void pop()
	{
		_list.deleteLastItem();
	}

	void clear()
	{
		_list.clear();
	}

	void print()
	{
		_list.printList();
	}

	bool isEmpty()
	{
		return _list.isEmpty();
	}

	t top()
	{
		return _list[_list.size() - 1];
	}

	int size()
	{
		return _list.size();
	}


};

