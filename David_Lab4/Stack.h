#ifndef _STACK_H
#define _STACK_H
#include <iostream>

using namespace std;

template <class T>
struct node
{
	T data;
	node<T> * next;
};

template <typename T>
class Stack
{
public:
	Stack();
	~Stack();
	bool isFull() const;
	bool isEmpty() const;
	void Push(T item);
	void Pop(T &item);
	node<T> Top();
	void printstack();
	node<T> * getTop();
	int getSize();
	
private:
	node<T> * top_ptr;
	int size;

	
};

#endif