#ifndef _STACK_H
#define _STACK_H
#include <iostream>

using namespace std;


struct node
{
	char data;
	node * next;
};


class Stack
{
public:
	Stack();
	~Stack();
	bool isFull() const;
	bool isEmpty() const;
	void Push(char);
	void Pop(char &item);
	node Top();
	void printstack();
	node * getTop();
	int getSize();
	
private:
	node * top_ptr;
	int size;

	
};

#endif