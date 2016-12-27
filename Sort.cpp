#include "Sort.h"
#include <utility>
#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>
#include "Random.h"

//insertion
//selection
//merge
//quick
//binary search
//Distb'n sort
using std::cout;
using std::endl;
void Sort::insertionSort()
{
	for(int i=1;i<numberOfElements;i++)
	{
		int j=i;
			while(j>0&&arr[j]<arr[j-1])
			{
				std::swap(arr[j],arr[j-1]);
				--j;
			}
	}
}
void Sort::selectionSort()
{
	for(int i=0;i<numberOfElements;i++)
	{
		int min=i;
		for(int j=i+1;j<numberOfElements;j++)
		{
			if(arr[min]>arr[j])
				min = j;
		}
		std::swap(arr[min],arr[i]);
	}
}
void Sort::mergeSort(int low,int high)
{
	int middle = floor((low+high)/2);
	if(low<high)
	{
		mergeSort(low,middle);
		mergeSort(middle+1,high);
		merge(low,middle,high);

	}
}

void Sort::merge(int low,int middle,int high)
{
	 int leftArraySize = middle-low+1;
	 int rightArraySize = high-middle;
	 int leftArr[leftArraySize+1];
	 int rightArr[rightArraySize+1];
	 
	 for(int i=0;i<leftArraySize;i++)
	 		leftArr[i]=arr[low+i];

	 for(int j=0;j<rightArraySize;j++)
	 		rightArr[j]=arr[j+middle+1];
	 
	 leftArr[leftArraySize] = INT_MAX;
	 rightArr[rightArraySize] = INT_MAX;

	 for(int i=0,j=0,k=low;k<=high;k++)
	 {		
	 		if(leftArr[i]<=rightArr[j])
	 		{
	 			arr[k] = leftArr[i];
	 			++i;
	 		}else{
	 			arr[k] = rightArr[j];
	 			++j;
	 		}
	 }
}

void Sort::populate()
{
	for(int i=0;i<numberOfElements;i++)
			arr[i] = getRandom(1,MAX_SIZE);
}
void Sort::print()
{
	for(int i=0;i<numberOfElements;i++)
		std::cout<<arr[i]<<",";
}
void Sort::quickSort(int low,int high)
{
	if(low<high)
	{
		int q = partition(low,high);
		quickSort(low,q-1);
		quickSort(q+1,high);
	}
}
int Sort::partition(int low,int high)
{
  int i=low-1;
  int x = arr[high];
  for(int j=low;j<high;j++)
  	{
  		if(arr[j]<=x)
  		{
  			++i;
  			std::swap(arr[i],arr[j]);
  		}	
  	}
  	++i;
  	std::swap(arr[i],arr[high]);
  	return i;
}

int Sort::binarySearch(int low,int high,int value)
{
	if(low>high)
	{
			return -1;
	}
	int middle = (low+high)/2;
	
	if(arr[middle]==value)
				return arr[middle];
	
	if(arr[middle]>value)
				return binarySearch(low,middle-1,value);
	else
				return binarySearch(middle+1,high,value);
}
