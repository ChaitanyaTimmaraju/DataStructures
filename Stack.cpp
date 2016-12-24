#include "Stack.h"

Stack::Stack(): LinkedList()
{

}

void Stack::push(int value)
{
	insert(value);
}
void Stack::print()
{
	LinkedList::print(getHead());
}
void Stack::pop()
{
	if(getHead())
	{
		deleteElement( getHead()->data);
	}
   
}
