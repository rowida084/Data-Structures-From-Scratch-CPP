#pragma once
#include<iostream>
#include"clsDblLinkedList.h"
template <class t>
class clsMyQueue
{
protected:
	clsDblLinkedList<t> _myList;

public:
	void push(t value)
	{
		_myList.insertAtEnd(value);
	}

	void pop()
	{
		_myList.deleteFirstNode();
	}

	bool isEmpty()
	{
		return _myList.isEmpty();
	}

	int size()
	{
		return _myList.size();
	}

	void print()
	{
		_myList.printList();
	}

	t front()
	{
		return _myList.getItem(0);
	}

	t back()
	{
		return _myList.getItem(size() - 1);
	}
	
	//these functions are not in queue (delete them when post it)

	t getItem(int index)
	{
		return _myList.getItem(index);
	}
	
	void reverse()
	{
		_myList.reverse();
	}

	void update(int index, t value)
	{
		_myList.updateItem(index, value);
	}

	void insertAfter(int index, t value)
	{
		_myList.insertAfter(index, value);
	}

	void insertBack(t value)
	{
		_myList.insertAtEnd(value);
	}

	void clear() {
		_myList.clear();
	}

};

