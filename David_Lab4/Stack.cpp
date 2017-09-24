#include "Stack.h"
#include <iostream>

using namespace std;

template <typename T>
void Stack<T>::Push(T item)
//Adds new item to the top of the stack
//Stack is bounded by size of memory
//Pre: Stack is initialized
//Post: If stack is full, print message, else, new item is placed at top of stack.
{	
	if(isFull())
	{
		cout << "The Stack is full..." << endl;
	}
	else
	{
	node<T> * loc;
	loc = new node<T>;
	loc->data = item;
	loc->next = top_ptr;
	top_ptr = loc;
	size++;
	}
}

template <typename T>
void Stack<T>::Pop(T &item)
//Removes top item from stack
//Pre: Stack is initialized
//Post: If stack is empty, prints message. Otherwise, delete top node and decrement size.
{	if(isEmpty())
	{
		cout << "The Stack is empty..."<< endl;
	}
	node<T> * temp;
	temp = top_ptr;
	top_ptr = top_ptr->next;
	item = temp->data;
	delete temp;
	size--;
}

template <typename T>
Stack<T>::Stack()	//Class constructor
{
	top_ptr = NULL;
	size = 0;
}

template <typename T>
Stack<T>::~Stack()	//Class destructor
{
	node<T> * temp;
	
	while(top_ptr != NULL)	//loop through stack and delete each node
	{
		temp = top_ptr;
		top_ptr = top_ptr->next;
		delete temp;
	}
}


template <typename T>
bool Stack<T>::isEmpty()	const
// returns true if there are no elemets in the stack, otherwise false.
{
	return(top_ptr == NULL);
}

template <typename T>
bool Stack<T>::isFull()	const
//Returns true if there is no more room for another item on the free store, otherwise false
{
	node<T> * loc;
	try
	{
		loc = new node<T>;		// try to create and delete node
		delete loc;
		return false;
	}
	catch(std::bad_alloc exception)		//if error, return true
	{
		return true;
	}
}

template <typename T>
void Stack<T>::printstack()
//If stack is empty, print message, else, print stack contents.
{
	if(isEmpty())
		cout << " The Stack is empty..." <<endl;
	
	
	node<T> * topcpy = top_ptr;
	
	while(topcpy != NULL)
	{
		cout << " |"<<topcpy->data << "|" << endl << " ----" <<endl;
		topcpy = topcpy->next;
	}
}

template <typename T>
node<T> * Stack<T>::getTop()
{
	return(top_ptr);
}

template <typename T>
int Stack<T>::getSize()
{
	return size;
}