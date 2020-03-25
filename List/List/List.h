#pragma once
#include <vector>
#include "Point.h"
class List
{
	size_t size;
	struct Node
	{
		Point point;
		Node* next;
		Node(const Point& p) : point(p.x, p.y, p.z), next(nullptr) {}
	};
	Node* first;

	Node* find(const size_t);
	void push(const Point&, const size_t);
	void push(const List&, const size_t);
	void pop(const size_t);

public:
	List();
	List(const List&);

	enum Error
	{
		SUCCESS,
		LIST_EMPTY,
		OUT_OF_BOUNDS
	};
	Error pop_front();
	size_t getSize();
	List operator+(const List&);
	List& operator+=(const List&);
	List& operator=(const List&);
	List operator--(int);

	//Proszê pamiêtaæ, ¿e to nie jest pe³na implementacja, nale¿y kod uzupe³niæ zgodnie z instrukcj¹
};


