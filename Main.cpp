#include <iostream>
#include <cstdlib>
#include "Random.h"
#include "Heapsort.h"
using std::cout;
using std::endl;
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	//first time calling rand() doesn't produce a actual random value,so just running it once.
	rand();
	
	Heap obj(0);
	for(int i=1;i<=10;i++)
	{
		obj.insert(getRandom(1,100));
	}
	obj.print();



	
		
}