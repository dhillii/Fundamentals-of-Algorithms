#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue(int max)
//Parameterized class constructor
//Post: maxqueue, front, and rear have been initialized
//The array to hold the queue elements has been dynamically allocated
{
	maxqueue = max + 1;
	front = maxqueue - 1;
	rear = maxqueue -1;
	items = new char[maxqueue];
	size = 0;
	
}

Queue::Queue()	//Default class constructor
//Post: maxqueue, front, and rear have been initialized
//The array to hold the queue elements has been dynamically allocated
{
	maxqueue = 501;
	front = maxqueue -1;
	rear = maxqueue -1;
	items = new char[maxqueue];
	size = 0;

	
}

Queue::~Queue()	//Class destructor
{
	delete [] items;
}

void Queue::makeEmpty()
//Post: front and rear have been reset to the empty state
{
	front = maxqueue - 1;
	rear = maxqueue - 1;
	size = 0;
	
}

bool Queue::isEmpty() const
//Returns true if the queue is empty, otherwise false
{
	return (rear == front);
}

bool Queue::isFull() const
//Returns true if the queue is full, otherwise false
{
	return ((rear + 1) % maxqueue == front);
}

void Queue::enqueue(char item)
//Post: If (queue is not full) item is at the rear of the queue;
//otherwise, a FullQueue exception is thrown.
{
	if(isFull())
		throw FullQueue();
	else
	{
		rear = (rear+1) % maxqueue;
		items[rear] = item;
		size += 1;
	}

}

void Queue::dequeue(char& item)
//Post: If (queue is not empty) the front of the queue has been removed
//and a copy returned in item; otherwise, an EmptyQueue is thrown.
{
	if(isEmpty())
		throw EmptyQueue();
	else
	{
		front = (front + 1) % maxqueue;
		item = items[front];
		size -= 1;
	}
	
}

void Queue::printqueue()
{
	if(isEmpty())
		cout << " The Queue is empty..." << endl;

	if(isFull())
		cout << " The Queue is full..." << endl;

	else
	{
		cout << " [";

		for(int i = 0; i < size; i++)
		{
			cout << items[(size-1)-i] << ", ";
		}

		cout << "] " << endl;


	}
}
		