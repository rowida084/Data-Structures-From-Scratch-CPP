#pragma once
#include<iostream>
#include"clsMyQueue.h"
#include"clsDblLinkedList.h"

template<class t>
class clsMyStack : public clsMyQueue<t> 
{
public:
	void push(t value)
	{
		clsMyQueue<t> ::_myList.insertAtTheBeginning(value);
	}

	t top()
	{
		return clsMyQueue<t> ::front();
	 }

	t bottom()
	{
		return clsMyQueue<t> ::back();
	}
};

