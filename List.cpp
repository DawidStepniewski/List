#include "List.h"



List::Node* List::find(const size_t idx)
{
	Node* node = first;

	for (size_t i = 0; i < idx; i++)
	{
		node = node->next;
	}

	return node;
}

void List::push(const Point& point, const size_t idx)
{
	if (idx == 0)
	{
		Node* tail = first;
		first = new Node(point);
		first->next = tail;
	}
	else
	{
		Node* prev = find(idx - 1);
		Node* tail = prev->next;
		prev->next = new Node(point);
		prev->next->next = tail;
	}
	size++;
}

void List::push(const List& list, const size_t idx)
{
	List copy(list);
	Node* it = copy.first;
	if (idx == 0)
	{
		Node* tail = first;
		Node* last = nullptr;
		if (it)
		{
			first = new Node(it->point);
			last = first;
			it = it->next;
		}
		while (it)
		{
			last->next = new Node(it->point);
			last = last->next;
			it = it->next;
		}
		last->next = tail;
	}
	else
	{
		Node* prev = find(idx - 1);
		Node* tail = prev->next;
		while (it)
		{
			prev->next = new Node(it->point);
			prev = prev->next;
			it = it->next;
		}
		prev->next = tail;
	}
	size += list.size;
}

void List::pop(const size_t idx)
{
	if (idx == 0)
	{
		Node* tail = first->next;
		delete first;
		first = tail;
	}
	else
	{
		Node* prev = find(idx - 1);
		Node* tail = prev->next->next;
		delete prev->next;
		prev->next = tail;
	}
	size--;
}

void List::multiply(const int skalar)
{
	if (skalar == 0) 
	{
		this->~List();
		return;
	}
		

	else
	{
		List* pom = new List();
		*pom = *this;
		for (size_t i = 0; i < skalar - 1; i++)
		{
			this->push(*pom, this->size);
		}
	}
	
}

List::List() : size(0), first(nullptr) {}

List::~List()
{
	while (size > 0)
		pop_front();
}

List::List(const List& list) : size(list.size), first(nullptr)
{
	Node* it = list.first;
	Node* last = first;
	if (it)
	{
		first = new Node(it->point);
		last = first;
		it = it->next;
	}
	while (it)
	{
		last->next = new Node(it->point);
		last = last->next;
		it = it->next;
	}
}

List::Error List::pop_front()
{
	List::Error error = List::Error::SUCCESS;

	if (size == 0)
	{
		error = List::Error::LIST_EMPTY;
	}
	else
	{
		pop(0);
	}

	return error;
}

List::Error List::pop_back()
{
	List::Error error = List::Error::SUCCESS;

	if (size == 0)
	{
		error = List::Error::LIST_EMPTY;
	}
	else
	{
		pop(size - 1);
	}

	return error;
}

List::Error List::insert(const Point& point, const size_t idx)
{
	List::Error error = List::Error::SUCCESS;

	if (idx > size)
	{
		error = List::Error::OUT_OF_BOUNDS;
	}
	
	push(point, idx);
	
	return error;
}

List::Error List::find(Point& out, const size_t idx)
{
	List::Error error = List::Error::SUCCESS;

	if (idx >= size)
	{
		error = List::Error::OUT_OF_BOUNDS;
	}

	else if (size == 0)
	{
		error = List::Error::LIST_EMPTY;
	}

	out = find(idx)->point;
	return error;
}

List::Error List::push_back(const Point& point)
{
	List::Error error = List::Error::SUCCESS;

	push(point, size);

	return error;
}



size_t List::getSize()
{
	return size;
}

List List::operator+(const List& list)
{
	List copy(*this);
	copy.push(list, copy.size);
	return copy;
}

List& List::operator+=(const List& list)
{
	push(list, size);
	return *this;
}

List& List::operator=(const List& list)
{
	List copy(list);
	this->~List();
	push(copy, 0);
	return *this;
}

List List::operator--(int)
{
	List copy(*this);
	pop_back();
	return copy;
}

List List::operator*(const unsigned int skalar)
{
	List copy(*this);
	copy.multiply(skalar);
	return copy;

}
List& List::operator++(int)
{
	List* pom = new List(*this);
	this->~List();
	return *pom;
}

Point& List::operator[] (size_t idx)
{
	Node* pom = find(idx);
	return pom->point;
}

std::ostream& operator<<(std::ostream& os, const List& inputList)
{
	List::Node* pom = inputList.first;
	for (size_t i = 0; i < inputList.size; i++)
	{
		os << "x: " << pom->point.x << '\t' << "y: " << pom->point.y << '\t' << "z: " << pom->point.z << std::endl;
		pom = pom->next;
	}
	return os;
}

