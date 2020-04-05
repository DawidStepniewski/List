#pragma once
#include <vector>
#include <iostream>
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
	void multiply(const int);

public:
	List();
	List(const List&);
	~List();

	enum Error
	{
		SUCCESS,
		LIST_EMPTY,
		OUT_OF_BOUNDS
	};
	Error pop_front();
	Error pop_back();
	Error push_back(const Point&);
	Error find(Point&, const size_t);
	Error insert(const Point&, const size_t);
	size_t getSize();
	List operator+(const List&);
	List& operator+=(const List&);
	List& operator=(const List&);
	List operator--(int);
	List operator*(const unsigned int);
	List& operator++(int);
	Point& operator[](const size_t);
	friend std::ostream& operator <<(std::ostream&, const List&);

	//Proszê pamiêtaæ, ¿e to nie jest pe³na implementacja, nale¿y kod uzupe³niæ zgodnie z instrukcj¹
};
std::ostream& operator <<(std::ostream&, const List&);

