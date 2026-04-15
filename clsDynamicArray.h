#pragma once
#include<iostream>
using namespace std;
template <class t>
class clsDynamicArray
{
protected:
int _size = 0;
    t* _tempArray;

public:
	t* originalArray;
	
	clsDynamicArray(int size = 0)
	{
		if (size < 0)
			size = 0;

		_size = size;
		originalArray = new t[_size];
	}

	~clsDynamicArray()
	{
		delete[] originalArray;
	}

	bool setItem(int index, t value)
	{
		if (index >= _size || index < 0)
			return false;
		originalArray[index] = value;
		return true;
	}

	int size()
	{
		return _size;
	}

	bool isEmpty()
	{
		return _size == 0 ? true : false;
	}

	void printList()
	{
		for (int i = 0; i < _size; i++)
		{
			cout << originalArray[i] << " ";
		}
	}

	void resize(int newSize)
	{
		if (newSize == _size)
		{
			return;
		}

		if (newSize < 0) {
			newSize = 0;
		}

		_tempArray = new t[newSize];

		if (newSize < _size) {
			_size = newSize;
		}

		for (int i = 0; i < _size; i++)
		{
			_tempArray[i] = originalArray[i];
		}

		_size = newSize;
		delete[] originalArray;
		originalArray = _tempArray;
	}

	t getAtim(int index)
	{
		return originalArray[index];
	}

	void clear()
	{
	
		_size = 0;
		_tempArray = new t[_size];
	    delete[] originalArray;
		originalArray = _tempArray;
	}

	
	void reverse()
	{
		//_tempArray = new t[_size];when use it make i<_size 
		for (int i = 0; i < _size/2; i++)//this will save memory and less time 
		{
			//_tempArray[i] = originalArray[_size - 1 - i];
			t temp = originalArray[i];
			originalArray[i] = originalArray[_size - 1 - i];
			originalArray[_size - 1 - i] = temp;
		}

		//delete[] originalArray;
		//originalArray = _tempArray;
	}

	bool  deleteItemAt(int index)
	{
		if (index >= _size || index < 0)
			return false;

		_size--;
		_tempArray = new t [_size];
		for (int i = 0; i < index; i++) 
		{
			_tempArray[i] = originalArray[i];
		}

		for (int i = index + 1; i < _size+1; i++)
		{
			_tempArray[i - 1] = originalArray[i];
		}

		delete[] originalArray;
		originalArray = _tempArray;
		return true;
	}

	void deleteFirstItem()
	{
		deleteItemAt(0);
	}

	void  deleteLastItem()
	{
		deleteItemAt(_size - 1);
	}

	int find(t value)
	{
		
		for (int i = 0; i < _size; i++)
		{
			if (originalArray[i] == value)
			{
				return i;
		    }
		}
		return -1;
	}

	bool deleteItem(t value)
	{
		int index = find(value);
		if (index > -1)
		{
			deleteItemAt(index);
			return true;
		}

		return false;
	}

	bool  insertAt(int index,t value)
	{
		if (index < 0 || index > _size)
			return false;

		_size++;
		_tempArray = new t[_size];
		for (int i = 0; i < index; i++) 
		{
			_tempArray[i] = originalArray[i];
        }
		
		_tempArray[index] = value;
		for (int i = index; i<_size-1; i++)
		{
			_tempArray[i + 1] = originalArray[i];
		}
		 
		delete[] originalArray;
		originalArray = _tempArray;
		return true;
	}

	void insertAtBeginning(t value)
	{
		insertAt(0, value);
	}

	bool  insertBefore(int index, t value)
	{
		if (index < 1) 
		{
		return 	insertAt(0,value);
	    }
		return 	insertAt(index - 1, value);
	}

	bool insertAfter(int index, t value)
	{
		if(index>=_size)
		{
			return 	insertAt(_size , value);
		}
		return 	insertAt(index + 1, value);
	}

	void insertAtEnd(t value)
	{
		insertAt(_size - 1,value);
	}

};

