#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"
class Stack: public LinkedList
{
public:
	 Stack();
	 void push(int value);
	 void pop();
	 void print();
};
#endif