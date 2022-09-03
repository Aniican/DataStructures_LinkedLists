#ifndef ITERATOR_H
#define ITERATOR_H

template <class T>
struct node
{
	T info;
	node<T>* link;

};

template <class T>
class linkedListIterator
{
public:
	linkedListIterator();
	linkedListIterator(node<T>* ptr);
	T operator*();
	linkedListIterator<T> operator++();
	bool operator==(const linkedListIterator<T>& right) const;
	bool operator!=(const linkedListIterator<T>& right) const;
private:
	node<T>* current;
};


template <class T>
linkedListIterator<T>::linkedListIterator()
{
	current = nullptr;
}

template<class T>
linkedListIterator<T>::linkedListIterator(node<T>* ptr)
{
	current = ptr;
}

template <class T>
T linkedListIterator<T>::operator*()
{
	return current->info;
}


template <class T>
linkedListIterator<T> linkedListIterator<T>::operator++()
{
	current = current->link;
	return *this;
}

template <class T>
bool linkedListIterator<T>::operator==(const linkedListIterator<T>& right) const
{
	return (current == right.current);
}

template <class T>
bool linkedListIterator<T>::operator!=(const linkedListIterator<T>& right) const
{
	return (current != right.current);
}

#endif