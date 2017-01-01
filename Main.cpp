#include <iostream>
#include <cstdlib>
#include "BFSApplications.h"
using std::cout;
using std::endl;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	//first time calling rand() doesn't produce a actual random value,so just running it once.
	rand();
	BFSApplications obj(false,false);
	obj.readGraph("GraphFile.txt");
	obj.twoColor();

	
}