#ifndef SORT_H
#define SORT_H
class Sort
{
	private:
		static const int MAX_SIZE = 256;
		int arr[MAX_SIZE];
		int numberOfElements;
	public:
		Sort(int n)
		{
			numberOfElements = n;
		}
		Sort():arr{12,7,8,200,1,4,5,9}
		{
			numberOfElements=8;
		}
		int binarySearch(int low,int high,int value);
		void quickSort(int low,int high);
		int partition(int low,int high);
		void mergeSort(int low,int high);
		int getElements(){return numberOfElements;}
		void merge(int low,int middle,int high);
		void populate();
		void print();
		void insertionSort();
		void selectionSort();
};
#endif