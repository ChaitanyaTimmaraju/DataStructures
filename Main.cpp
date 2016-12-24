#include <iostream>
#include "Stack.h"

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	//first time calling rand() doesn't produce a actual random value,so just running it once.
	rand();
	Stack obj;
	obj.populate(10);
	for(int i=0;i<=10;i++)
	{
		obj.print();
		obj.pop();
	}	
}