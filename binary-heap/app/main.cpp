#include "BinaryHeap.h"

int main()
{
  int node = 0;
  CBinaryHeap<int> heap;
  heap.Insert(7);
  heap.Insert(4);
  heap.Insert(6);
  heap.Insert(3);
  heap.Insert(5);
  heap.Insert(1);
  heap.Insert(2);
  heap.DumpHeap();
  for (int i = 0; i < 8; i++)
  {
    heap.DeleteMin(node);
    cout << "Mini node: " << node << "\n" ;
    heap.DumpHeap();
  }
  return 0;
}