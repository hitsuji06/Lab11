#include "MinHeap.hpp"
#include <limits.h>
using namespace std;


void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}


MinHeap::MinHeap(int cap)
{
  currentSize = 0;
  capacity = cap;
  heapArr = new int[capacity];
}

int MinHeap::parent(int index)
{
  return (index-1)/2;
}

int MinHeap::leftChild(int index)
{
  return ((2*index) + 1);
}


int MinHeap::rightChild(int index)
{
  return ((2*index) + 2);
}


int MinHeap::getMin()
{
  return heapArr[0];
}

void MinHeap::heapify(int i)
{
  int l = leftChild(i);
  int r = rightChild(i);
  int smallest = i;
  if ( r<currentSize && heapArr[i]>heapArr[r])
  {
    smallest=r;
  }
  if (l > currentSize && heapArr[i]>heapArr[r])
  {
    smallest=l;
  }  
  if (smallest != i)
  {
    swap(&heapArr[i],&heapArr[smallest]);
    heapify(smallest);
  }
} 

void MinHeap::insertElement(int value)
{
  if(currentSize == capacity)
  {
    cout<<"Maximum heap size reached. Cannot insert anymore"<<endl;
    return;
  }

  currentSize = currentSize + 1;
  int index = currentSize - 1;
  heapArr[index] = value;

  while (index != 0 && heapArr[parent(index)] > heapArr[index])
    {
       swap(&heapArr[index], &heapArr[parent(index)]);
       index = parent(index);
    }
}

void MinHeap::print()
{
  int iter = 0;
  while(iter < currentSize)
  {
    cout<<heapArr[iter]<<" ";
    iter = iter + 1;
  }
  cout<<endl;
}

int MinHeap::extractMin()
{
  if (currentSize <= 0)
  {
    return INT_MAX;
  }
  if (currentSize == 1)
  {
    currentSize--;
    return heapArr[0];
  }else
  {
    int starter=heapArr[0];
    heapArr[0]= heapArr[currentSize-1];
    currentSize=currentSize-1;
    heapify(0);
    return starter;
  }

}
void MinHeap::deleteKey(int i)
{

}