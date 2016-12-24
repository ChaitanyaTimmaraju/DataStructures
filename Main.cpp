#include <iostream>
#include "BST.h"
#include "Random.h"
#include <cstdlib>
using std::cout;
using std::endl;
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	//first time calling rand() doesn't produce a actual random value,so just running it once.
	rand();
	BST obj;
	for(int i=0;i<10;i++)
	{	
		int rand = getRandom(1,100);
		obj.insert(&obj.head,rand,obj.head);

	}
	obj.traverse(obj.head);
	cout<<"calling minimum:"<<(obj.findMinimum(obj.head))->data;
	

	
		
}