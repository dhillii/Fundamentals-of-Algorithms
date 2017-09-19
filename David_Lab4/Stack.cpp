#include "Stack.h"
#include <iostream>

using namespace std;


void Stack::Push(char item)
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
	node * loc;
	loc = new node;
	loc->data = item;
	loc->next = top_ptr;
	top_ptr = loc;
	size++;
	}
}


void Stack::Pop(char &item)
//Removes top item from stack
//Pre: Stack is initialized
//Post: If stack is empty, prints message. Otherwise, delete top node and decrement size.
{	if(isEmpty())
	{
		cout << "The Stack is empty..."<< endl;
	}
	node * temp;
	temp = top_ptr;
	top_ptr = top_ptr->next;
	item = temp->data;
	delete temp;
	size--;
}

Stack::Stack()	//Class constructor
{
	top_ptr = NULL;
	size = 0;
}


Stack::~Stack()	//Class destructor
{
	node * temp;
	
	while(top_ptr != NULL)	//loop through stack and delete each node
	{
		temp = top_ptr;
		top_ptr = top_ptr->next;
		delete temp;
	}
}



bool Stack::isEmpty()	const
// returns true if there are no elemets in the stack, otherwise false.
{
	return(top_ptr == NULL);
}


bool Stack::isFull()	const
//Returns true if there is no more room for another item on the free store, otherwise false
{
	node * loc;
	try
	{
		loc = new node;		// try to create and delete node
		delete loc;
		return false;
	}
	catch(std::bad_alloc exception)		//if error, return true
	{
		return true;
	}
}

void Stack::printstack()
//If stack is empty, print message, else, print stack contents.
{
	if(isEmpty())
		cout << " The Stack is empty..." <<endl;
	
	
	node * topcpy = top_ptr;
	
	while(topcpy != NULL)
	{
		cout << " |"<<topcpy->data << "|" << endl << " ----" <<endl;
		topcpy = topcpy->next;
	}
}

node * Stack::getTop()
{
	return(top_ptr);
}

int Stack::getSize()
{
	return size;
}













































