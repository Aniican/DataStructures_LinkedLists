#ifndef UNORDERED_H
#define UNORDERED_H
#include "linkedList.h"

template <class T>
class unorderedLinkedList : public linkedList<T>
{
public:
	bool search(const T& searchItem) const;
	void insertFirst(const T& newData);
	void insertLast(const T& newData);
	void deleteNode(const T& deleteItem);
	void divideList(node<T>* first1, node<T>* &first2);
	void mergeSort(int (*func)(T, T));
	void recMergeSort(node<T>* &head, int (*func)(T, T));
	node<T>* mergeList(node<T>* first1, node<T>* first2, int (*func)(T, T));
};

template <class T>
bool unorderedLinkedList<T>::search(const T& searchItem) const
{
	node<T>* current;
	bool found = false;
	current = this->head;
	while (current != nullptr && !found)
	{
		if (current->info == searchItem)
			found = true;
		else
			current = current->link;
	}
	return found;
}

template <class T>
void unorderedLinkedList<T>::insertFirst(const T& newData)
{
	node<T>* newNode;
	newNode = new node<T>;
	newNode->info = newData;
	newNode->link = this->head;
	this->head = newNode;
	this->count++;
	if (this->tail == nullptr)
		this->tail = newNode;
}

template <class T>
void unorderedLinkedList<T>::insertLast(const T& newData)
{
	node<T>* newNode;
	newNode = new node<T>;
	newNode->info = newData;
	if (this->isEmptyList())
	{
		this->head = newNode;
		this->tail = newNode;
		this->count++;
	}
	else
	{
		this->tail->link = newNode;
		this->tail = newNode;
		this->count++;
	}
}

template <class T>
void unorderedLinkedList<T>::deleteNode(const T& deleteItem)
{
	node<T>* current;
	node<T>* trailCurrent;
	bool found;
	if (this->isEmptyList())
	{
		cout << "Cannot delete from an empty list" << endl;
	}
	else
	{
		if (this->head->info == deleteItem)
		{
			current = this->head;
			this->head = this->head->link;
			this->count--;
			if (this->head == nullptr)
				this->tail = nullptr;

			delete current;
		}
		else
		{
			found = false;
			trailCurrent = this->head;
			current = this->head->link;

			while (current != nullptr && !found)
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				else
				{
					found = true;
				}
			}
			if (found)
			{
				trailCurrent->link = current->link;
				this->count--;
				if (this->tail == current)
					this->tail = trailCurrent;
				delete current;
			}
			else
			{
				cout << "The item to be deleted is not in the list." << endl;
			}
		}
	}
}

template <class T>
void unorderedLinkedList<T>::divideList(node<T>* first1, node<T>*& first2)
{
	node<T>* middle;
	node<T>* current;

	if (first1 == nullptr)
		first2 = nullptr;
	else if (first1->link == nullptr)
		first2 = nullptr;
	else
	{
		middle = first1;
		current = first1->link;

		if (current != nullptr)
			current = current->link;

		while (current != nullptr)
		{
			middle = middle->link;
			current = current->link;
			if (current != nullptr)
				current = current->link;
		}

		first2 = middle->link;

		middle->link = nullptr;
	}
}

template <class T>
node<T>* unorderedLinkedList<T>::mergeList(node<T>* first1, node<T>* first2, int (*func)(T, T))
{
	node<T>* lastSmall;
	node<T>* newHead;

	if (first1 == nullptr)
		return first2;
	else if (first2 == nullptr)
		return first1;
	else
	{
		if (func(first1->info, first2->info) == 1)
		{
			newHead = first1;
			first1 = first1->link;
			lastSmall = newHead;
		}
		else
		{
			newHead = first2;
			first2 = first2->link;
			lastSmall = newHead;
		}
		while (first1 != nullptr && first2 != nullptr)
		{
			if (func(first1->info, first2->info) == 1)
			{
				lastSmall->link = first1;
				lastSmall = lastSmall->link;
				first1 = first1->link;
			}
			else
			{
				lastSmall->link = first2;
				lastSmall = lastSmall->link;
				first2 = first2->link;
			}
		}

		if (first1 == nullptr)
			lastSmall->link = first2;
		else
			lastSmall->link = first1;

		return newHead;
	}
}

template <class T>
void unorderedLinkedList<T>::recMergeSort(node<T>* &top, int (*func)(T, T))
{
	node<T>* otherTop;

	if (top != nullptr)
		if (top->link != nullptr)
		{
			divideList(top, otherTop);
			recMergeSort(top, func);
			recMergeSort(otherTop, func);
			top = mergeList(top, otherTop, func);
		}
}

template <class T>
void unorderedLinkedList<T>::mergeSort(int (*func)(T, T)) 
{
	recMergeSort(this->head, func);

	if (this->head == nullptr)
		this->tail = nullptr;
	else
	{
		this->tail = this->head;
		while (this->tail->link != nullptr)
			this->tail = this->tail->link;
	}
}

#endif