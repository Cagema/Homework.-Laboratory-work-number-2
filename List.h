#pragma once
#include "pch.h"
#include <stdio.h>
#include <iostream> 
using namespace std;

template<typename T>
class Node
{
public:
	Node * pNext;
	T data;

	Node(T data = T(), Node *pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}
};

template<typename T>
class List
{
public:
	List();
	~List();

	void pop_front();
	void pop_back();
	void push_back(T data);
	void push_front(T data);
	void insert(T data, size_t index);
	T at(size_t index);
	void remove(size_t index);
	int getSize() { return size; }
	void clear();
	void set(T data, size_t index);
	bool isEmpty() { return ((size == 0) && (head == nullptr)); }
	template <typename T1> friend  std::ostream& operator<< (std::ostream &out, List<T1> );

	Node<T> *head;

private:
	int size = 0;
	
};

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;

	head = head->pNext;

	delete temp;

	size--;

}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	size++;
}

template<typename T>
void List<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void List<T>::insert(T data, size_t index)
{
	//if (index < 0) throw std::invalid_argument("Index must be >= 0");
	if (index >= size) throw std::invalid_argument("Index is larger than size of list");

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T> *previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T> *newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

		size++;
	}
}

template<typename T>
inline T List<T>::at(size_t index)
{
	//if (index < 0) throw std::invalid_argument("Index must be >= 0");
	if (index >= size) throw std::invalid_argument("Index is larger than size of list");

	int counter = 0;

	Node<T> *current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
inline void List<T>::set(T data, size_t index)
{
	//if (index < 0) throw std::invalid_argument("Index must be >= 0");
	if (index >= size) throw std::invalid_argument("Index is larger than size of list");

	int counter = 0;

	Node<T> *current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			current->data = data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::remove(size_t index)
{
	//if (index < 0) throw std::invalid_argument("Index must be >= 0");
	if (index >= size) throw std::invalid_argument("Index is larger than size of list");

	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<T> *toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		size--;
	}

}

template<typename T>
void List<T>::pop_back()
{
	remove(size - 1);
}

template<typename T>
inline std::ostream & operator<<(std::ostream & out, List<T> list)
{

	for (int i = 0; i < list.getSize(); i++) {
		std::cout << "\n" << i << " element is {" << list.at(i) << "}";
	}
	return out;
}

