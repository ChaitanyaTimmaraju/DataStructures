#ifndef HEAP_SORT_H
#define HEAP_SORT_H


class Heap
{
public:
		static const int MAX_QUEUE_SIZE = 256;
		int extractMax();
		void insert(int value);
		void maxHeapify(int index);
		void buildHeap();
		int parent(int index);
		int child(int index);
		Heap(int numberOfElements)
		{
			this->numberOfElements = numberOfElements;
		
		}
		void print();
private:
	   	int arr[MAX_QUEUE_SIZE+1];
	   	int numberOfElements;
};

#endif