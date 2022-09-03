#ifndef LINKED_H
#define LINKED_H

#include "linkedListIterator.h"
#include <iostream>

using namespace std;

template <class T>
class linkedList
{
public:
	void initializeList();
	const linkedList<T>& operator=(const linkedList<T>& otherList);
	bool isEmptyList() const;
	void print() const;
	int length() const;
	void destroyList();
	T front() const;
	T back() const;
	virtual bool search(const T& searchItem) const = 0;
	virtual void insertFirst(const T& newData) = 0;
	virtual void insertLast(const T& newData) = 0;
	virtual void deleteNode(const T& deleteItem) = 0;
	linkedListIterator<T> begin();
	linkedListIterator<T> end();
	linkedList();
	linkedList(const linkedList<T>& otherList);
	~linkedList();
//protected:
	int count;
	node<T>* head;
	node<T>* tail;
private:
	void copyList(const linkedList<T>& otherList);
};

template <class T>
bool linkedList<T>::isEmptyList() const
{
	return (head == nullptr);
}

template <class T>
linkedList<T>::linkedList()
{
	head = nullptr;
	tail = nullptr;
	count = 0;
}

template <class T>
void linkedList<T>::destroyList()
{
	node<T>* temp;
	while (head != nullptr)
	{
		temp = head;
		head = head->link;
		delete temp;
	}
	tail = nullptr;
	count = 0;
}

template <class T>
void linkedList<T>::initializeList()
{
	destroyList();
}

template <class T>
void linkedList<T>::print() const
{
	node<T>* current;
	current = head;
	while (current != nullptr)
	{
		cout << current->info << endl;
		current = current->link;
	}
}

template <class T>
int linkedList<T>::length() const
{
	return count;
}

template <class T>
T linkedList<T>::front() const
{
	if (isEmptyList())
		throw 1;
	return head->info;
}

template <class T>
T linkedList<T>::back() const
{
	if (isEmptyList())
		throw 1;
	return tail->info;
}

template <class T>
linkedListIterator<T> linkedList<T>::begin()
{
	linkedListIterator<T> temp(head);
	return temp;
}

template <class T>
linkedListIterator<T> linkedList<T>::end()
{
	linkedListIterator<T> temp(tail);
	return temp;
}

template <class T>
void linkedList<T>::copyList(const linkedList<T>& otherList)
{
	node<T>* newNode;
	node<T>* current;

	if (!isEmptyList())
		destroyList();

	if (otherList.isEmptyList())
	{
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	else
	{
		current = otherList.head;
		count = otherList.count;
		head = new node<T>;
		head->info = current->info;
		head->link = nullptr;

		tail = head;
		current = current->link;
		while (current != nullptr)
		{
			newNode = new node<T>;
			newNode->info = current->info;
			newNode->link = nullptr;
			tail->link = newNode;
			tail = newNode;
			current = current->link;
		}
	}
}

template <class T>
linkedList<T>::linkedList(const linkedList<T>& otherList)
{
	head = nullptr;
	copyList(otherList);
}

template <class T>
const linkedList<T>& linkedList<T>::operator=(const linkedList<T>& otherList)
{
	if (this != &otherList)
	{
		copyList(otherList);
	}
	return *this;
}

template <class T>
linkedList<T>::~linkedList()
{
	destroyList();
}

#endif