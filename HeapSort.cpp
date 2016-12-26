#include <iostream>
#include <cmath>
#include <utility>
#include "HeapSort.h"
using std::cout;
using std::endl;

void Heap::print()
{

	for(int i=1,height=0;i<=numberOfElements;i++)
	{
		if(static_cast<int>(log2(i))==height)
		{
			 cout<<endl;
			 ++height;
		}
		cout<<arr[i]<<"\t";

	}
}
int Heap::parent(int value)
{
	if(value<= 1)
		return -1;
	return floor((value)/2);
}
int Heap::child(int value)
{
	return 2*value;
}
void Heap::maxHeapify(int index)
{
	int left = child(index);
	int right = child(index)+1;
	int largest;
	
	if(left<= numberOfElements && arr[left]>arr[index])
		largest = left;
	else
		largest = index;

	if(right<=numberOfElements && arr[right]>arr[largest])
		largest = right;
	
	if(largest	!= index)
		{
			std::swap(arr[largest],arr[index]);
			maxHeapify(largest);
		}
}

void Heap::buildHeap()
{
	for(int largestNode = floor(numberOfElements/2);largestNode>0;--largestNode)
	{
		maxHeapify(largestNode);
	}
}

int Heap::extractMax()
{
	if(numberOfElements<1)
	{
		return -1;
	}
	int max = arr[1];
	arr[1]= arr[numberOfElements];
	--numberOfElements;
	maxHeapify(1);
	return max;
}
void Heap::insert(int value)
{
	numberOfElements += 1;
	arr[numberOfElements] = value;
	int index = numberOfElements;
	while( index>1 && arr[index]>arr[parent(index)])
	{
		std::swap(arr[index],arr[parent(index)]);
		index = parent(index);
	}
}