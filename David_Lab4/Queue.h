#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>


using namespace std;

class FullQueue
{};

class EmptyQueue
{};




class Queue
{
	
	public:
		Queue(int max);
		Queue();		//constructor
		~Queue();		//destructor
		void makeEmpty();
		bool isEmpty() const;
		bool isFull() const;
		void enqueue(char item);
		void dequeue(char& item);
		void printqueue();
		
	private:
		int front;
		int rear;
		char * items;
		int maxqueue;
		int size;
};


#endif
