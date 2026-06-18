#pragma once
#include<iostream>
using namespace std;
template<class t>
class clsDblLinkedList
{
private:
int	_size = 0;
public:
	class node 
	{
	public:
		t value;
		node* prev ;
		node* next;
	};

	node* head = nullptr;

	 void insertAtTheBeginning(t value)
	{
		node* newNode = new node();
		newNode->value = value;
		newNode->prev = nullptr;
		newNode->next = head;

		if (head != nullptr)
		{
			head->prev = newNode;
		}
		head = newNode;
		_size++;
	}

	 void printList()
	{
		cout << "Null <-->";
		node* current = head;
		while (current != nullptr)
		{
			cout << current->value << "<-->";
			current = current->next;
		}
		cout << "Null" << endl;
	}   

	 node* find( t value)
	{
		node* current = head;
		while (current  != nullptr)
		{
			if (current->value == value)
			{
				return current;
			}
			current = current->next;
		}
		return nullptr;
	}

	 void insertAfter(node* current, t value)
	{
		node* newNode = new node();
		newNode->value = value;
		newNode->prev = current;
		newNode->next = current->next;

		if (current->next != nullptr)
		{
			current->next->prev = newNode;
		}
		current->next = newNode;
		_size++;

	}

	 bool insertAfter(int index, t value)
	 {
		 node* current = getNode(index);
		 if (current == nullptr) {
			 return false;
		 }
		 insertAfter(current, value);
		 return true;
	 }

	 void insertAtEnd( t value)
	{
		node* newNode = new node();
		newNode->value = value;
		newNode->next = nullptr;
		newNode->prev = nullptr;

		if (head == nullptr) {
			head = newNode;
			return;
		}
		node* current = head;

		while (current->next != nullptr)
		{
			current = current->next;
		}

		newNode->prev = current;
		current->next = newNode;
		_size++;

	}

	 void deleteNode(node*& toBeDeleted)
	{
		if (head == nullptr || toBeDeleted == nullptr) {
			return;
		}

		if (head == toBeDeleted) {
			head = toBeDeleted->next;
		}

		if (toBeDeleted->next != nullptr) {
			toBeDeleted->next->prev = toBeDeleted->prev;
		}

		if (toBeDeleted->prev != nullptr) {
			toBeDeleted->prev->next = toBeDeleted->next;
		}
		delete toBeDeleted;
		-size--;
	}

	 void deleteFirstNode()
	{
		if (head == nullptr) {
			return;
		}

		node* temp = head;
		head = head->next;
		if (head != nullptr) {
			head->prev = nullptr;
		}
		delete temp;
		_size--;

	}

	 void deleteLastNode()
	{
		 if (head == nullptr) {
			 return;
		 }
		 _size--;
		 if (head->next == nullptr) {
			 delete head;
			 head = nullptr;
			 return;
		 }
		node* current = head;

		while (current->next != nullptr) 
		{
			current = current->next;
		}

		node* temp = current->next;
		current->next = nullptr;
		delete temp;

	}

	 int size() 
	 {
		 return _size;
	 }

	 bool isEmpty() 
	 {
		 return (-size == 0 ? true : false);
	 }

	 void clear()
	 {
		 while (_size > 0)
		 {
			 deleteFirstNode();
		 }
	 }

	 void reverse()
	 {
		 node* current = head;
		 node* temp = nullptr;
		 while (current != nullptr)
		 {
			 temp = current->prev;
			 current->prev = current->next;
			 current->next = temp;
			 current = current->prev;
		 }

		 if (temp != nullptr)
		 {
			 head = temp->prev;
		 }
	 }

	 node* getNode(int index)
	 {
		 if (index > _size - 1 || index < 0)
		 {
			 return nullptr;
		 }
		 node* current = head;
		 int count = 0;
		 while (current != nullptr)
		 {
			
			 if (count == index) {
				 break;
			 }
			 current = current->next;
			 count++;
		 }
		 return current;
	 }

	 t getItem(int index) 
	 {
		 node * N= getNode(index);
		 if (N == nullptr)
			 return nullptr;
		 else
			 return N->value;
	 }

	 bool  updateItem(int index, t newValue)
	 {
		 node* itemNode = getNode(index);
		 if (itemNode != nullptr) {
			 itemNode->value = newValue;
			 return true;
		 }
		 return false;
	 }
};
